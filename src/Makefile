OPTIONS = -Wall -Wextra
BUILDDIR = build

.PHONY: all
all: ${BUILDDIR}/array ${BUILDDIR}/apple ${BUILDDIR}/spear ${BUILDDIR}/works

${BUILDDIR}:
	mkdir -p ${BUILDDIR}
${BUILDDIR}/%: %.c ${BUILDDIR}
	gcc ${OPTIONS} -o $@ $<

clean:
	rm -rf ${BUILDDIR}/*
