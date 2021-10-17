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

int main(){
     //Input Character
     //int because that's what getc gives
     int inc;
     
     char innums[3] = {0};
     //char innum;
     char innumloc = -1;
     
     while ((inc = getc(stdin)) != EOF){
	  if (inc>=48 && inc<=57){
	       innumloc++;
	       if (innumloc>2){
		    if (innums[0] > 2 || innumloc>3){
			 fprintf(stderr, "Error: Input number is too large to fit in an 8-bit integer\n");
			 return 1;
		    }
	       }
	       char innum = inc-48;
	       innums[innumloc] = innum;
	  } else {
	       if (innumloc==2){
		    fputc(innums[0]*100+innums[1]*10+innums[2], stdout);
	       } else if (innumloc==1){
		    fputc(innums[0]*10+innums[1], stdout);
	       } else if (innumloc == 0){
		    fputc(innums[0], stdout);
	       }
	       innumloc = -1;
	  }
     }
     return 0;
}
