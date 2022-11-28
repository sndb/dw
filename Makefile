CC = cc
FLAGS = -std=c11 -pedantic -Wall -Wextra -Os
PREFIX = /usr/local

dw: dw.c
	${CC} ${FLAGS} dw.c -o $@

clean:
	rm -f dw

install: dw
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f dw ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/dw

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/dw

.PHONY: clean install uninstall
