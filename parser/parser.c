/* //
//  parser.c
//  
//
//  Created by Ella Grady on 2/23/22.
//

#include <stdio.h>
#include "parser.h"
#include <ctype.h>
#include <stdlib.h>

#include "code.h"

#include <string.h>

#define MAX_LENGTH 200
extern map comp;
extern map dest;
extern map jmp;

/* void mystrcpy(char *out, char *in) {
    
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



/* int removespacesandtabspointer(char *out, char *in) {
    
    
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
    infilepointer = fopen(infile, "r");
    FILE *outfilepointer;
    outfilepointer = fopen(outfile, "w+");
    if (infilepointer == NULL)
    {
        perror("Error: could not open file ");
        exit(1);
    }
    
    char buffer[MAX_LENGTH];
    // char templine[MAX_LENGTH];
    char outputline[MAX_LENGTH];
    // fputs("hello", outfilepointer);
    fgets(buffer, MAX_LENGTH, infilepointer );
    while (!feof(infilepointer)){
        
        removespacesandtabs(outputline, buffer);
        
        if(strlen(outputline) != 0 && outputline[0] != '\n') {
            fputs(outputline, outfilepointer);
            //fputs('\0', outfilepointer);
            fputs("\n\0", outfilepointer);
        }
        fgets(buffer, MAX_LENGTH, infilepointer );
    }
    // fputs("next", outfilepointer);
    
    // close the file
    fclose(infilepointer);
    fclose(outfilepointer);
    return outfilepointer;
}

void sequenceoutput(char *outfile, char *infile) {
    FILE *infilepointer;
    infilepointer = fopen(infile, "r");
    FILE *outfilepointer;
    outfilepointer = fopen(outfile, "w");

    
    char buffer[MAX_LENGTH];
    fgets(buffer, MAX_LENGTH, infilepointer);
    // fputs("hello", outfilepointer);
    while (!feof(infilepointer)){
        // puts("hello");
        //fputs("hello", outfilepointer);
        if (buffer[0] == '@') {
            // puts("A-Command");
            fputs("A_COMMAND", outfilepointer);
            //fputs('\0', outfilepointer);
            fputs("\n\0", outfilepointer);
        }
        else if (buffer[0] == '(') {
            // puts("L-Command");
            fputs("L_COMMAND", outfilepointer);
            //fputs('\0', outfilepointer);
            fputs("\n\0", outfilepointer);
        }
        else {
            // puts("C-Command");
            fputs("C_COMMAND", outfilepointer);
            //fputs('\0', outfilepointer);
            fputs("\n\0", outfilepointer);
        }
        fgets(buffer, MAX_LENGTH, infilepointer);
    }
    // puts("check", outfilepointer);
    fclose(infilepointer);
    fclose(outfilepointer);
}
// https://stackoverflow.com/questions/8534274/is-the-strrev-function-not-available-in-linux/8534275#8534275
char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
void binaryconvert(char *output, char *input) {
    int value = atoi(input);
    
    //puts("value: ");
    //printf("%i", value);
    // puts("output");
    // puts(output);
    // puts(input);
    // long long bin = 0;
  
    // return bin;
    int temp = value;
    // printf("%i", temp);
    char binary[MAX_LENGTH];
    int index = 0;
    binary[index]='0';


    while(temp!=0)
    {
        /* Finds decimal%2 and adds to the binary value
        binary[index] =  (temp % 2)  + '0';
        temp /= 2;
        // puts("T");
        index++;
    }
    binary[index] = '\0';
    // strrev(binary);
    
    char binary16[17];
    for (int i = 0; i < 16; i++) {
        // for (int j = 0; j < strlen(binary); j++){
        if (i < strlen(binary)) {
            binary16[i] = binary[i];
        }
        else {
            binary16[i] = '0';
        }
        
    }
    binary[16] = '\0';
    strrev(binary16);
    /* Reverse the binary value found
    
    //puts(binary);
    // puts(binary16);
    strcpy(output, binary16);
    // puts(output);
    // printf("%lu", strlen(output));
    
    
    
    
}
void translate(char *outfile, char *infile) {
    FILE *infilepointer;
    infilepointer = fopen(infile, "r");
    FILE *outfilepointer;
    outfilepointer = fopen(outfile, "w");

    // map table = symbolTable();
    
    char buffer[MAX_LENGTH];
    fgets(buffer, MAX_LENGTH, infilepointer);
    //puts("BUFFER: ");
    //puts(buffer);
    // int linenumber = 0;
    while (!feof(infilepointer)){
        if (buffer[0] == '@') {
            // char *end = strchr(buffer, '\0');
            char command[MAX_LENGTH];
            if(isdigit(buffer[1])==1) {
                strncpy(command, buffer + 1, strlen(buffer));
                // puts("command: ");
                // puts(command);
                char binary[MAX_LENGTH];
                // puts("binary: ");
                // puts(binary);
                binaryconvert(binary, command);// binaryconvert(command);
                fputs(binary, outfilepointer);
                fputs("\n\0", outfilepointer);
                 // puts(binary);
            }
            
        }
        else if (buffer[0] == '(') {
            // puts("L-Command");
            fputs("L_COMMAND", outfilepointer);
            //fputs('\0', outfilepointer);
            fputs("\n\0", outfilepointer);
        }
        else {/*
            char final[MAX_LENGTH];
            char destkey[MAX_LENGTH];
            char compkey[MAX_LENGTH];
            char jumpkey[MAX_LENGTH];
            // puts("ccommand1");
            
            char *equal = strchr(buffer, '=');
            int equalindex = 0;
            if (equal != NULL) {
                // puts("ccommand2");
                char destkeytemp[MAX_LENGTH];
                equalindex = strlen(buffer) - strlen(equal);
                // printf("%i\n", equalindex);
                strncpy(destkeytemp, buffer + 0, equalindex);
                destkey[0] = destkeytemp[0];
                destkey[1] = '\0';
                // puts(destkey);
                
                
                // strcpy(destkey, "\0");
            }
            
            char *semi = strchr(buffer, ';');
            int semiindex = 0;
            if (semi != NULL) {
                // puts("ccommand3");
                semiindex = strlen(buffer)  - strlen(semi);
                int endlength = strlen(buffer) - semiindex;
                strncpy(jumpkey, buffer + (semiindex + 1), endlength);
                jumpkey[strlen(jumpkey) - 1] = '\0';
                // puts(jumpkey);
                // strcpy(jumpkey, "\0");
            }
            
            if (equal == NULL && semi != NULL) {
                // puts("ccommand4");
                strcpy(destkey,  "");
                strncpy(compkey, buffer, semiindex);
                compkey[strlen(compkey) - 1] = '\0';
            }
            else if (equal != NULL && semi == NULL) {
                // puts("ccommand5");
                strcpy(jumpkey , "");
                jumpkey[strlen(jumpkey) - 1] = '\0';
                // puts("ccommanda");
                strncpy(compkey, buffer + (equalindex +1), strlen(buffer) - 1);
                compkey[strlen(compkey) - 1] = '\0';
                // puts("ccommandb");
                // strcpy(compkey, "\0");
            }
            else {
                // puts("ccommand6");
                strncpy(compkey, buffer + (equalindex +1), strlen(buffer) - semiindex);
                compkey[strlen(compkey)] = '\0';
                
                // strcpy(compkey, "\0");
            }
            
            // puts("ccommand7");
            char destvalue[MAX_LENGTH];
            // puts("ccommand7a");
            char compvalue[MAX_LENGTH];
            // puts("ccommand7b");
            char jumpvalue[MAX_LENGTH];
            // puts("ccommand7c");
            if (strlen(destkey) != 0) {
               //  puts("ccommand8");
                strcpy(destvalue, lookupKey(dest, destkey));
                // puts(destvalue);
                destvalue[strlen(destvalue)] = '\0';
                // puts("ccommand8a");
            }
            else {
                strcpy(destkey, "null");
                strcpy(destvalue, lookupKey(dest, destkey));
                // puts(destvalue);
                destvalue[strlen(destvalue)] = '\0';
            }
            if (strlen(jumpkey) != 0) {
                // puts("ccommand9");
                strcpy(jumpvalue , lookupKey(jmp, jumpkey));
                // puts(jumpvalue);
                jumpvalue[strlen(jumpvalue)] = '\0';
                // puts("ccommand9a");
            }
            else {
                strcpy(jumpkey, "null");
                strcpy(jumpvalue, lookupKey(jmp, jumpkey));
                //puts("jump null: ");
                //puts(jumpvalue);
                jumpvalue[strlen(jumpvalue)] = '\0';
            }
            
            // puts("ccommand10");
            // puts(compkey);
            // printf("%i\n",containsKey(comp, compkey));
            // printf("%i\n",containsKey(comp, "A"));
            // puts(lookupKey(comp, compkey));
            strcpy(compvalue , lookupKey(comp, compkey));
            // compvalue[strlen(compvalue)] = '\0';
            
            compvalue[strcspn(compvalue, "\r\n")] = 0;
            destvalue[strcspn(destvalue, "\r\n")] = 0;
            jumpvalue[strcspn(jumpvalue, "\r\n")] = 0;
            // puts("ccommand11");
            strcpy(final, "111");
            strcat(final, compvalue); //, strlen(destvalue));
            //printf("destvalue %s\n", destvalue);
            //printf("compvalue %s\n", compvalue);
            //printf("jumpvalue %s\n", jumpvalue);
            // printf("final1 %s\n", final);
            strcat(final, destvalue); // strlen(compvalue));
            // printf("final2 %s\n", final);
            strcat(final, jumpvalue); //, strlen(jumpvalue));
            // printf("final3 %s\n", final);
            final[(strlen(final))] = '\0';
            fputs(final, outfilepointer);
            fputs("\n\0", outfilepointer);
            //puts("final: ");
            //puts(final);
            // puts(final);
            
            
        }
        fgets(buffer, MAX_LENGTH, infilepointer);
    }
}
map passone(char *outfile, char *infile) {
    FILE *infilepointer;
    infilepointer = fopen(infile, "r");
    FILE *outfilepointer;
    outfilepointer = fopen(outfile, "w");

    map lines = symbolTable();
    
    char buffer[MAX_LENGTH];
    fgets(buffer, MAX_LENGTH, infilepointer);
    int linenumber = 0;
    while (!feof(infilepointer)){
        if (buffer[0] == '(') {
            char *closeparen = strchr(buffer, ')');
            // int parenindex = closeparen - buffer;
            char *paren;
            strncpy(paren, buffer + 1, strlen(buffer) - 1 );
            insertKey(lines, paren, linenumber);
            linenumber++;
    
        }
    }
} */
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


 #include "code.h"

 #include <string.h>

 #define MAX_LENGTH 200
#define MAP_SIZE 5000
 extern map comp;
 extern map dest;
 extern map jmp;
 extern map lines;

 /* void mystrcpy(char *out, char *in) {
     
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
 }*/
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



 /* int removespacesandtabspointer(char *out, char *in) {
     
     
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
 }*/
  
 FILE * readfile(char *outfile, char *infile) {
     FILE *infilepointer;
     infilepointer = fopen(infile, "r");
     FILE *outfilepointer;
     outfilepointer = fopen(outfile, "w+");
     if (infilepointer == NULL)
     {
         perror("Error: could not open file ");
         exit(1);
     }
     
     char buffer[MAX_LENGTH];
     // char templine[MAX_LENGTH];
     char outputline[MAX_LENGTH];
     // fputs("hello", outfilepointer);
     fgets(buffer, MAX_LENGTH, infilepointer );
     while (!feof(infilepointer)){
         
         removespacesandtabs(outputline, buffer);
         
         if(strlen(outputline) != 0 && outputline[0] != '\n') {
             fputs(outputline, outfilepointer);
             //fputs('\0', outfilepointer);
             fputs("\n\0", outfilepointer);
         }
         fgets(buffer, MAX_LENGTH, infilepointer );
     }
     // fputs("next", outfilepointer);
     
     // close the file
     fclose(infilepointer);
     fclose(outfilepointer);
     return outfilepointer;
 }

 void sequenceoutput(char *outfile, char *infile) {
     FILE *infilepointer;
     infilepointer = fopen(infile, "r");
     FILE *outfilepointer;
     outfilepointer = fopen(outfile, "w");

     
     char buffer[MAX_LENGTH];
     fgets(buffer, MAX_LENGTH, infilepointer);
     // fputs("hello", outfilepointer);
     while (!feof(infilepointer)){
         // puts("hello");
         //fputs("hello", outfilepointer);
         if (buffer[0] == '@') {
             // puts("A-Command");
             fputs("A_COMMAND", outfilepointer);
             //fputs('\0', outfilepointer);
             fputs("\n\0", outfilepointer);
         }
         else if (buffer[0] == '(') {
             // puts("L-Command");
             fputs("L_COMMAND", outfilepointer);
             //fputs('\0', outfilepointer);
             fputs("\n\0", outfilepointer);
         }
         else {
             // puts("C-Command");
             fputs("C_COMMAND", outfilepointer);
             //fputs('\0', outfilepointer);
             fputs("\n\0", outfilepointer);
         }
         fgets(buffer, MAX_LENGTH, infilepointer);
     }
     // puts("check", outfilepointer);
     fclose(infilepointer);
     fclose(outfilepointer);
 }
 // https://stackoverflow.com/questions/8534274/is-the-strrev-function-not-available-in-linux/8534275#8534275
 char *strrev(char *str)
 {
       char *p1, *p2;

       if (! str || ! *str)
             return str;
       for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
       {
             *p1 ^= *p2;
             *p2 ^= *p1;
             *p1 ^= *p2;
       }
       return str;
 }
 void binaryconvert(char *output, char *input) {
     int value = atoi(input);
     
     //puts("value: ");
     //printf("%i", value);
     // puts("output");
     // puts(output);
     // puts(input);
     // long long bin = 0;
   
     // return bin;
     int temp = value;
     // printf("%i", temp);
     char binary[MAX_LENGTH];
     int index = 0;
     binary[index]='0';


     while(temp!=0)
     {
         /* Finds decimal%2 and adds to the binary value */
         binary[index] =  (temp % 2)  + '0';
         temp /= 2;
         // puts("T");
         index++;
     }
     binary[index] = '\0';
     // strrev(binary);
     
     char binary16[17];
     for (int i = 0; i < 16; i++) {
         // for (int j = 0; j < strlen(binary); j++){
         if (i < strlen(binary)) {
             binary16[i] = binary[i];
         }
         else {
             binary16[i] = '0';
         }
         
     }
     binary[16] = '\0';
     strrev(binary16);
     /* Reverse the binary value found */
     
     //puts(binary);
     // puts(binary16);
     strcpy(output, binary16);
     // puts(output);
     // printf("%lu", strlen(output));
     
     
     
     
 }
 void translate(char *outfile, char *infile) {
     FILE *infilepointer;
     infilepointer = fopen(infile, "r");
     FILE *outfilepointer;
     outfilepointer = fopen(outfile, "w");
     int line16start = 16;
     // map table = symbolTable();
     
     char buffer[MAX_LENGTH];
     fgets(buffer, MAX_LENGTH, infilepointer);
     //puts("BUFFER: ");
     //puts(buffer);
     // int linenumber = 0;
    //  passone(infile);
     while (!feof(infilepointer)){
         // puts("step");
         puts(buffer);
         if (buffer[0] == '@') {
             // char *end = strchr(buffer, '\0');
             char command[MAX_LENGTH];
             
             if(isdigit(buffer[1])!=0) {
                 puts("acommand");
                  strncpy(command, buffer + 1, strlen(buffer));
                 // puts("command: ");
                 // puts(command);
                 char binary[MAX_LENGTH];
                 // puts("binary: ");
                 // puts(binary);
                 binaryconvert(binary, command);// binaryconvert(command);
                 fputs(binary, outfilepointer);
                 fputs("\n\0", outfilepointer);
                 
                  // puts(binary);
             }
             else if (buffer[1] == 'R') {
                 strncpy(command, buffer + 2, strlen(buffer));
                // puts("command: ");
                // puts(command);
                char binary[MAX_LENGTH];
                // puts("binary: ");
                // puts(binary);
                binaryconvert(binary, command);// binaryconvert(command);
                fputs(binary, outfilepointer);
                fputs("\n\0", outfilepointer);
             }
             else {
                 puts("ignore");
                char binary[MAX_LENGTH];
                strncpy(command, buffer + 1, strlen(buffer));
                 command[strlen(command)] ='\0';
                 puts(command);
                 insertKey(lines, "A", "A");
                 
                 printf("%i\n", containsKey(lines, "A"));
                if (containsKey(lines, command) != -1) {
                    puts("a");
                    char *value = lookupKey(lines, command);
                    puts(value);
                    binaryconvert(binary, value);
                    puts(binary);
                    fputs(binary, outfilepointer);
                    fputs("\n\0", outfilepointer);
                     
                }
                else {
                    char line16[MAX_LENGTH];
                    puts("one");
                    sprintf(line16, "%i", line16start);
                    //line16[0] = line16start;
                    puts(line16);
                    printf("two %s\n", line16);
                    line16[strlen(line16)] ='\0';
                    puts("three");
                    insertKey(lines, command, line16);
                    puts("four");
                    char binary[MAX_LENGTH];
                    puts("five");
                    binaryconvert(binary, line16);
                    // strcpy(binary, passtwonumber(line16));
                    puts("six");
                    puts(binary);
                    fputs(binary, outfilepointer);
                    fputs("\n\0", outfilepointer);
                    line16start++;
                    
                }
                 
                // puts("command: ");
                // puts(command);
               // char binary[MAX_LENGTH];
                // puts("binary: ");
                // puts(binary);
                //binaryconvert(binary, command);// binaryconvert(command);
                //fputs(binary, outfilepointer);
                //fputs("\n\0", outfilepointer);
                
                 
             }
             
         }
         /* if (buffer[0] == '@') {
             puts(buffer);
             // if (isdigit(buffer[1])) {
                 char binary[MAX_LENGTH];
                 
                 // char *end = strchr(buffer, '\0');
                 char command[MAX_LENGTH];
                 
                 strncpy(command, buffer + 1, strlen(buffer));
                 // puts("command: ");
                 // puts(command);
                 // char binary[MAX_LENGTH];
                 // puts("binary: ");
                 // puts(binary);
                 binaryconvert(binary, command);// binaryconvert(command);
                 // puts(binary);
                 fputs(binary, outfilepointer);
                 fputs("\n\0", outfilepointer);
                 // puts(binary);
             // }
             /*else {
                 char command[MAX_LENGTH];
                 strncpy(command, buffer + 1, strlen(buffer));
                 if (containsKey(lines, command) != -1) {
                     char *value = lookupKey(lines, command);
                     char binary[MAX_LENGTH];
                     binaryconvert(binary, value);
                      //puts(binary);
                     fputs(binary, outfilepointer);
                     fputs("\n\0", outfilepointer);
                 }
                 else {
                     insertKey(lines, command, line16start);
                     char binary[MAX_LENGTH];
                     
                     strcpy(binary, passtwonumber(line16start));
                     puts(binary);
                     fputs(binary, outfilepointer);
                     fputs("\n\0", outfilepointer);
                     
                 }
                 
             }*/
         
         else if (buffer[0] == '(') {
             // puts("lcommand");
             // passone(outfile, infile);
             continue;
            
         }
         else {
             
             char final[MAX_LENGTH];
             char destkey[MAX_LENGTH];
             char compkey[MAX_LENGTH];
             char jumpkey[MAX_LENGTH];
              puts("ccommand1");
             
             char *equal = strchr(buffer, '=');
             int equalindex = 0;
             if (equal != NULL) {
                  puts("ccommand2");
                 char destkeytemp[MAX_LENGTH];
                 equalindex = strlen(buffer) - strlen(equal);
                  printf("%i\n", equalindex);
                 strncpy(destkeytemp, buffer + 0, equalindex);
                 destkey[0] = destkeytemp[0];
                 destkey[1] = '\0';
                 puts(destkey);
                 
                 
                 // strcpy(destkey, "\0");
             }
             
             char *semi = strchr(buffer, ';');
             int semiindex = 0;
             if (semi != NULL) {
                 puts("ccommand3");
                 semiindex = strlen(buffer)  - strlen(semi);
                 int endlength = strlen(buffer) - semiindex;
                 strncpy(jumpkey, buffer + (semiindex + 1), endlength);
                 jumpkey[strlen(jumpkey) - 1] = '\0';
                 puts(jumpkey);
                 // strcpy(jumpkey, "\0");
             }
             
             if (equal == NULL && semi != NULL) {
                  puts("ccommand4");
                 strcpy(destkey,  "");
                 strncpy(compkey, buffer, semiindex);
                 compkey[strlen(compkey)] = '\0';
             }
             else if (equal != NULL && semi == NULL) {
                  puts("ccommand5");
                 strcpy(jumpkey , "");
                 jumpkey[strlen(jumpkey) - 1] = '\0';
                  puts("ccommanda");
                 strncpy(compkey, buffer + (equalindex +1), strlen(buffer) - 1);
                 compkey[strlen(compkey)] = '\0';
                  puts("ccommandb");
                 puts(compkey);
                 // strcpy(compkey, "\0");
             }
             else {
                  puts("ccommand6");
                 strncpy(compkey, buffer + (equalindex +1), strlen(buffer) - semiindex );
                 compkey[strlen(compkey)] = '\0';
                 
                 // strcpy(compkey, "\0");
             }
             
              puts("ccommand7");
             char destvalue[MAX_LENGTH];
              puts("ccommand7a");
             char compvalue[MAX_LENGTH];
              puts("ccommand7b");
             char jumpvalue[MAX_LENGTH];
              puts("ccommand7c");
             if (strlen(destkey) != 0) {
                  puts("ccommand8");
                 strcpy(destvalue, lookupKey(dest, destkey));
                 puts(destvalue);
                 destvalue[strlen(destvalue)] = '\0';
                  puts("ccommand8a");
             }
             else {
                 strcpy(destkey, "null");
                 strcpy(destvalue, lookupKey(dest, destkey));
                  puts(destvalue);
                 destvalue[strlen(destvalue)] = '\0';
             }
             if (strlen(jumpkey) != 0) {
                  puts("ccommand9");
                 strcpy(jumpvalue , lookupKey(jmp, jumpkey));
                  puts(jumpvalue);
                 jumpvalue[strlen(jumpvalue)] = '\0';
                  puts("ccommand9a");
             }
             else {
                 strcpy(jumpkey, "null");
                 strcpy(jumpvalue, lookupKey(jmp, jumpkey));
                 puts("jump null: ");
                 puts(jumpvalue);
                 jumpvalue[strlen(jumpvalue)] = '\0';
             }
             
              puts("ccommand10");
              puts(compkey);
             compkey[strcspn(compkey, "\r\n")] = 0;
              printf("%i\n",containsKey(comp, compkey));
              printf("%i\n",containsKey(comp, "M"));
              puts(lookupKey(comp, compkey));
             strcpy(compvalue , lookupKey(comp, compkey));
              compvalue[strlen(compvalue)] = '\0';
             
             compvalue[strcspn(compvalue, "\r\n")] = 0;
             destvalue[strcspn(destvalue, "\r\n")] = 0;
             jumpvalue[strcspn(jumpvalue, "\r\n")] = 0;
              puts("ccommand11");
             strcpy(final, "111");
             strcat(final, compvalue); //, strlen(destvalue));
             printf("destvalue %s\n", destvalue);
             printf("compvalue %s\n", compvalue);
             printf("jumpvalue %s\n", jumpvalue);
              printf("final1 %s\n", final);
             strcat(final, destvalue); // strlen(compvalue));
            printf("final2 %s\n", final);
             strcat(final, jumpvalue); //, strlen(jumpvalue));
              printf("final3 %s\n", final);
             final[(strlen(final))] = '\0';
             fputs(final, outfilepointer);
             fputs("\n\0", outfilepointer);
             puts("final: ");
             puts(final);
             // puts(final);
             
             puts("ccommand");
             
         }
         fgets(buffer, MAX_LENGTH, infilepointer);
         
     }
 }
 /* char* passtwonumber (char *buffer) {
     // char *end = strchr(buffer, '\0');
     char command[MAX_LENGTH];
     
     strncpy(command, buffer + 1, strlen(buffer));
     // puts("command: ");
     // puts(command);
     char binary[MAX_LENGTH];
     // puts("binary: ");
     // puts(binary);
     binaryconvert(binary, command);// binaryconvert(command);
     return binary;
     //fputs(binary, outfilepointer);
     //fputs("\n\0", outfilepointer);
     // puts(binary);
     
     
 } */


 /* void passone(char *infile) {
     FILE *infilepointer;
     infilepointer = fopen(infile, "r");
     // FILE *outfilepointer;
     // outfilepointer = fopen(outfile, "w");
      puts("passone1");
     // lines = symbolTable();
    puts("passone2");
     
     char buffer[MAX_LENGTH];
     
     puts("passone3");
     int linenumber = 0;
     while (!feof(infilepointer)){
         fgets(buffer, MAX_LENGTH, infilepointer);
         
        //puts("passone4");
         if (buffer[0] == '(') {
             puts("passone5");
             char *closeparen = strchr(buffer, ')');
             puts("passone6");
             // int parenindex = strlen(buffer) - strlen(closeparen);
             char paren[MAX_LENGTH];
             puts("passone6a");
             strncpy(paren, buffer + 1, (strlen(buffer) - 3) );
             paren[strlen(paren)] = '\0';
             puts("passone6b");
             puts(paren);
             //printf("%i\n", linenumber);
             puts("passone7");
             char *line;
             asprintf(&line, "%i", linenumber);
             // puts(line);
             //line[strlen(line)] = '\0';
             puts(line);
             //puts(paren);
             printf("%i\n", containsKey(lines, paren));
             insertKey(lines, paren, line);
             puts("passone8\n");
             linenumber+=1;
            
         }
         else {
             linenumber+=1;
            puts("passone not l");
         }
         // puts("next");
         // fgets(buffer, MAX_LENGTH, infilepointer);
         // puts("next");
     }
     fclose(infilepointer);
     // return lines;
 }*/







