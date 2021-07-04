/*
   txt2bin converts its input to an 8-bit string of printed 1s and 0s
   Copyright 2021 happysmash27

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
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
