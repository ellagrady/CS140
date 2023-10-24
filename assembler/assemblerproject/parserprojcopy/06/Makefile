# Ella Grady
# Makefile for assembler project
# March 22 2022

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


