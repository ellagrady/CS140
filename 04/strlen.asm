
// Ella Grady
// February 15, 2022
// CS 140 Spring 2022
// strlen.asm
// calculate the length of a string and store the result in a memory location


//strlen = 0;
// if string[i] != 0
  // strlen += 1


@length
M=0

@i
M=1

(LOOP)
  @100
  D=M
  
  @END
  D;JEQ
  
  @length
  M=D+1

  @LOOP
  0;JMP



(END)
   @END
   0;JMP // Infinite loop


