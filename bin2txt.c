/*
    bin2txt converts 8-bit binary (in the form of 1s and 0s) to text
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
  //int because that's what getc gives
  //unsigned because to my knowledge, no characters are on negative values
  unsigned int inc;
  //Output Character
  //char because out input is 8 bits, and char is also 8 bits
  //unsigned because we are not outputting negative characters
  unsigned char outc;
  //Location ob bit in output character
  //char because 0-7 does not need to go above 255
  //unsigned because we do not want negative numbers, and want it to overflow after 0
  unsigned char outloc;

  /*Outloc starts at the largest significant digit
    (indexed by 7) and goes down*/
  outloc = 7;
  
  /*Read the input characters until EOF occurs
    (you can invoke this with ctrl-d)*/
  while((inc = getc(stdin)) != EOF){
    /*Once outloc reaches 0 (signifying the last bit in
      the 8-bit string of 1s and 0s), subtracting 1 from 
      it again (as happens at the end of my loop) will 
      cause it to overflow to a large number (usually 255 
      for chars). This checks if outloc has overflowed to
      be larger than its maximum allotted 7, as will occur 
      when we have read a full 8 bits, and if so, outputs 
      the character and resets outloc to 0.*/
    if (outloc > 7){
      putchar(outc);
      outloc = 7;
    }

    if (inc == '1'){
      //If our input character is 1...
      /*Sets the bit in outloc to 1...
	by shifting a single bit left by outloc and
        then using the binary OR operator to set
        bits to 1 if either of them is a 1, which
        means that for all the 0s in my number comprising
        zeros in every location except outloc, the 
        number will stay the same, but for that single
        1 in outloc, this bit will be 1 no matter what, 
        since whether or not outc has a 1 in that
        location, my number will have a 1 to ensure
        that at least one bit, from either side, 
        is a 1*/
      outc |= 1 << outloc;
      outloc -= 1;
    } else if (inc == '0'){
      //If our input character is 0...
      /*Sets the bit in outloc to 0...
	by shifting a single bit left by outloc, 
	using the binary ones complement operator
	so that this bit is 0, and every other one
	(which was 0 before) is now 1. Then, use the
	binary AND operator to set a bit to 1 only
	if BOTH are 1. Since all bits except the one
	I want to set to 0 are 1 in my number, those
	will stay the same no matter what, but that 
	one zero will ensure that whatever is in that
	space is zero, because my complement number
	does not have a 1 there to satisfy the AND
	operator*/
      outc &= ~(1 << outloc);
      outloc -= 1;
    }
    /*If the character is neither a 1 or a 0, don't
      do anything and wait for the next character*/
  }
  
}
