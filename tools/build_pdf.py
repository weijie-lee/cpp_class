#!/usr/bin/env python3
"""
Build print-ready A4 PDFs for every lesson in the course.

For each 第XX课_*/ folder this script produces three PDFs under pdf/:

    01_教案.pdf         teacher lesson plan (sections 1-4, 7, 9)
    02_例题讲义.pdf     classroom handout with example code & output (section 5)
    03_练习册.pdf       student workbook with answer areas (sections 6 & 8)

Special lessons (12/24/34/40) emit an alternative set — review guide,
exam paper, and answer key — see build_special_lesson().
"""
from __future__ import annotations

import argparse
import html
import re
import sys
from pathlib import Path

import markdown
from weasyprint import CSS, HTML
from weasyprint.text.fonts import FontConfiguration

sys.path.insert(0, str(Path(__file__).parent))
from transforms import (  # noqa: E402
    answer_area,
    cover_page,
    extract_preamble,
    parse_cpp_examples,
    shrink_teacher_dialogue,
    split_sections,
    strip_emoji,
    student_info_block,
)

# ---------------------------------------------------------------------------
# Paths and constants
# ---------------------------------------------------------------------------

ROOT = Path(__file__).resolve().parent.parent
CSS_PATH = Path(__file__).parent / "print.css"

MD_EXTENSIONS = ["tables", "fenced_code", "sane_lists", "attr_list", "nl2br"]

SPECIAL_LESSONS = {12, 24, 34, 40}

FONT_CONFIG = FontConfiguration()


# ---------------------------------------------------------------------------
# Lesson discovery
# ---------------------------------------------------------------------------

_LESSON_RE = re.compile(r"^第(\d{2})课_")


def lesson_dirs() -> list[Path]:
    dirs = []
    for p in sorted(ROOT.iterdir()):
        if p.is_dir() and _LESSON_RE.match(p.name):
            dirs.append(p)
    return dirs


def lesson_number(path: Path) -> int:
    m = _LESSON_RE.match(path.name)
    return int(m.group(1)) if m else -1


# ---------------------------------------------------------------------------
# Markdown → PDF helpers
# ---------------------------------------------------------------------------

def render_pdf(md_body: str, out_path: Path, title: str) -> None:
    """Convert a Markdown string to a PDF at out_path."""
    md_body = strip_emoji(md_body)
    html_body = markdown.markdown(md_body, extensions=MD_EXTENSIONS,
                                  output_format="html5")
    full_html = f"""<!doctype html>
<html lang="zh-CN">
<head>
<meta charset="utf-8">
<title>{html.escape(title)}</title>
</head>
<body>
{html_body}
</body>
</html>"""
    css = CSS(filename=str(CSS_PATH), font_config=FONT_CONFIG)
    HTML(string=full_html, base_url=str(out_path.parent)).write_pdf(
        str(out_path), stylesheets=[css], font_config=FONT_CONFIG
    )


def render_html_pdf(html_body: str, out_path: Path, title: str) -> None:
    """Convert a raw HTML body (not markdown) to a PDF."""
    full_html = f"""<!doctype html>
<html lang="zh-CN">
<head>
<meta charset="utf-8">
<title>{html.escape(title)}</title>
</head>
<body>
{html_body}
</body>
</html>"""
    css = CSS(filename=str(CSS_PATH), font_config=FONT_CONFIG)
    HTML(string=full_html, base_url=str(out_path.parent)).write_pdf(
        str(out_path), stylesheets=[css], font_config=FONT_CONFIG
    )


# ---------------------------------------------------------------------------
# Standard lesson builders
# ---------------------------------------------------------------------------

def build_teacher_plan(lesson_dir: Path, sections: dict, preamble: str) -> None:
    """01_教案.pdf — teacher's concise lesson plan."""
    picks = [1, 2, 3, 4, 7, 9]
    out_parts = [preamble.strip(), ""]
    for n in picks:
        if n in sections:
            body = sections[n]["body"]
            if n == 4:  # 讲稿提纲 — trim narrative
                body = shrink_teacher_dialogue(body, max_quote_lines=4)
            out_parts.append(body.strip())
            out_parts.append("")
    md_body = "\n".join(out_parts)

    out_dir = lesson_dir / "pdf"
    out_dir.mkdir(exist_ok=True)
    render_pdf(md_body, out_dir / "01_教案.pdf",
               title=f"{lesson_dir.name} · 教案")


def build_examples_handout(lesson_dir: Path, sections: dict, preamble: str) -> None:
    """02_例题讲义.pdf — examples with code and expected output."""
    out_dir = lesson_dir / "pdf"
    out_dir.mkdir(exist_ok=True)

    header = preamble.strip() + "\n\n> 本讲义配合课堂例题讲解使用，代码可直接在 Dev-C++ 中运行验证。\n\n"
    section_body = sections.get(5, {}).get("body", "").strip() or \
                   "## 五、课堂例题\n\n（本课暂无独立例题代码，请参考教案与测试卷。）\n"

    # Append expected-output-rich code listings from examples.cpp
    examples_cpp = lesson_dir / "examples.cpp"
    extras_md = build_code_appendix(examples_cpp, kind="Example")

    md_body = header + section_body + "\n\n" + extras_md
    render_pdf(md_body, out_dir / "02_例题讲义.pdf",
               title=f"{lesson_dir.name} · 例题讲义")


def build_practice_workbook(lesson_dir: Path, sections: dict, preamble: str) -> None:
    """03_练习册.pdf — practice problems with blank answer areas."""
    out_dir = lesson_dir / "pdf"
    out_dir.mkdir(exist_ok=True)

    # Build HTML directly so we can inject the student info block and
    # answer areas as raw HTML alongside rendered markdown.
    title_md = preamble.strip()
    title_html = markdown.markdown(strip_emoji(title_md),
                                    extensions=MD_EXTENSIONS)

    practice_md = sections.get(6, {}).get("body", "").strip()
    homework_md = sections.get(8, {}).get("body", "").strip()

    pieces: list[str] = [title_html, student_info_block()]

    if practice_md:
        pieces.append(render_practice_section(practice_md))
    if homework_md:
        pieces.append(markdown.markdown(
            strip_emoji(homework_md), extensions=MD_EXTENSIONS))

    html_body = "\n".join(pieces)
    render_html_pdf(html_body, out_dir / "03_练习册.pdf",
                    title=f"{lesson_dir.name} · 练习册")


# ---------------------------------------------------------------------------
# Helpers used by builders
# ---------------------------------------------------------------------------

# Match "### 练习 1" / "### 练习 1：xxx" / "### 练习 1（挑战题）"
_PRACTICE_RE = re.compile(r"^###\s+练习\s*\d+", re.MULTILINE)

# Anything starting a "reference answer" section inside a practice problem.
# Matches: **参考答案**, **参考答案（方法一）**, ## 参考答案, 等等
_ANSWER_LABEL_RE = re.compile(
    r"(?:\*\*参考答案.*?\*\*|^#{2,4}\s*参考答案.*$)",
    re.MULTILINE,
)


def _strip_practice_answer(chunk: str) -> str:
    """
    Within a single practice-problem chunk, cut everything from the first
    "参考答案" marker to the end of the chunk.

    If there's no marker, return the chunk unchanged.
    """
    m = _ANSWER_LABEL_RE.search(chunk)
    if not m:
        return chunk.rstrip() + "\n"
    stripped = chunk[: m.start()].rstrip()
    # Also drop any trailing "> …" teacher-commentary that was leading up to the answer.
    return stripped + "\n"


def render_practice_section(section_md: str) -> str:
    """
    Render the 课堂练习题 section, injecting an .answer-area after each
    individual problem. Reference answers are hidden from the student workbook.
    """
    section_md = strip_emoji(section_md)
    matches = list(_PRACTICE_RE.finditer(section_md))
    if not matches:
        cleaned = _strip_practice_answer(section_md)
        return markdown.markdown(cleaned, extensions=MD_EXTENSIONS) + \
               answer_area("large")

    pieces: list[str] = []
    # Pre-heading chunk (the "## 六、课堂练习题" line etc.).
    first_start = matches[0].start()
    if first_start > 0:
        pieces.append(markdown.markdown(section_md[:first_start],
                                        extensions=MD_EXTENSIONS))

    for i, m in enumerate(matches):
        start = m.start()
        end = matches[i + 1].start() if i + 1 < len(matches) else len(section_md)
        chunk = section_md[start:end]
        cleaned = _strip_practice_answer(chunk)
        pieces.append(markdown.markdown(cleaned, extensions=MD_EXTENSIONS))
        # Pick answer area size by problem text length (after answer stripped).
        size = "large" if len(cleaned) > 500 else ("medium" if len(cleaned) > 200 else "small")
        pieces.append(answer_area(size))

    return "\n".join(pieces)


def build_code_appendix(cpp_path: Path, kind: str) -> str:
    """Render parsed code blocks as markdown with Sample Input / Expected Output."""
    if not cpp_path.exists():
        return ""
    blocks = parse_cpp_examples(cpp_path)
    blocks = [b for b in blocks if b["kind"].lower() == kind.lower()]
    if not blocks:
        return ""

    parts = ["", f"## 附：{kind_to_chinese(kind)}源代码与运行结果", ""]
    for b in blocks:
        heading = f"### {kind_to_chinese(kind)} {b['index']}"
        if b["title"]:
            heading += f"：{b['title']}"
        parts.append(heading)
        parts.append("")
        parts.append("```cpp")
        parts.append(b["code"])
        parts.append("```")
        if b["input"]:
            parts.append("**Sample Input**")
            parts.append("")
            parts.append("```")
            parts.append(b["input"])
            parts.append("```")
        if b["output"]:
            parts.append("**Expected Output**")
            parts.append("")
            parts.append("```")
            parts.append(b["output"])
            parts.append("```")
        parts.append("")
    return "\n".join(parts)


def kind_to_chinese(kind: str) -> str:
    return {"Example": "例题", "Practice": "练习", "Problem": "题目"}.get(
        kind.capitalize(), kind)


# ---------------------------------------------------------------------------
# Special lessons (12 / 24 / 34 / 40)
# ---------------------------------------------------------------------------

def build_special_lesson(lesson_dir: Path) -> None:
    """Review + exam lessons have a different layout."""
    out_dir = lesson_dir / "pdf"
    out_dir.mkdir(exist_ok=True)

    # 01_复习.pdf — just the full 教案 sans emoji.
    plan_md = (lesson_dir / "教案.md").read_text(encoding="utf-8")
    render_pdf(plan_md, out_dir / "01_复习.pdf",
               title=f"{lesson_dir.name} · 复习")

    # 02_测试卷 / 模拟赛 — strip the answer block.
    test_md_path = lesson_dir / "测试卷.md"
    if not test_md_path.exists():
        test_md_path = lesson_dir / "模拟赛试卷.md"
    if test_md_path.exists():
        exam_md = test_md_path.read_text(encoding="utf-8")
        # Students get the paper WITHOUT answers; we add answer blanks instead.
        student_md, answer_md = strip_answers(exam_md)
        header_html = markdown.markdown(
            strip_emoji(extract_preamble(student_md)), extensions=MD_EXTENSIONS)
        student_html = header_html + student_info_block() + \
            markdown.markdown(strip_emoji(after_preamble(student_md)),
                              extensions=MD_EXTENSIONS)
        out_name = "02_测试卷.pdf" if "测试卷" in test_md_path.name else "02_模拟赛.pdf"
        render_html_pdf(student_html, out_dir / out_name,
                        title=f"{lesson_dir.name} · 学生卷")

        render_pdf(answer_md, out_dir / "03_答案.pdf",
                   title=f"{lesson_dir.name} · 参考答案")


_ANSWER_HEADING_RE = re.compile(
    # Heading level 1-4, optionally followed by emoji/whitespace, then the label.
    r"^#{1,4}[^\n\w]*(参考答案|标准答案|答案与解析|答案和评分|答案|评分建议|评分标准)[^\n]*$",
    re.MULTILINE,
)


def strip_answers(md_text: str) -> tuple[str, str]:
    """Split an exam markdown into (student_version, answer_key).

    The answer key is detected by the first heading (# through ####) whose
    text contains 参考答案 / 答案 / 评分建议 etc.
    """
    m = _ANSWER_HEADING_RE.search(md_text)
    if not m:
        return md_text, md_text
    student_part = md_text[: m.start()].rstrip() + "\n"
    answer_part = md_text[m.start():]
    # Keep the original title/preamble in the answer key for context.
    preamble = extract_preamble(md_text)
    if preamble and not answer_part.startswith("#"):
        answer_part = preamble + answer_part
    return student_part, answer_part


def after_preamble(md_text: str) -> str:
    pre = extract_preamble(md_text)
    return md_text[len(pre):]


# ---------------------------------------------------------------------------
# Main entrypoint
# ---------------------------------------------------------------------------

def build_lesson(lesson_dir: Path) -> None:
    n = lesson_number(lesson_dir)
    print(f"[build] L{n:02d}  {lesson_dir.name}", flush=True)

    if n in SPECIAL_LESSONS:
        build_special_lesson(lesson_dir)
        return

    md_path = lesson_dir / "教案.md"
    if not md_path.exists():
        print(f"  !! missing 教案.md, skipping")
        return

    md_text = md_path.read_text(encoding="utf-8")
    sections = split_sections(md_text)
    preamble = extract_preamble(md_text)

    build_teacher_plan(lesson_dir, sections, preamble)
    build_examples_handout(lesson_dir, sections, preamble)
    build_practice_workbook(lesson_dir, sections, preamble)


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--lesson", type=int,
                        help="Build only the given lesson number (1-40).")
    parser.add_argument("--from", dest="from_n", type=int, default=1,
                        help="Start lesson (inclusive).")
    parser.add_argument("--to", dest="to_n", type=int, default=40,
                        help="End lesson (inclusive).")
    args = parser.parse_args(argv)

    targets = []
    for d in lesson_dirs():
        n = lesson_number(d)
        if args.lesson is not None:
            if n == args.lesson:
                targets.append(d)
        else:
            if args.from_n <= n <= args.to_n:
                targets.append(d)

    if not targets:
        print("No lessons matched.", file=sys.stderr)
        return 1

    for d in targets:
        try:
            build_lesson(d)
        except Exception as e:  # pragma: no cover - best-effort loop
            print(f"  !! failed {d.name}: {e}", flush=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
