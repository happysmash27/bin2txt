all: bin2txt txt2bin NOTify dec2txt

bin2txt: bin2txt.c
	gcc bin2txt.c -Wall -o bin2txt

txt2bin: txt2bin.c
	gcc txt2bin.c -Wall -o txt2bin

NOTify: NOTify.c
	gcc NOTify.c -Wall -o NOTify

dec2txt: dec2txt.c
	gcc dec2txt.c -Wall -o dec2txt

clean:
	rm -f bin2txt txt2bin NOTify
