//
//  main.c
//  assemblerproject
//
//  Created by Ella Grady on 3/2/22.
//

#include <stdio.h>
#include "parser.h"
#include <unistd.h>
#include "code.h"
#define MAX_SIZE 200

extern map comp;
extern map dest;
extern map jmp;
extern map lines;

int main(int argc, char * argv[]) {
    
     // char inputbuffer[MAX_LENGTH];
     // char copiedbuffer[MAX_LENGTH];
     char buffer[200];
    
     getcwd(buffer, 200);
     // puts(buffer);
     char *in = argv[1];
     char *temp = "temp.asm";
     char *out = argv[2];
    
    // first read through of input to clean up and create temp file
     FILE *pointer = readfile(temp, in);
    
    // create maps
    ccommands();
    symbolTable(temp);
    // puts(lookupKey(comp, "0"));
    // puts(lookupKey(dest, "null"));
    // puts(lookupKey(jmp, "null"));


    // translating all commands to binary
    translate(out, temp);
    
    // free up memory of maps
    freeMap(comp);
    freeMap(dest);
    freeMap(jmp);
    freeMap(lines);
    //passone(temp);
    
    //strcpy(inputbuffer, "Hello World");
    //mystrcpypointer(copiedbuffer, inputbuffer);
    //removespacesandtabs(inputbuffer, "Hello World // example");
    //removespacesandtabspointer(copiedbuffer, "Hello World // example");
    
    //puts(inputbuffer);
    //puts(copiedbuffer);
    

}
