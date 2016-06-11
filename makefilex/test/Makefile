#Include directory in which header files exists
IDIR=./
#Object files directory in which object files exists
ODIR=./
#Libry path
LDIR=../

#Libray names
LIBS=-lm

#Compiler name
CC=gcc
CFLAGS=-I$(IDIR)
_DEPS=t.h
#%: applies to all files. 
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJS=t.o t2.o
OBJS=$(patsubst %,$(ODIR)/%,$(_OBJS))

#the special macros $@ and $^, which are the left and right sides of the :, respectively,
#the $< is the first item in the dependencies list,
$(ODIR)/%.o:%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

t:$(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)
#The .PHONY rule keeps make from doing something with a file named clean.
#Remember the all and clean special targets in our Makefile?
#What happens when the project directory has files with the names all or clean?
#The conflicts will cause errors.
#Use the .PHONY directive to specify which targets are not to be treated as files 
#for example: .PHONY: all clean.
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(IDIR)/*~
