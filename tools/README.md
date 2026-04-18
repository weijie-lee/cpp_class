# tools/ — A4 打印版 PDF 构建工具

本目录存放将课程 Markdown 源文件转换为 A4 打印版 PDF 的脚本。

## 产出

对于每一课 `第XX课_XX/`，在子目录 `pdf/` 中生成三份独立 PDF：

| 文件 | 用途 | 内容来源 |
|------|------|---------|
| `01_教案.pdf` | 教师讲稿（精简版） | 教案.md 的第一～四（讲稿提纲做了裁剪）、七、九段 |
| `02_例题讲义.pdf` | 课堂发给学生参考 | 教案.md 第五段 + examples.cpp 的代码与 Expected Output |
| `03_练习册.pdf` | 学生课堂填写 | 教案.md 第六、八段，答案已剥离，每题下留空白作答区 |

### 特殊课程（第 12 / 24 / 34 / 40 课）

阶段测试课和模拟赛课按如下拆分：

| 文件 | 用途 |
|------|------|
| `01_复习.pdf` | 阶段知识回顾 |
| `02_测试卷.pdf` 或 `02_模拟赛.pdf` | 学生卷，已删除参考答案，顶部有姓名栏 |
| `03_答案.pdf` | 教师参考答案（含评分建议） |

## 使用

```bash
# 安装依赖（首次使用）
make install-deps

# 全量重建
make all

# 仅重建一课
make lesson N=7

# 重建一个区间
make range FROM=1 TO=11

# 清理
make clean
```

也可以直接调用脚本：

```bash
python3 tools/build_pdf.py                  # 全部
python3 tools/build_pdf.py --lesson 15      # 单课
python3 tools/build_pdf.py --from 25 --to 34   # 区间
```

## 目录结构

```
tools/
├── build_pdf.py     # 主构建脚本
├── transforms.py    # Markdown 转换工具（去 emoji、拆段、提取代码输出）
├── print.css        # A4 打印样式表
└── README.md        # 本文件
```

## 依赖

- Python 3.10+
- [WeasyPrint](https://weasyprint.org/)（`apt install weasyprint`）
- `python3-markdown`
- Noto CJK 字体（`fonts-noto-cjk`）

WeasyPrint 走 HTML + CSS → PDF，不需要 LaTeX，对中文字体支持完善。

## 自定义样式

调整 A4 打印外观请编辑 [tools/print.css](./print.css)。常用调整：

- `@page { margin: ... }` — 页边距
- `body { font-size: ... }` — 正文字号
- `.answer-area.small/medium/large { min-height: ... }` — 练习作答区高度
- `.student-info { ... }` — 姓名栏外观

改完 CSS 后运行 `make all` 即可重新生成全部 PDF。

## 已知限制

- WeasyPrint 对 CSS grid/flex 支持有限，但本文档场景（文本 + 表格 + 代码块）完全够用。
- 生成的 PDF 每份 ~400-800KB，全部 40 课约 40-60MB，已提交入库便于教师直接下载打印。
- 如果需要减小仓库体积，可将 `pdf/` 加入 `.gitignore` 并改由 CI 构建。
