// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/mult/Mult.tst

load strlen.hack,
output-file strlen.out,
compare-to strlen.cmp,
output-list RAM[16]%D2.6.2;

// Should output 7
set RAM[100] 4,   // Set test arguments
set RAM[101] 5,
set RAM[102] 6; 
set RAM[103] 6; 
set RAM[104] 6; 
set RAM[105] 6; 
set RAM[106] 6; 
set RAM[107] 0;
repeat 200 {
  ticktock;
}
output;


// should output 0
set PC 0,
set RAM[100] 0,   // Set test arguments
set RAM[101] 5,
set RAM[102] 6; 
set RAM[103] 6; 
set RAM[104] 6; 
set RAM[105] 6; 
set RAM[106] 6; 

repeat 50 {
  ticktock;
}
output;

// should output 1
set PC 0,
set RAM[100] 5,   // Set test arguments
set RAM[101] 0,
set RAM[102] 6; 
set RAM[103] 6; 
set RAM[104] 6; 
set RAM[105] 6; 
set RAM[106] 6; 

repeat 100 {
  ticktock;
}
output;


// should output 2
set PC 0,
set RAM[100] 5,   // Set test arguments
set RAM[101] 7,
set RAM[102] 0; 
set RAM[103] 6; 
set RAM[104] 6; 
set RAM[105] 6; 
set RAM[106] 6; 

repeat 120 {
  ticktock;
}
output;


// should output 12
set PC 0,
set RAM[100] 1,   // Set test arguments
set RAM[101] 2,
set RAM[102] 3; 
set RAM[103] 4; 
set RAM[104] 5; 
set RAM[105] 6; 
set RAM[106] 7; 
set RAM[107] 8; 
set RAM[108] 9;
set RAM[109] 10;
set RAM[110] 11;
set RAM[111] 12;

repeat 250 {
  ticktock;
}
output;

