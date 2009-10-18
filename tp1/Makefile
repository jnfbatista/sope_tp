all: sosh

sosh: commands.o sosh.o
	gcc -o sosh sosh.o commands.o -Wall

sosh.o: sosh.c
	gcc -g -c sosh.c

commands.o: commands.h commands.c
	gcc -g -c commands.c

edit:
	vim -p sosh.c commands.h commands.c

clean: 
	rm *.o
	rm sosh

push:
	git push origin master
