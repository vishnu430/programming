IDIR=./
ODIR=./
LDIR=../

LIBS=-lm

CC=gcc
CFLAGS=-I$(IDIR)
_DEPS=t.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJS=t.o t2.o
OBJS=$(patsubst %,$(ODIR)/%,$(_OBJS))

$(ODIR)/%.o:%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

t:$(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(IDIR)/*~
