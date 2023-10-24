
/****************************************************************
 File: main.c
 ------------
 A main program to demonstrate the IntQueue ADT.
 It enqueues the numbers 0 through 99 and then dequeues
 them.
*/

#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

int main(void) 
{
    FILE *file;
    char filename[200];
    char *newline;
    file = fopen(filename, "r");
    if (file) {
        int chr;
        while ((chr = fgetc(file)) != EOF)
            fputc(chr, stdout);
        fclose(file);
    } else {
        printf("File not found.");
    }
    printf("\n");
    return 0;
	/* int i;
	int data;
	IntStack stack = createStack();

	for (i=0; i<20; i++) {
		data = i;
		printf("Pushing %d\n", data);
		push(stack, data);
	} 

	if (!isEmpty(stack))
	{
		while (!isEmpty(stack))
		{
			data = pop(stack);
			printf("Popping %d\n", data);
		}
	}
	else
		printf("Stack is empty.\n");

	deleteStack(stack);

	return 0; */
}
