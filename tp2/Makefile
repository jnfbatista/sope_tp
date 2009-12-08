all: sosh

sosh: commands.o sosh.o
	gcc -o sosh sosh.o commands.o -Wall

sosh.o: sosh.c
	gcc -g -c sosh.c -Wall

freq: freq.o
	gcc -o freq freq.o -Wall

freq.o: freq.c
	gcc -g -c freq.c -Wall

commands.o: commands.h commands.c
	gcc -g -c commands.c -Wall

edit:
	vim -p sosh.c commands.h commands.c freq.c

clean: 
	rm *.o
	rm sosh

push:
	git push origin master
