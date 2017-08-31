CC = gcc -g
CCFLAGS = -Wall -m32
OUTFILE = testtarget
DEPS = src/testtarget.c

all:
	$(CC) $(CCFLAGS) -o $(OUTFILE) $(DEPS)

clean:
	$(RM) $(OUTFILE)
