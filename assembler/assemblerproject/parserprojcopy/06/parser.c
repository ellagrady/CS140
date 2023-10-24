 //
 //  parser.c
 //
 //  translates assembly code into binary
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
// global maps from code.c
 extern map comp; // holds comp values
 extern map dest; // holds dest values
 extern map jmp; // holds jump values
 extern map lines; // holds values for labels

 // cleans a file by removing any whitespaces
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



 
// reads a file - used to copy cleaned version to a temp file
 FILE * readfile(char *outfile, char *infile) {
     FILE *infilepointer;
     infilepointer = fopen(infile, "r");
     FILE *outfilepointer;
     outfilepointer = fopen(outfile, "w");
     // if the file is null returns error and exits
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
     // go through input file line by line
     while (!feof(infilepointer)){
         // removes whitespaces from each line
         removespacesandtabs(outputline, buffer);
         // puts cleaned line into temp file
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

 // first version for checkpoint to print type of command to output file
 void sequenceoutput(char *outfile, char *infile) {
     FILE *infilepointer;
     infilepointer = fopen(infile, "r");
     FILE *outfilepointer;
     outfilepointer = fopen(outfile, "w");
     if (infilepointer == NULL)
     {
         perror("Error: could not open file ");
         exit(1);
     }
     
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
 // used to reverse binary strings
 // based on :
 // https://stackoverflow.com/questions/8534274/is-the-strrev-function-not-available-in-linux/8534275#8534275
 char *strrev(char *str)
 {
     char *pointerone;
     char *pointertwo;

       if (! str || ! *str)
             return str;
     
       for (pointerone = str, pointertwo = str + strlen(str) - 1; pointertwo > pointerone; ++pointerone, --pointertwo)
       {
             *pointerone ^= *pointertwo;
             *pointertwo ^= *pointerone;
             *pointerone ^= *pointertwo;
       }
       return str;
 }
// converts a string in decimal to a string in binary
 void binaryconvert(char *output, char *input) {
     int value = atoi(input);
     
     //puts("value: ");
     //printf("%i", value);
     // puts("output");
     // puts(output);
     // puts(input);
     
     
     int temp = value;
     // printf("%i", temp);
     char binary[MAX_LENGTH];
     int index = 0;
     binary[index]='0';

     // finds binary value
     while(temp!=0)
     {
         // Finds decimal%2 and adds to the binary value
         binary[index] =  (temp % 2)  + '0';
         temp /= 2;
         // puts("T");
         index++;
     }
     binary[index] = '\0';
     // strrev(binary);
     binary[strcspn(binary, "\r\n")] = 0;
     
     char binary16[17];
     // for (int i = 0; i < 16; i++) {
     int i = 0;
     
     // turns binary value into 16-bit binary
     while (i < 16) {
         // for (int j = 0; j < strlen(binary); j++){
         if (i < strlen(binary)) {
             binary16[i] = binary[i];
         }
         else {
             binary16[i] = '0';
         }
         i+=1;
         
     }
     binary16[16] = '\0';
     // reverse binary value
     strrev(binary16);
     binary16[strcspn(binary16, "\r\n")] = 0;
     
     
     //puts(binary);
     // puts(binary16);
     
     // copy binary to output
     strcpy(output, binary16);
     // printf("%lu", strlen(output));
     
     
     
     
 }
// translate function to translate all commands into binary
 void translate(char *outfile, char *infile) {
     FILE *infilepointer;
     infilepointer = fopen(infile, "r");
     FILE *outfilepointer;
     outfilepointer = fopen(outfile, "w");
     int line16start = 16; // used for named variables
     // map table = symbolTable();
     if (infilepointer == NULL)
     {
         perror("Error: could not open file ");
         exit(1);
     }
     
     char buffer[MAX_LENGTH];
     fgets(buffer, MAX_LENGTH, infilepointer);
     //puts("BUFFER: ");
     //puts(buffer);
     // int linenumber = 0;
    //  passone(infile);
     while (!feof(infilepointer)){
         // puts(buffer);
         if (buffer[0] == '@') {
             
             // char *end = strchr(buffer, '\0');
             char command[MAX_LENGTH]; // holds cleaned command

             // if the a-command is a number convert number directly to binary
             if(isdigit(buffer[1])!=0) {
                 // puts("acommand");
                 strncpy(command, buffer + 1, strlen(buffer));
                 // command[strcspn(command, "\r\n")] = 0;
                 // puts("command: ");
                 // puts(command);
                 char binary[MAX_LENGTH];
                 // puts("binary: ");
                 // puts(binary);
                 binaryconvert(binary, command);// binaryconvert(command);
                 binary[strcspn(binary, "\r\n")] = 0;
                 fputs(binary, outfilepointer);
                 fputs("\n\0", outfilepointer);
                 
                  // puts(binary);
             }
             
             // otherwise if command has a name, check if key is in lines table
             // if in table use that value, otherwise insert into lines with
             // a value, starting at 16 for the first variable
             else {
                 // puts("ignore");
                char binary[MAX_LENGTH];
                strncpy(command, buffer + 1, strlen(buffer));
                command[strlen(command)] ='\0';
                 
                command[strcspn(command, "\r\n")] = 0;
                 // check if command is already in lines,
                 // if is in lines convert value to binary
                if (containsKey(lines, command) != -1) {
                    // puts("a");
                    char *value = lookupKey(lines, command);
                    // puts(value);
                    binaryconvert(binary, value);
                    // puts("BINARY: ");
                    // puts(binary);
                    binary[strlen(binary)] = '\0';
                    binary[strcspn(binary, "\r\n")] = 0;
                    // binary[strcspn(binary, "\r\n")] = 0;
                    fputs(binary, outfilepointer);
                    fputs("\n\0", outfilepointer);
                     
                }
                 // otherwise insert key and value into array
                 // then find binary conversion of value based on start at 16
                else {
                    char *line16;
                    // puts("one");
                    asprintf(&line16, "%i", line16start);
                    //line16[0] = line16start;
                    // puts(line16);
                    // printf("two %s\n", line16);
                    
                    // puts(line16);
                    // puts("three");
                    insertKey(lines, command, line16);
                    // puts("four");
                    char binary[MAX_LENGTH];
                    // puts("five");
                    binaryconvert(binary, line16);
                    // puts("BINARY");
                    // puts(binary);
                    binary[strlen(binary)] = '\0';
                    binary[strcspn(binary, "\r\n")] = 0;
                    fputs(binary, outfilepointer);
                    fputs("\n\0", outfilepointer);
                    line16start++;
                    free(line16);
                    
                }
                 
                
                 
             }
             
         }
         // if command is a label do nothing
         else if (buffer[0] == '(') {
              printf("%s", "");
             // passone(outfile, infile);
             
            
         }
         // if command is c-command translate using comp, dest, and jmp maps
         else {
             
             char final[MAX_LENGTH];
             char destkey[MAX_LENGTH];
             char compkey[MAX_LENGTH];
             char jumpkey[MAX_LENGTH];
             strcpy(final, "\0");
             // printf("%lu\n", strlen(final));
             strcpy(destkey, "\0");
             strcpy(compkey, "\0");
             strcpy(jumpkey, "\0");
             // puts("ccommand1");
             // puts(buffer);
             char *equal = strchr(buffer, '='); // find where = sign is in command
             int equalindex = 0;
             // if the equal sign exists get dest part from before the equal sign
             if (equal != NULL) {
                // puts("ccommand2");
                 
                 equalindex = strlen(buffer) - strlen(equal);
                 // printf("%i\n", equalindex);
                 // char destkeytemp[equalindex];
                  strncpy(destkey, buffer, equalindex + 1);
                 // destkey[0] = destkeytemp[0];
                // destkey[1] = '\0';
                  // strncpy(destkeytemp, buffer + 0, equalindex);
                  /* int i = 0;
                 while (i < equalindex) {
                     destkey[i] = destkeytemp[i];
                     i+=1;
                 } */
                 destkey[equalindex] = '\0';
                 destkey[strcspn(destkey, "\r\n")] = 0;
                 // destkey[strlen(destkey) - 1] = '\0';
                 // puts(destkey);
                 
                 
                 // strcpy(destkey, "\0");
             }
             
             char *semi = strchr(buffer, ';'); // find where ; sign is in command
             int semiindex = 0;
             // if ; exists get jump part from after ;
             if (semi != NULL) {
                 // puts("ccommand3");
                 semiindex = strlen(buffer)  - strlen(semi);
                 int endlength = strlen(buffer) - semiindex;
                 strncpy(jumpkey, buffer + (semiindex + 1), endlength);
                 jumpkey[strlen(jumpkey) - 1] = '\0';
                 jumpkey[strcspn(jumpkey, "\r\n")] = 0;
                 // puts(jumpkey);
                 // strcpy(jumpkey, "\0");
             }
             // if = is not in command and ; is, get comp part from before ;
             if (equal == NULL && semi != NULL) {
                 // puts("ccommand4");
                 strcpy(destkey,  "\0");
                 destkey[strlen(destkey)] = '\0';
                 // strcpy(compkey, "\0");
                 // puts(buffer);
                 // puts(compkey);
                 // printf("%i\n", semiindex);
                 strncpy(compkey, buffer, semiindex);
                 compkey[semiindex] = '\0';
                 compkey[strcspn(compkey, "\r\n")] = 0;
                 // puts(compkey);
             }
             // if = is in command and ; is not, get comp part from after =
             else if (equal != NULL && semi == NULL) {
                 // puts("ccommand5");
                 strcpy(jumpkey , "\0");
                 // strcpy(compkey, "");
                 jumpkey[strlen(jumpkey) - 1] = '\0';
                 // puts("ccommanda");
                 strncpy(compkey, buffer + (equalindex +1), strlen(buffer) - 1);
                 compkey[strlen(compkey)] = '\0';
                 compkey[strcspn(compkey, "\r\n")] = 0;
                 // puts("ccommandb");
                // puts(compkey);
                 // strcpy(compkey, "\0");
             }
             // otherwise both = and ; are there get comp part from between = and ;
             else {
                 // puts("ccommand6");
                 strncpy(compkey, buffer + (equalindex +1), strlen(buffer) - semiindex );
                 compkey[strlen(compkey)] = '\0';
                 compkey[strcspn(compkey, "\r\n")] = 0;
                 
                 // strcpy(compkey, "\0");
             }
             
             // puts("ccommand7");
             char destvalue[MAX_LENGTH];
             // puts("ccommand7a");
             char compvalue[MAX_LENGTH];
             // puts("ccommand7b");
             char jumpvalue[MAX_LENGTH];
             strcpy(destvalue, "\0");
             strcpy(compvalue, "\0");
             strcpy(jumpvalue, "\0");
             
             // puts("ccommand7c");
             // if the destkey exists find the value in dest
             if (strlen(destkey) != 0) {
              //    puts("ccommand8");
                 strcpy(destvalue, lookupKey(dest, destkey));
              //   puts(destvalue);
                 destvalue[strlen(destvalue)] = '\0';
               //   puts("ccommand8a");
             }
             // if destkey does not exist set key to null and find value of null in dest
             else {
                 strcpy(destkey, "null");
                 strcpy(destvalue, lookupKey(dest, destkey));
                 // puts(destvalue);
                 destvalue[strlen(destvalue)] = '\0';
             }
             // if jumpkey does exist find value in jmp
             if (strlen(jumpkey) != 0) {
                 // puts("ccommand9");
                 strcpy(jumpvalue , lookupKey(jmp, jumpkey));
                 // puts(jumpvalue);
                 jumpvalue[strlen(jumpvalue)] = '\0';
                 // puts("ccommand9a");
             }
             // if jumpkey does not exist set key to null and find value of null in jmp
             else {
                 strcpy(jumpkey, "null");
                 strcpy(jumpvalue, lookupKey(jmp, jumpkey));
                 // puts("jump null: ");
                 // puts(jumpvalue);
                 jumpvalue[strlen(jumpvalue)] = '\0';
             }
             
              // puts("ccommand10");
              // puts(compkey);
             compkey[strcspn(compkey, "\r\n")] = 0;
              // printf("%i\n",containsKey(comp, compkey));
              // printf("%i\n",containsKey(comp, "M"));
              // puts(lookupKey(comp, compkey));
             
             // find value of compkey in comp
             strcpy(compvalue , lookupKey(comp, compkey));
             compvalue[strlen(compvalue) - 1] = '\0';
             
             compvalue[strcspn(compvalue, "\r\n")] = 0;
             destvalue[strcspn(destvalue, "\r\n")] = 0;
             jumpvalue[strcspn(jumpvalue, "\r\n")] = 0;
             // puts("ccommand11");
             
             // start final c-command binary translation with 111
             strcpy(final, "111");
             
             // concatanate compvalue to the final translation
             strcat(final, compvalue);
             // printf("destvalue %s\n", destvalue);
             // printf("compvalue %s\n", compvalue);
             //printf("jumpvalue %s\n", jumpvalue);
             // printf("final1 %s\n", final);
             
             // add dest value to final
             strcat(final, destvalue);
            // printf("final2 %s\n", final);
             
             // add jumpvalue to final
             strcat(final, jumpvalue);
            // printf("final3 %s\n", final);
             final[(strlen(final))] = '\0';
             final[strcspn(final, "\r\n")] = 0;
             
             fputs(final, outfilepointer);
             fputs("\n\0", outfilepointer);
             //puts("final: ");
              //puts(final);
             // puts(final);
             
             // puts("ccommand");
             
         }
         fgets(buffer, MAX_LENGTH, infilepointer);
         
     }
     fclose(infilepointer);
     fclose(outfilepointer);
     
 }

