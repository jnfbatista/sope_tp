#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

#include "readline.h"

#define FREQ_PIPE "/tmp/sosh.canal"

int init_pipe() {
	if( mkfifo(FREQ_PIPE, 0600) == -1 ) {
		perror("creating fifo");
	}
}

int main(int argc, char *argv[], char* envp[]) {
	int fd, n_bytes;
	char buf[256];

	fd = open(FREQ_PIPE, O_RDONLY);
	if (fd != -1) {
		while(1) {
			n_bytes = read(fd, buf, 256);
			if (n_bytes != 0) {
				printf("%s\n", buf);
			}
		}
	close(fd);

	}
	return 0;
}



