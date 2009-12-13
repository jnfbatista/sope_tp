all: sosh freq

sosh: commands.o sosh.o
	gcc -lpthread -o  sosh_s sosh.o commands.o -Wall

sosh.o: sosh.c
	gcc -g -c sosh.c -Wall

freq: freq_cmds.o readline.o freq.o
	gcc -lpthread -o freq freq.o readline.o freq_cmds.o -Wall

freq.o: freq.c
	gcc  -g -c freq.c -lpthread -Wall

commands.o: commands.h commands.c
	gcc -g -c commands.c -Wall

readline.o: readline.h readline.c
	gcc -g -c readline.c -Wall

freq_cmds.o: freq_cmds.h freq_cmds.c
	gcc -g -c freq_cmds.c -Wall

edit:
	vim -p sosh.c commands.* freq.c freq_cmds.* readline.*

clean: 
	rm *.o
	rm sosh
	rm freq

push:
	git push origin master
