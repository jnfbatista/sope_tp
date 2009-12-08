#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>

#define FREQ_PIPE "/tmp/sosh.canal"

struct Letter {
	char[1];
	int frequency;
};

struct freq_table{
	Letter* letters[];
};

int init_pipe() {
	if( mkfifo(FREQ_PIPE, 0600) == -1 ) {
		perror("creating fifo");
	}
}

int main(int argc, char *argv[], char* envp[]) {

	return 0;
}

