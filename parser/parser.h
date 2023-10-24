//
//  parser.h
//  
//
//  Created by Ella Grady on 2/23/22.
//

#ifndef parser_h
#define parser_h
#include "code.h"
#include "map.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
extern map comp;
extern map dest;
extern map jmp;
extern map lines;

int removespacesandtabs(char *out, char *in);
int removelines(char *out, char *in);

FILE * readfile(char *outfile, char *infile);

void sequenceoutput(char *outfile, char *infile);
char* passtwonumber (char *buffer);
void passtwolabel (char *buffer);
void passone(char *infile);
char *strrev(char *str);
void binaryconvert(char *output, char *input);
void translate(char *outfile, char *infile);

#endif /* parser_h */
