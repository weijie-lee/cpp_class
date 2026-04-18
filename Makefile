# ============================================================
# C++ CSP-J course — PDF build
# ============================================================

PYTHON ?= python3
BUILD   = $(PYTHON) tools/build_pdf.py

.PHONY: help all lesson clean install-deps

help:
	@echo "Targets:"
	@echo "  make all           — regenerate all lesson PDFs (40 lessons)"
	@echo "  make lesson N=7    — regenerate one lesson"
	@echo "  make range FROM=1 TO=11  — regenerate a lesson range"
	@echo "  make clean         — remove every pdf/ folder"
	@echo "  make install-deps  — install weasyprint + python-markdown"

all:
	$(BUILD)

lesson:
	@test -n "$(N)" || (echo 'Usage: make lesson N=<number>' && exit 1)
	$(BUILD) --lesson $(N)

range:
	$(BUILD) --from $(FROM) --to $(TO)

clean:
	find . -type d -name pdf -prune -exec rm -rf {} +

install-deps:
	apt install -y weasyprint python3-markdown python3-pygments \
	    fonts-noto-cjk fonts-noto-mono
