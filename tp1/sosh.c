#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

#include "commands.h"

#define VERSION "0.3"


/**
 * Handler de um sinal (a ser usado com SIGINT) para
 * perguntar ao utilizador se deseja sair da consola
 *
 * @param sig Sinal a ser tratado por esta função
 */
void handler(int sig);

/**
 * Trata do loop principal do programa, esperando os
 * comandos a serem executados e executando-os posteriormente
 * @param user String com o nome do utilizador da máquina
 */
int process_commands(char* user); 

/**
 * main function
 */
int main(int argc, char * argv[], char* envp[]) {

	char* user;

	user = getenv("USER");
	signal(SIGINT, handler);

	while(1) {
		process_commands(user);
	}

	return 0;
}

int process_commands(char* user) {
	char cmd[MAX_INPUT];
	const char* tokens = " \n\r";
	char *res[50];
	int i =0;

	printf("%s: ", user);
	fgets( cmd, MAX_INPUT, stdin); //Espera um input de stdin

	// Processa o input e separa-o num char*
	res[i] = strtok(cmd, tokens); 
	i++;
	while( (res[i] = strtok(NULL, tokens)) != NULL){
		i++;
	}
	
	// Tenta executar o commando da shell
	// em caso de não existir tenta correr com o execlp
	if(strcmp(res[0], "ver") == 0 ) {
		cmd_ver(VERSION);
	} else if (strcmp(res[0], "quem") == 0) {
		cmd_quem();
	} else if(strcmp(res[0],"localiza") == 0){
		cmd_localiza(res);
	} else if (strcmp(res[0],"psu") == 0) {
		cmd_psu();	
	} else if (strcmp(res[0],"ajuda") == 0) {
		cmd_ajuda();
	} else if (strcmp(res[0],"exit") == 0) {
		cmd_sair();
	} else {
		cmd_usrbin(res, i);	
	}
	return 0;
}

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

