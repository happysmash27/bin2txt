# bin2txt
Software to convert text to and from binary, written as a string of 1s and 0s.

To compile, simply run `make`, and the bin2txt and txt2bin binaries will be generated. 

To use bin2txt, pipe a series of 1s and 0s in, or just type them. Currently, it assumes each character is 8 bits.

To use txt2bin, pipe 8-bit characters into it (variable-width utf-8 works, by the way). It will then output them in 8-bit binary, with a space every 8 bits, and a newline at the end. 

Backwards compatibility with the binaries may be broken in the future in order to add more functionality (e.g, support for encodings other than utf-8). 