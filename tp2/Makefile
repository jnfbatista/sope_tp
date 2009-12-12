all: sosh freq

sosh: commands.o sosh.o
	gcc -o sosh sosh.o commands.o -Wall

sosh.o: sosh.c
	gcc -g -c sosh.c -Wall

freq: readline.o freq.o
	gcc -o freq freq.o readline.o -Wall

freq.o: freq.c
	gcc -g -c freq.c -Wall

commands.o: commands.h commands.c
	gcc -g -c commands.c -Wall

readline.o: readline.h readline.c
	gcc -g -c readline.c -Wall

edit:
	vim -p sosh.c commands.h commands.c freq.c

clean: 
	rm *.o
	rm sosh
	rm freq

push:
	git push origin master
