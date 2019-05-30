CC:=gcc
CFLAGS:=-Wall
OBJDIR:=obj
SRCDIR:=src

LIBBASEDIR:=libs
LIBMATHDIR:=mathlib

MAIN_FILE=$(SRCDIR)/main.c

MATHLIB_ARCHIVE=$(LIBBASEDIR)/$(LIBMATHDIR)/mathlib.a

all: library main.o

library:
	@$(MAKE) -C $(LIBBASEDIR)/${LIBMATHDIR}

main.o:
	$(CC) $(CFLAGS) -o $(OBJDIR)/$@ $(MAIN_FILE) $(MATHLIB_ARCHIVE)


.PHONY: clean
clean:
	rm -f $(OBJDIR)/*.o
	rm -f $(OBJDIR)/result.txt
	@$(MAKE) clean -C $(LIBBASEDIR)/${LIBMATHDIR}

