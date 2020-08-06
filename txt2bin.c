/*
    txt2bin converts its input to an 8-bit string of printed 1s and 0s
    Copyright (C) 2020  happysmash27

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdio.h>

int main(){
  //Input Character
  //Int because getc() returns int
  int inc;
  //Why getc() returns int? I think for the special characters
  //So, I think we can select only 8 bits from it.

  //Inloc is a char with the bit we want to read from inc
  //This will be used with bitwise operators to read that bit
  //unsigned char because... actually, I have to think about this
  unsigned char inloc;
  inloc = 1<<7;

  while((inc = getc(stdin)) != EOF){
    //Inloc starts at the largest significant digit and goes down
    /*To initialise this, we take 1 and shift it left 7 times, to 
      our largest significant digit*/
    //To make it go down, we shift it right using inloc >>= 1
    /*When inloc is shifted right the final time, 
      it will be equal to 0, with no bit selected, 
      and our loop will restart.*/
    for (inloc = 1<<7; inloc != 0; inloc >>= 1){
      if (inc&inloc){
	putchar('1');
      } else {
	putchar('0');
      }
    }
    putchar(' ');
  }
  putchar('\n');
}
