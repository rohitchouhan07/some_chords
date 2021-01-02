PREFIX ?= /usr
BINDIR ?= $(PREFIX)/bin
CC     ?= gcc
LIBS    = -lncurses -lmenu

all: chords

chords: 
	$(CC) chords.c -o some_chords $(LIBS)

install: all
	mkdir -p $(PREFIX)/share/some_chords
	cp a.txt b.txt c.txt d.txt e.txt f.txt g.txt /usr/share/some_chords
	install -Dm755 some_chords $(DESTDIR)$(BINDIR)/some_chords

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/some_chords

clean:
	rm -f some_chords *.o

.PHONY: all install uninstall clean
