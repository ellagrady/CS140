//
//  code.c
//  assemblerproject
//  creates maps for parser.c
//
//  Created by Ella Grady on 3/14/22.
//

#include "code.h"
#include "map.h"
#include<stdio.h>
#include<string.h>
#include <stdlib.h>


#define MAX_SIZE 2000
#define MAX_LENGTH 200


map comp; //  map for comp values
map dest; // map for dest values
map jmp; // map for jmp values
map lines; // map for labels

// creates comp dest and jmp maps
void ccommands(){
    // comp = createMap(MAX_SIZE);
    FILE *comppointer;
    char comprow[MAX_LENGTH];

    comppointer = fopen("comp.txt","r"); // comp map based on comp.txt containing comp keys and values
    // puts("ccomand1");
     comp = createMap(MAX_SIZE);
     dest = createMap(MAX_SIZE);
     jmp = createMap(MAX_SIZE);

        
    while (!feof(comppointer))
    {
        // puts("ccomand2");
        char *hold;
       
        // puts("ccomanda");

        fgets(comprow, MAX_LENGTH, comppointer);
        // puts(comprow);
        // printf("%c\n",comprow[2]);
        //puts(comprow[1]);
        // puts("ccomandb");
        
        char *comma = strchr(comprow, ',');
        // puts(comma);
        int commaindex = comma  - comprow;
        char key[commaindex+1];
        char value[strlen(comprow)];
        // printf("commaindex%i\n", commaindex);
        strncpy(key, comprow, commaindex);
        key[commaindex] = '\0';
        // puts(key);
        // puts("ccommandc");
        strncpy(value, comprow + (commaindex + 1), strlen(comprow));
        
        // uts("ccommandd");
        insertKey(comp, key, value );
        // puts("ccommandc");
         // puts("comp key ");
         // puts(key);
         // puts("\ncomp value ");
         // puts(value);
    }
    fclose(comppointer);
    
    // dest = createMap(MAX_SIZE);
    FILE *destpointer;
    char destrow[MAX_LENGTH];

    destpointer = fopen("dest.txt","r"); // dest map based on dest.txt containing dest keys and values
    // puts("ccomand3");

        
    while (!feof(destpointer))
    {
        // puts("ccomand2");
        char *hold;
       
        // puts("ccomanda");

        fgets(destrow, MAX_LENGTH, destpointer);
        // puts(comprow);
        // printf("%c\n",comprow[2]);
        //puts(comprow[1]);
        // puts("ccomandb");
        
        char *comma = strchr(destrow, ',');
        // puts(comma);
        int commaindex = comma  - destrow;
        char key[commaindex+1];
        char value[strlen(destrow)];
        // printf("commaindex%i\n", commaindex);
        strncpy(key, destrow, commaindex);
        key[commaindex] = '\0';
        // puts(key);
        // puts("ccommandc");
        strncpy(value, destrow + (commaindex + 1), strlen(destrow));
        
        // uts("ccommandd");
        insertKey(dest, key, value );
        // puts("ccommandc");
         // puts("comp key ");
         // puts(key);
         // puts("\ncomp value ");
         // puts(value);
    }
    fclose(destpointer);
    // jmp = createMap(MAX_SIZE);
    FILE *jmppointer;
    char jmprow[MAX_LENGTH];

    jmppointer = fopen("jmp.txt","r"); // jmp map based on jmp.txt containing jmp keys and value
    // puts("ccomand5");

        
    while (!feof(jmppointer))
    {
        // puts("ccomand2");
        char *hold;
       
        // puts("ccomanda");

        fgets(jmprow, MAX_LENGTH, jmppointer);
        // puts(jmprow);
        // printf("%c\n",comprow[2]);
        //puts(comprow[1]);
        // puts("ccomandb");
        
        char *comma = strchr(jmprow, ',');
        // puts(comma);
        int commaindex = comma  - jmprow;
        char key[commaindex+1];
        char value[strlen(jmprow)];
        // printf("commaindex %i\n", commaindex);
        strncpy(key, jmprow, commaindex);
        key[commaindex] = '\0';
        //puts(key);
        // puts("ccommandc");
        strncpy(value, jmprow + (commaindex + 1), strlen(jmprow));
        
        // uts("ccommandd");
        insertKey(jmp, key, value );
        // puts("ccommandc");
        //puts("jump key ");
         //puts(key);
         //puts("\njump value ");
         //puts(value);
        
        /*if (key == "null") {
            puts("code.c jump null: ");
            puts(value);
        } */
    }
    fclose(jmppointer);
    
    // puts("ccomand7");
    // printf("%i", containsKey(comp, "A"));

    // puts("lookup A: ");
    // puts(lookupKey(comp, "A"));
    // puts(lookupKey(dest, "null"));
    // puts(lookupKey(jmp, "null"));


    
}

// pass one through file to put label names into map with corresponding line number as value
void symbolTable(char *infile) {
    lines = createMap(MAX_SIZE);
    FILE *infilepointer;
    infilepointer = fopen(infile, "r");
    // FILE *outfilepointer;
    // outfilepointer = fopen(outfile, "w");
     // puts("passone1");
    // lines = symbolTable();
   // puts("passone2");
    
    char buffer[MAX_LENGTH];
    
    // puts("passone3");
    int linenumber = 0;
    while (!feof(infilepointer)){
        fgets(buffer, MAX_LENGTH, infilepointer);
        // puts(buffer);
       //puts("passone4");
        if (buffer[0] == '(') {
            // puts("passone5");
            char *closeparen = strchr(buffer, ')');
            // puts("passone6");
            // int parenindex = strlen(buffer) - strlen(closeparen);
            char paren[MAX_LENGTH];
            // puts("passone6a");
            strncpy(paren, buffer + 1, (strlen(buffer) - 3) );
            paren[strlen(buffer) - 3] = '\0';
            // puts("passone6b");
            // puts(paren);
            //printf("%i\n", linenumber);
            // puts("passone7");
            char *line;
            asprintf(&line, "%i", linenumber);
            // puts(line);
            //line[strlen(line)] = '\0';
            // puts(line);
            //puts(paren);
            paren[strcspn(paren, "\r\n")] = 0;
            // printf("%i\n", containsKey(lines, paren));
            insertKey(lines, paren, line);
            // printf("%i\n", containsKey(lines, paren));
            // puts("passone8\n");
            // linenumber+=1;
            free(line);
           
        }
        else {
            linenumber+=1;
            // puts("passone not l");
        }
        // puts("next");
        // fgets(buffer, MAX_LENGTH, infilepointer);
        // puts("next");
    }
    fclose(infilepointer);
    // return lines;
    
    // preset universal keys and values
    insertKey(lines, "SCREEN", "16384");
    insertKey(lines, "KBD", "24576");
    insertKey(lines, "SP", "0");
    insertKey(lines, "LCL", "1");
    insertKey(lines, "ARG", "2");
    insertKey(lines, "THIS", "3");
    insertKey(lines, "THAT", "4");
    insertKey(lines, "R0", "0");
    insertKey(lines, "R1", "1");
    insertKey(lines, "R2", "2");
    insertKey(lines, "R3", "3");
    insertKey(lines, "R4", "4");
    insertKey(lines, "R5", "5");
    insertKey(lines, "R6", "6");
    insertKey(lines, "R7", "7");
    insertKey(lines, "R8", "8");
    insertKey(lines, "R9", "9");
    insertKey(lines, "R10", "10");
    insertKey(lines, "R11", "11");
    insertKey(lines, "R12", "12");
    insertKey(lines, "R13", "13");
    insertKey(lines, "R14", "14");
    insertKey(lines, "R15", "15");
}


