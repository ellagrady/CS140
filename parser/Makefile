
# This is the Makefile for main.c, IntQueue.c and IntQueue.h
# To use it, put it in the same directory as those three files.
# To compile, simply type "make" at the command line.
# To remove all object code, type "make clean" (this removes
# all ".o" and ".a" files)

# Executable file "exec" depends on main.o and IntQueue.o
assembler:  parser.o main.o code.o map.o
	gcc -o assembler parser.o main.o code.o map.o
	
parser.o: parser.c
	gcc -c parser.c
	
main.o: main.c
	gcc -c main.c
	
code.o: code.c
	gcc -c code.c
	
map.o: map.c
	gcc -c map.c

clean:
	rm -f *~ *.o *.a 
#^^^This space must be a TAB!!.


