//
//  parser.c
//
//
//  Created by Ella Grady on 2/23/22.
//

#include <stdio.h>
#include "parser.h"
#include <ctype.h>
#include <stdlib.h>

#include <string.h>

#define MAX_LENGTH 200

void mystrcpy(char *out, char *in) {
    
    int i = 0;
    // repeat until reach null character
    while(in[i] != '\0') {
        out[i]=in[i];
        i++;
    }
    out[i]= '\0'; // NULL terminate the output
}

void mystrcpypointer(char *out, char *in) {
    
    while (*in != '\0') {
        *out =*in;
        
        //advance the pointers
        in++;
        out++;
    }
    
    *out = '\0';
}
int removespacesandtabs(char *out, char *in) {
    
    int inindex = 0;
    int outindex = 0;
    // repeat until reach null character
    while(in[inindex] != '\0' && in[inindex] != '/') {
        // if(in[inindex] == '/'){
            // break;
        // }
        if(!isspace(in[inindex])) {
            out[outindex]=in[inindex];
            outindex++;
        }
        inindex++;
    }
    out[outindex]= '\0'; // NULL terminate the output
    return (out[0] != '\0');
}

int removespacesandtabspointer(char *out, char *in) {
    
    // int inindex = 0;
    // int outindex = 0;
    // repeat until reach null character
    while(*in != '\0' && *in != '/') {
        // if(in[inindex] == '/'){
            // break;
        // }
        if(!isspace(*in)) {
            *out = *in;
            out++;
        }
        in++;
    }
    *out= '\0'; // NULL terminate the output
    
    return (out[0] != '\0');
}

FILE * readfile(char *outfile, char *infile) {
    FILE *infilepointer;
    infilepointer = fopen(infile, "r+");
    FILE *outfilepointer;
    outfilepointer = fopen(outfile, "w+");
    if (infilepointer == NULL)
    {
        perror("Error: could not open file ");
        exit(1);
    }
    
    char buffer[MAX_LENGTH];
    char outputline[MAX_LENGTH];

    fgets(buffer, MAX_LENGTH, infilepointer );
    while (!feof(infilepointer)){
        
        removespacesandtabs(outputline, buffer);
        fputs(outputline, outfilepointer);
        fputs('\n', outfilepointer);
        fgets(buffer, MAX_LENGTH, infilepointer );
    }
    
    
    // close the file
    fclose(infilepointer);
    return outfilepointer;
}

void sequenceoutput(FILE *outfilepointer) {
    //FILE *outfilepointer;
    //outfilepointer = fopen(outfile, "r");
    if (outfilepointer == NULL) {
        perror("Error opening input file:");
        exit(1);
    }
    
    char buffer[MAX_LENGTH];
    fgets(buffer, MAX_LENGTH, outfilepointer);
    while (!feof(outfilepointer)){
        if (buffer[0] == '@') {
            fputs("A-Command", outfilepointer);
        }
        else if (buffer[0] == '(') {
            fputs("L-Command", outfilepointer);
        }
        else {
            fputs("C-Command", outfilepointer);
        }
        fgets(buffer, MAX_LENGTH, outfilepointer);
    }
}



int main(int argc, char** argv) {
    
    char inputbuffer[MAX_LENGTH];
    char copiedbuffer[MAX_LENGTH];
    
    char *in = argv[1];
    char *out = argv[2];
    
    FILE *pointer = readfile(out, in);
    
    sequenceoutput(pointer);
    
    //strcpy(inputbuffer, "Hello World");
    //mystrcpypointer(copiedbuffer, inputbuffer);
    //removespacesandtabs(inputbuffer, "Hello World // example");
    //removespacesandtabspointer(copiedbuffer, "Hello World // example");
    
    //puts(inputbuffer);
    //puts(copiedbuffer);
    

}
