/* Ella Grady
 * March 29, 2022
 * CS 140
 * Datalab
 *
 *
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
    // not ( not x and not y)
  return ~(~x & ~y);
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
    // or, and also not and –> have to be different
    int or = ~(~x & ~y);
    int nand = ~(x & y);
    return or & nand;
  
}
/* 
 * oddBits - return word with all odd-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int oddBits(void) {
    // sets each odd bit to be 0xaa
    int one = 0xAA;
    return one + (one << 8) + (one << 16) + (one << 24);
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
    // shifts through x to byte n
    int shiftnum = n << 3; // byte number between 0 and 3
    int value = x >> shiftnum; // go to byte in word
    return value & 0xFF; // compute
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
    int y = 0;
    n = n << 3; // n between 0 and 3
    m = m << 3; // between 0 and 3
    y = 0xff & ((x >> n) ^ (x >> m)); // 1111 1111
    x = x ^ (y << n); // set nth byte to mth byte
    x = x ^ (y << m); // set mth byte to nth byte
    return x;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
    int shift = (( 1 << 31) >> n) << 1; // shifts out leading n bits
    return (x >> n) & ~shift;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 *  hint on last step:
 *   separate into two 16 bit numbers and add together
 *   step back splitting smaller and smaller
 */
int bitCount(int x) {
    
    int mask = 0x01; // mask = one
    int count = 0; // count
    mask = mask | (mask << 8); // mask = one or one shifted left 8
    mask = mask | (mask << 16); // mask = one or one shifted left 8 or shifted left 16
    count += (x & mask); // count = value of x and mask
    // right shift through x to check if place = mask
    count += ((x >> 1) & mask);
    count += ((x >> 2) & mask);
    count += ((x >> 3) & mask);
    count += ((x >> 4) & mask);
    count += ((x >> 5) & mask);
    count += ((x >> 6) & mask);
    count += ((x >> 7) & mask);

    // returns the count of each part
    return (count & 0xff) + ((count >> 8) & 0xff) + ((count >> 16) & 0xff) + ((count >> 24) & 0xff);
  
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
    int xsign = (x >> 31); // set to 0 or 1 based on sign
    int flipsign = ((( ~x) + 1) >> 31); // sets to 1 or 0
    
    return ((~(xsign | flipsign)) & 1); // returns 0 or 1 depending on what xsign and flipsign are
}
/* 
 * minusOne - return a value of -1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 *  flip the bits (!) and add 1
 */
int minusOne(void) {
    // returns opposite of 0
    return ~(0x00);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
    // minimum two's complement = 100000000...
  return 1 << 31;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
    int shift = x >> (n + ~0); // calculate shift necessary based on n
    return !shift ^ !(~shift); // return results if it can work
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
    int bias = (x >> 31) & 1; // compute bias with most significant bit
    return (x + ( bias << n) + ~bias + 1) >> n; // adds based on bias
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
    // flip the bits and add 1
    return (~(x) + 1);
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
    // shifts most significant bit over and checks to see if is less than 0
    // then ands that result with if x is 0
    return ((!(x >> 31)) & !!x);
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
    int xsign = x >> 31; // 1 if negative, 0 if positive
    int ysign = y >> 31; // 1 if negative, 0 if positive
    // if x larger (~y + x) = 0 - sign bit
    // if y larger (~y + x) = 1 - sign bit
    int equal = (!(xsign ^ ysign)) & ((~y + x) >> 31);
    // if signs opposite then reverse
    int notequal = xsign & !ysign;
    // returns 0 when x > y , so negate to return 1
    return !(equal | notequal);
}
/* 
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4 
 */
int isNonZero(int x) {
    int zero = (~x + 1); // handles negative 0 case
    return ((zero >> 31) | (x >> 31)) & 1; // shift sign bit, add them, mask with 1 to see if either had sign bit
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
    // https://docs.oracle.com/cd/E19957-01/806-3568/ncg_math.html - hex bit patterns
   
    unsigned inf = 0x7F800000; // infinity
    
  
    if (uf > inf) { // if uf is infinity return uf
        return uf;
    }
    
    return uf ^ (1 << 31); // otherwise change sign bit to 1
}
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
    // https://docs.oracle.com/cd/E19957-01/806-3568/ncg_math.html - hex bit patterns
    
    unsigned inf = 0x7F800000; // infinity
    
    
    if (uf > inf) { // if uf is infinity return uf
        return uf;
    }
    
    return uf ^ (0 << 31); // otherwise change sign bit to 0
    
    
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
    // if x = 0 or -1, rep already known
    // otherwise make x pos and determine exp by subtracting num of left shifts from 158
    // calculate and normalize frac then add all together
    
    int exp = 158; // 127 (bias) + 31 (max shift) = 158
    int sign = 0x80000000; // most negative bit
    int neg = x & sign; // tells if x is negative
    int frac;
    
    if (x == 0x80000000) { // if x = - 1 float representation
        return 0xCF000000; // representation of -2147483648 ( value of - 1 on cs: app pg 111)
    }
    if (!x) { // if x = 0 return 0
        return 0;
    }
    if (neg) { // make x positive
        x = -x;
    }
    while (!(x & sign)) { // shift x left until sign position is a 1
        x = x << 1;
        exp--; // makes at most 31 shifts, so this will make represent exponent before  subtracting bias
    }
    
    frac = (x & 0x7FFFFFFF) >> 8; // shift x out of exponent part
    if (x & 0x80 && (((x & 0x7F) > 0x00)  || frac & 0x01)) { // changes frac part
        frac++;
    }
    
    exp = exp << 23; // shifts exponent part
    return (neg | exp) + frac; // returns float representation
    
}
