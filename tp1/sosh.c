#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

#include "commands.h"

#define VERSION "0.2"

int process_commands(char* user, char* envp[]); 

char* process_args(char * args);
/**
 *
 * @param sig Sinal a ser tratado por esta função
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
	char cmd[MAX_INPUT];
	const char* tokens = " \n\r";
	char *res[50];
	int i =0, j = 0;
	
	printf("%s: ", user);
	fgets( cmd, MAX_INPUT, stdin);

	// Processes the intput
	res[i] = strtok(cmd, tokens); 
	i++;
	while( (res[i] = strtok(NULL, tokens)) != NULL){
		i++;
	}

	while(res[j] != NULL) {
		printf("%d: %s\n",j, res[j]);
		j++;
	}

	if(strcmp(res[0], "ver") == 0 ) {
		ver(VERSION);
	} else if (strcmp(res[0], "quem") == 0) {
		quem();
	} else if(strcmp(res[0],"localiza") == 0){
		localiza(res);
	} else if (strcmp(res[0],"psu") == 0) {
		psu();	
	} else if (strcmp(res[0],"ajuda") == 0) {
		ajuda();
	} else if (strcmp(res[0],"sair") == 0) {
		sair();
	} else {
		printf("Comando não reconhecido\n");
	}
	return 0;
}

