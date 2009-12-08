#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

#define FREQ_PIPE "/tmp/sosh.canal"
/*
   struct Letter {
   char letter[1];
   int frequency;
   };

   struct freq_table{
   struct Letter* letters[];
   };*/

int init_pipe() {
	if( mkfifo(FREQ_PIPE, 0600) == -1 ) {
		perror("creating fifo");
	}
}

int main(int argc, char *argv[], char* envp[]) {
	int fd;
	char buf[256];

	fd = open(FREQ_PIPE, O_RDONLY);
	if (fd != -1) {
		while(1) {
			read(fd, buf, 256);
			printf("%s\n", buf);
		}

	}


	return 0;
}

