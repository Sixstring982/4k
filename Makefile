SOURCE=./src/main.c
BIN=./bin/big
BUILDDIR=./build
TINYEXE=./bin/tiny

CC=gcc
CCFLAGS=-Wall -pedantic -ansi -Werror
TINYFLAGS=-m32 -Os -fomit-frame-pointer
GZEXE=./gscript.sh

LINKLIBS=/home/sixstring982/.local/share/Steam/ubuntu12_32/steam-runtime/i386/usr/lib/i386-linux-gnu/libSDL-1.2.so.0.11.4 /usr/lib32/nvidia-304-updates/libGL.so

all:	$(TINYEXE)

$(BIN):	$(SOURCE)
	mkdir -p ./bin ./build
	$(CC) $(CCFLAGS) $(TINYFLAGS) -c $^ -o $(BUILDDIR)/main.o
	ld -melf_i386 -dynamic-linker /lib/ld-linux.so.2 $(BUILDDIR)/main.o  -o $@ -lc
	strip -S --strip-unneeded --remove-section=.note.gnu.build-id --remove-section=.note.ABI-tag $@
	sstrip $@

$(TINYEXE):	$(BIN)
	gzip -cn9 $^ | cat $(GZEXE) - > $@
	chmod 755 $@

clean:
	rm -rf ./bin

.PHONY:	clean
