all: bin2txt txt2bin NOTify

bin2txt: bin2txt.c
	gcc bin2txt.c -o bin2txt

txt2bin: txt2bin.c
	gcc txt2bin.c -o txt2bin

NOTify: NOTify.c
	gcc NOTify.c -o NOTify

clean:
	rm -f bin2txt txt2bin NOTify
