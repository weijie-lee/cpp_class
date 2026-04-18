"""
Markdown transformation utilities for print-friendly conversion.

Responsibilities:
  - Strip emoji and decorative Unicode for black-and-white printing.
  - Split a lesson's 教案.md into the canonical 9 sections.
  - Shrink long "老师说" narrative blocks.
  - Extract Expected Output blocks from *.cpp example files.
  - Build HTML fragments for student info header and answer areas.
"""

from __future__ import annotations

import re
from pathlib import Path

# ---------------------------------------------------------------------------
# Emoji / decorative Unicode stripping
# ---------------------------------------------------------------------------

# Common decorative characters that appear in the lesson plans.
_DECORATIVE_CHARS = set("✅❌✔✘⭐★☆🎯📌📍📝📖📚📊📁📄📋🎉🎓🎈🏆🏅🔑🔍🔎🔧🔨"
                        "💡💻💪👍👎🤔😊😄🙂☺😂😭😎🙏🎁🌟✨💯🔥❓❗‼⚠"
                        "⬆⬇⬅➡↑↓←→⏰⌚🕐🕑🕒🕓🎬🎮🎭🎨🎲🎵🎶"
                        "📣📢📯🔔🔕🔗🔒🔓🔐🌈🌞🌙🌺🌸🍎🍏🍊🍋🍌"
                        "🐱🐶🐰🐯🦁🐻🐼🐨🐸🐵🙈🙉🙊💝💖💕❤♥♡")

# Unicode ranges covering emoji / pictographs / symbols.
_EMOJI_RANGES = [
    (0x1F300, 0x1F9FF),   # symbols & pictographs
    (0x1FA00, 0x1FAFF),   # extended symbols & pictographs
    (0x2600, 0x27BF),     # misc symbols + dingbats
    (0x2B00, 0x2BFF),     # misc symbols and arrows
    (0x1F1E6, 0x1F1FF),   # regional indicators (flags)
]

# Variation selectors / zero-width joiners that follow emoji.
_EMOJI_MODIFIERS = {0xFE0F, 0xFE0E, 0x200D}


def _is_emoji_codepoint(cp: int) -> bool:
    if cp in _EMOJI_MODIFIERS:
        return True
    for start, end in _EMOJI_RANGES:
        if start <= cp <= end:
            return True
    return False


def strip_emoji(text: str) -> str:
    """Remove emoji and most decorative characters, keeping Chinese/ASCII text."""
    out = []
    for ch in text:
        if ch in _DECORATIVE_CHARS:
            continue
        if _is_emoji_codepoint(ord(ch)):
            continue
        out.append(ch)
    # Collapse runs of spaces that decorative removal may have left behind.
    result = "".join(out)
    result = re.sub(r"[ \t]{2,}", " ", result)
    # Collapse triple-plus blank lines into a pair.
    result = re.sub(r"\n{3,}", "\n\n", result)
    return result


# ---------------------------------------------------------------------------
# Section splitting
# ---------------------------------------------------------------------------

# Chinese-numeral section headings used consistently across all 教案.md:
#   ## 一、课程信息
#   ## 二、教学重点与难点
#   ## 三、课堂时间分配
#   ## 四、讲稿提纲
#   ## 五、课堂例题
#   ## 六、课堂练习题
#   ## 七、常见错误与应对
#   ## 八、课后作业
#   ## 九、下节课预告
_SECTION_RE = re.compile(
    r"^##\s+(?P<num>[一二三四五六七八九十]+)、(?P<title>.+?)\s*$",
    re.MULTILINE,
)

_CHINESE_NUM = {"一": 1, "二": 2, "三": 3, "四": 4, "五": 5,
                "六": 6, "七": 7, "八": 8, "九": 9, "十": 10}


def split_sections(md_text: str) -> dict[int, dict]:
    """
    Return a dict keyed by section number (1..9) with:
        {"title": str, "body": str, "start": int, "end": int}

    `body` includes the `## ...` heading itself so each slice is self-contained.
    """
    matches = list(_SECTION_RE.finditer(md_text))
    sections: dict[int, dict] = {}
    for i, m in enumerate(matches):
        num = _CHINESE_NUM.get(m.group("num"))
        if num is None:
            continue
        start = m.start()
        end = matches[i + 1].start() if i + 1 < len(matches) else len(md_text)
        sections[num] = {
            "title": m.group("title").strip(),
            "body": md_text[start:end].rstrip() + "\n",
            "start": start,
            "end": end,
        }
    return sections


def extract_preamble(md_text: str) -> str:
    """Return text before the first `## 一、` heading (title + frontmatter)."""
    m = _SECTION_RE.search(md_text)
    return md_text[: m.start()] if m else md_text


# ---------------------------------------------------------------------------
# Dialogue shrinking
# ---------------------------------------------------------------------------

_TEACHER_TAG_RE = re.compile(r"^\s*>\s*\*\*老师说：\*\*\s*$", re.MULTILINE)


def shrink_teacher_dialogue(md_text: str, max_quote_lines: int = 4) -> str:
    """
    Trim `> **老师说：**` blockquote bodies to the first few non-empty quote
    lines. Long in-class dialogue is interesting on screen but eats paper
    when printed — we keep just the lead-in sentence(s).
    """
    lines = md_text.split("\n")
    out: list[str] = []
    i = 0
    while i < len(lines):
        line = lines[i]
        if _TEACHER_TAG_RE.match(line):
            # Collect the blockquote that follows.
            out.append(line)
            i += 1
            kept = 0
            while i < len(lines) and lines[i].lstrip().startswith(">"):
                stripped = lines[i].lstrip()
                # Always keep empty quote lines if we are still under the cap.
                content = stripped[1:].strip()
                if not content:
                    if kept > 0:
                        out.append(lines[i])
                    i += 1
                    continue
                if kept < max_quote_lines:
                    out.append(lines[i])
                    kept += 1
                i += 1
            # If we dropped lines, add an ellipsis quote line.
            if i < len(lines) and kept >= max_quote_lines:
                out.append("> …")
        else:
            out.append(line)
            i += 1
    return "\n".join(out)


# ---------------------------------------------------------------------------
# Expected output extraction from *.cpp files
# ---------------------------------------------------------------------------

_CPP_BLOCK_RE = re.compile(
    r"//\s*----\s*(?P<kind>Example|Practice|Problem)\s*(?P<num>\d+)(?:\s*:\s*(?P<title>[^\r\n]+?))?\s*----",
    re.IGNORECASE,
)

_OUTPUT_SECTION_RE = re.compile(
    r"(?:Sample\s+Input|Expected\s+Output)\s*:\s*\n(?P<body>(?:[^\n]*\n){0,40})",
    re.IGNORECASE,
)


def parse_cpp_examples(path: Path) -> list[dict]:
    """
    Parse a *.cpp file that follows the classroom template.

    Returns a list of {index, kind, title, code, input, output} dicts.
    Missing fields are empty strings.
    """
    if not path.exists():
        return []
    text = path.read_text(encoding="utf-8", errors="replace")
    markers = list(_CPP_BLOCK_RE.finditer(text))
    results: list[dict] = []
    for i, m in enumerate(markers):
        start = m.end()
        end = markers[i + 1].start() if i + 1 < len(markers) else len(text)
        block = text[start:end]
        code_chunk = block
        sample_input = ""
        expected_output = ""

        # Look for a /* ... */ block that contains Expected Output or Sample Input.
        for c in re.finditer(r"/\*(?P<body>.+?)\*/", block, re.DOTALL):
            body = c.group("body")
            if not re.search(r"(Expected\s+Output|Sample\s+Input)", body, re.IGNORECASE):
                continue

            # The comment body looks like:
            #   * Sample Input: 7
            #   *
            #   * Expected Output:
            #   * 1
            #   * 2
            # We first strip the leading " * " from each line, then split
            # by labelled sections.
            cleaned = _clean_comment_block(body)
            sample_input = _extract_labelled(cleaned, r"Sample\s+Input")
            expected_output = _extract_labelled(cleaned, r"Expected\s+Output")

            # Trim the code block so it ends before this /* ... */ comment.
            code_chunk = block[: c.start()].rstrip() + "\n"
            break

        code_chunk = code_chunk.strip("\n")
        code_chunk = _strip_outer_block_comment(code_chunk)

        results.append({
            "index": int(m.group("num")),
            "kind": m.group("kind").capitalize(),
            "title": (m.group("title") or "").strip(),
            "code": code_chunk,
            "input": sample_input.strip(),
            "output": expected_output.strip(),
        })
    return results


def _extract_labelled(cleaned: str, label_re: str) -> str:
    """
    Given a cleaned (no leading '* ') comment body, extract the text after
    `LABEL:` until the next labelled section or end of body.
    """
    lines = cleaned.splitlines()
    label = re.compile(label_re + r"\s*:\s*(.*)$", re.IGNORECASE)
    stop_labels = ("sample input", "expected output", "sample output", "notes")

    out: list[str] = []
    capturing = False
    for ln in lines:
        stripped = ln.strip()
        m = label.match(stripped)
        if m:
            capturing = True
            tail = m.group(1).strip()
            if tail:
                out.append(tail)
            continue
        if capturing:
            low = stripped.lower()
            # Stop when a new labelled section begins.
            if any(low.startswith(s + ":") for s in stop_labels):
                break
            out.append(ln)
    # Drop surrounding blank lines.
    while out and not out[0].strip():
        out.pop(0)
    while out and not out[-1].strip():
        out.pop()
    return "\n".join(out)


def _clean_comment_block(body: str) -> str:
    """Remove leading ' * ' from C-block-comment lines."""
    out = []
    for line in body.splitlines():
        stripped = line.lstrip()
        if stripped.startswith("*"):
            stripped = stripped[1:]
            if stripped.startswith(" "):
                stripped = stripped[1:]
        out.append(stripped.rstrip())
    # Trim trailing blank lines.
    while out and not out[-1].strip():
        out.pop()
    while out and not out[0].strip():
        out.pop(0)
    return "\n".join(out)


def _strip_outer_block_comment(code: str) -> str:
    """If a code chunk is entirely inside /* ... */, unwrap it."""
    s = code.strip()
    if s.startswith("/*") and s.endswith("*/"):
        inner = s[2:-2]
        return _clean_comment_block(inner).strip()
    return code


# ---------------------------------------------------------------------------
# HTML fragment builders
# ---------------------------------------------------------------------------

def student_info_block() -> str:
    return (
        '<div class="student-info">'
        '<span class="row">姓名：________________________&nbsp;&nbsp;&nbsp;'
        '班级：________________&nbsp;&nbsp;&nbsp;'
        '学号：________________</span>'
        '<span class="row">日期：______年______月______日&nbsp;&nbsp;&nbsp;'
        '得分：________&nbsp;/&nbsp;________'
        '</span>'
        '</div>'
    )


def answer_area(size: str = "medium") -> str:
    cls = size if size in {"small", "medium", "large"} else "medium"
    return f'<div class="answer-area {cls}">&nbsp;</div>'


def cover_page(title: str, subtitle: str, lesson_name: str) -> str:
    return (
        '<div class="cover">'
        f'<div class="title">{title}</div>'
        f'<div class="subtitle">{subtitle}</div>'
        '<div class="meta">'
        f'<div>课程：C++ 信息学启蒙 · 小学四年级</div>'
        f'<div>课次：{lesson_name}</div>'
        f'<div>共 40 课 · CSP-J / 蓝桥杯少儿组 备赛</div>'
        '</div>'
        '</div>'
    )
