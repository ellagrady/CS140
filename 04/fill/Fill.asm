// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Ella Grady
// February 15, 2022
// CS 140 Spring 2022
// Fill.asm
// runs an infinite loop that listens to the keyboard input. When a key is pressed (any key), the 
// program blackens the screen, i.e. writes "black" in every pixel; the screen should remain fully 
// black as long as the key is pressed. When no key is pressed, the program clears the screen, i.e. 
// writes "white" in every pixel; the screen should remain fully clear as long as no key is pressed


// Put your code here.

(RESET) // start screen at location in r0
  @SCREEN
  D=A
  @0
  M=D

(KEYBOARDCHECK)
  @KBD
  D=M

  @BLACK // jump to BLACK if any key is pressed
  D;JGT

  @WHITE // jump to WHITE if no key is pressed
  D;JEQ

@KEYBOARDCHECK
0;JMP

(BLACK) // sets value of what to fill screen with - black if any key is pressed
  @1
  M=-1

  @CHANGE
  0;JMP

(WHITE) // sets value of what to fill screen with - white if no key is pressed
  @1
  M=0

  @CHANGE
  0;JMP

(CHANGE) // check what to fill screen with (D holds black/white value)
  @1
  D=M

@0 // get address of screen pixel to fill and fill it
A=M
M=D

@0 // increment to next pixel location
D=M+1
@KBD
D=A-D // set A = keyboard value - screen value

@0 
M=M+1 // increment to next pixel location
A=M

@CHANGE // if A=0 leave whole screen as BLACK
D;JGT

@RESET
0;JMP