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
     
     int intprintnum = 0;
     char innums[3] = {0};
     //char innum;
     char innumloc = 0;
     char max_num_size = 3;
     
     while ((inc = getc(stdin)) != EOF){
	  if (inc>=48 && inc<=57){
	       char innum = inc-48;
	       if (innumloc == 0){
		    //This annoying format I am reading can be anywhere between 1 to 3 digits
		    //Should an even more insane format come along with no spaces, automatically...
		    if (innum>2){
			 max_num_size = 2;
		    } else {
			 max_num_size = 3;
		    }
	       }
	       innums[numloc] = inc;
	       numloc++;
