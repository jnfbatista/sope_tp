#include "commands.h"

int quem(char* envp[]) {
	execlp("who", (char*)NULL);
	return 0;
}

int psu() {
	return 0;
}

int ver(char* version) {
	printf("sosh: Versão %s\n", version);
	return 0;
}

int ajuda() {
	return 0;
}
int localiza(char* cmd) {
	return 0;
}

int sair() {
	return 0;
}
