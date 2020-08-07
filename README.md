# bin2txt
Software to convert text to and from binary, written as a string of 1s and 0s.

To compile, simply run `make`, and the bin2txt and txt2bin binaries will be generated. 

To use bin2txt, pipe a series of 1s and 0s in and it will output them… or just type them. Currently, it assumes each character is 8 bits.

Example of using a pipe to input 1s and 0s:

```
% echo "01001000 01100101 01101100 01101100 01101111 00100000 01010111 01101111 01110010 01101100 01100100 00100001 00001010"|./bin2txt
Hello World!
```

Example of using a file to input 1s and 0s:

```
% ./bin2txt < binfile_hello
Hello World!
%
```

Example of just typing everything in:

```
% ./bin2txt
01001000 01100101 01101100 01101100 01101111 00100000 01010111 01101111 01110010 01101100 01100100 00100001 00001010
Hello World!

```

To use txt2bin, pipe 8-bit characters into it (variable-width utf-8 works, by the way). It will then output them in 8-bit binary, with a space every 8 bits, and a newline when the program terminates.

Example of using a pipe to input text to convert to binary:

```
% echo "Hello World\!"|./txt2bin
01001000 01100101 01101100 01101100 01101111 00100000 01010111 01101111 01110010 01101100 01100100 00100001 00001010
%
```

Example of using a file to input text to convert to binary:

```
% ./txt2bin < file_hello
01001000 01100101 01101100 01101100 01101111 00100000 01010111 01101111 01110010 01101100 01100100 00100001 00001010
%
```

Example of just typing everything in: 

```
% ./txt2bin
Hello World!
01001000 01100101 01101100 01101100 01101111 00100000 01010111 01101111 01110010 01101100 01100100 00100001 00001010 
```

Backwards compatibility with the binaries may be broken in the future in order to add more functionality (e.g, support for encodings other than utf-8). 