/*
    NOTify outputs the bitwise NOT of each character input to it
    Copyright (C) 2021  happysmash27

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.*/

#include <stdio.h>

void main(){
  //Input Character
  //int because that's what getc gives
  //unsigned because to my knowledge, no characters are on negative values
  unsigned int inc;

  while((inc = getc(stdin)) != EOF){
    putchar(~inc);
  }
}
