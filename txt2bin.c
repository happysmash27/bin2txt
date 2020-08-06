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
