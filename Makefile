all: bin2txt txt2bin

bin2txt: bin2txt.c
	gcc bin2txt.c -o bin2txt

txt2bin: txt2bin.c
	gcc txt2bin.c -o txt2bin

clean:
	rm -f bin2txt txt2bin
