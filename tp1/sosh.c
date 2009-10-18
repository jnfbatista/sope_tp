#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

#include <commands.h>

/**
 * @param Signal to be handled
 */
void handler(int sig) {
	char c[32];

	printf("\nDo you wish to exit? (y/N): ");
	scanf("%s", c);
	if(strcmp(c, "y" ) == 0) {
		exit(0);
	}
}


int main(int argc, char * argv[], char* envp[]) {
	
	signal(SIGINT, handler);

	while(1) {

	}

	return 0;
}
