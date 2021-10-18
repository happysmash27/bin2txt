/*
   dec2txt converts 8-bit decimal numbers (will expand inputs in future) to binary text output
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
#include <stdint.h>
#include <limits.h>

int main(){
     //Input Character
     //int because that's what getc gives
     int inc;
     
     unsigned char innums[3] = {0};
     signed char innumloc = -1;

     size_t input_number = 0;
     
     while ((inc = getc(stdin)) != EOF){
	  if (inc>='0' && inc<='9'){
	       //Make sure we don't print our error over and over again if the number keeps going on, by stopping incrementing at 4 and only outputting if is 3 (which is 1 higher than the max supported)
	       if (innumloc<4){
		    innumloc++;
		    if (innumloc<3 && innumloc>=0){
			 innums[innumloc] = inc-'0';
		    } else if (innumloc == 3){
			 fprintf(stderr, "Error: Number of digits in input number %zu is too large to fit in an 8-bit integer\n", input_number);
		    }
	       }
	  } else {
	       if (innumloc==2){
		    uint16_t outnum = innums[0]*100+innums[1]*10+innums[2];
		    if (outnum>UCHAR_MAX){
		      fprintf(stderr, "Error: Input number %zu larger than 8-bit maximum of 255\n", input_number);
		    } else {
			 fputc((unsigned char)outnum, stdout);
		    }
	       } else if (innumloc==1){
		    fputc(innums[0]*10+innums[1], stdout);
	       } else if (innumloc == 0){
		    fputc(innums[0], stdout);
	       }
	       if (innumloc>-1){
		    input_number++;
	       }
	       innumloc = -1;
	  }
     }
     return 0;
}
