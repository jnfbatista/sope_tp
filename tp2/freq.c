#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

#include "readline.h"
#include "freq_cmds.h"

#define FREQ_PIPE "/tmp/sosh.canal"
#define NTHREADS 3

int letter_freq[24];

int init_pipe(); 

/*
 * @param fd File descriptor
 */
void* counter(void* fd_ptr) {
	int * fd = (int *)fd_ptr;
	int n_bytes;
	char buf[256];

	while(1) {
		while( read(*fd, buf, 255) != NULL) {
	   		freq_count(buf, letter_freq);
			freq_diplay(letter_freq);
		}

	}

	return NULL;
}

int main(int argc, char *argv[], char* envp[]) {
	int fd, n_bytes;
	char buf[256];

	pthread_t tid;

	fd = open(FREQ_PIPE, O_RDONLY);
	if (fd != -1) {
		//criar as threads
		if(  pthread_create(&tid, NULL, counter, (void *)&fd) != 0) {
			perror("pthread");
			exit(1);
		}

		if(pthread_join(tid, NULL) != 0) {
			perror("error joining thread");
			exit(1);
		}
	}
	/*
	   freq_count(FREQ_PIPE, letter_freq);
	   freq_diplay(letter_freq);
	   */

	return 0;
}


int init_pipe() {
	if( mkfifo(FREQ_PIPE, 0600) == -1 ) {
		perror("creating fifo");
	}
}

