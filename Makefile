CC = gcc -g
CCFLAGS = -Wall
OUTFILE = testtarget
DEPS = src/testtarget.c

all:
	$(CC) $(CCFLAGS) -o $(OUTFILE) $(DEPS)

clean:
	$(RM) $(OUTFILE)
