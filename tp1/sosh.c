#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

#include "commands.h"

#define VERSION "0.2"

/**
 * @param Signal to be handled
 */
void handler(int sig) {
	char c[32];

	printf("\nDo you wish to exit? (y/N): ");
	scanf("%s", c);
	if(strcmp(c, "y" ) == 0) {
		exit(0);
	} else {
		return;
	}
}

/**
 * main function
 */
int main(int argc, char * argv[], char* envp[]) {

	char* user;

	user = getenv("USER");

	signal(SIGINT, handler);

	while(1) {
		process_commands(user, envp);
	}

	return 0;
}

int process_commands(char* user, char* envp[]) {
	char cmd[128];
	int pid;
	printf("%s: ", user);
	scanf("%s", cmd);

	if(strcmp(cmd, "ver") == 0 ) {
		ver(VERSION);
	} else if (strcmp(cmd, "quem")==0) {
		pid = fork();
		//Pai
		if (pid == 0) {
			quem(envp);
		} else {
			wait(&pid);
		}
	} else if(strcmp(cmd,"localiza")){

	} else if (strcmp(cmd,"psu")) {
	
	} else if (strcmp(cmd,"ajuda")) {
	
	} else {
		printf("Comando não reconhecido\n");
	}
}
