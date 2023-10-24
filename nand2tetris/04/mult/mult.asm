// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
//
// This program only needs to handle arguments that satisfy
// R0 >= 0, R1 >= 0, and R0*R1 < 32768.

// Ella Grady
// February 15, 2022
// CS 140 Spring 2022
// Mult.asm
// computes the value R0*R1 and stores the result in R2

// Put your code here.
@R2 //starts with r2 at 0
M=0

@R0 // jump to NEXT if r0 > 0
D=M
@NEXT
D;JGT

@END // if did not jump go to END
0;JMP

// adds r1 to r2 and decrements r0 by 1
// if r0 > 0, do NEXT again
(NEXT) 

   @R2 // get r2
   D=M

   @R1 // add r1 to r2
   D=D+M

   @R2 // put result back to r2
   M=D

   @R0 // decrement r0 by 1
   D=M-1
   M=D

   @NEXT // if r0 still > 0 repeat NEXT loop
   D;JGT

(END)
   @END
   0;JMP