//
//  code.h
//  assemblerproject
//  creates maps for parser.c
//
//  Created by Ella Grady on 3/14/22.
//

#ifndef code_h
#define code_h

#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "map.h"
 map comp;
 map dest;
 map jmp;
map lines;

void ccommands();
void symbolTable(char *infile);


#endif /* code_h */
