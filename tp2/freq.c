#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

#include "readline.h"
#include "freq_cmds.h"

#define FREQ_PIPE "/tmp/sosh.canal"
#define CMD_PIPE "/tmp/sosh.cmd"
#define RES_PIPE "/tmp/sosh.results"

#define NTHREADS 2 

int letter_freq[26];

void process_input();

int init_pipe(); 

/*
 * Função para uma thread que lerá tudo que é recebido no pipe
 * e procederá para a contagem
 *
 * @param fd File descriptor
 */
void* counter(void* fd_ptr);

void* recieve_cmds();

int main(int argc, char *argv[], char* envp[]) {
	int fd, fd_cmd, n_bytes;
	char buf[256];

	pthread_t tid[NTHREADS];

	//Initiates cmd fifo
	if(mkfifo(CMD_PIPE, 0666) == -1) {
		if(errno != EEXIST)
			exit(1);
	}
	if (pthread_create(&tid[0], NULL, recieve_cmds, (void *)&fd_cmd) != 0) {
		perror("create thread for recieveing comands");
		exit(1);
	}

	fd = open(FREQ_PIPE, O_RDONLY);
	if (fd != -1) {
		//criar as threads
		if(  pthread_create(&tid[1], NULL, counter, (void *)&fd) != 0) {
			perror("pthread");
			exit(1);
		}

		if(pthread_join(tid[1], NULL) != 0) {
			perror("error joining thread");
			exit(1);
		}
	}
	if(pthread_join(tid[0], NULL) != 0) {
		perror("error joining thread");
		exit(1);
	}

	return 0;
}


int init_pipe() {
	if( mkfifo(FREQ_PIPE, 0600) == -1 ) {
		perror("creating fifo");
	}
}

void* counter(void* fd_ptr) {
	int * fd = (int *)fd_ptr;
	int n_bytes;
	char buf[256];

	while(1) {
		while( read(*fd, buf, 255) != NULL) {
			freq_count(buf, letter_freq);
		}

	}

	return NULL;
}

void* recieve_cmds(void* arg) {
	int fd;
	char buffer[256];

	do {
		fd = open(CMD_PIPE, O_RDONLY);
	} while (fd == -1);

	while( read(fd, buffer, 255) != NULL) {
		if (strcmp(buffer, "stat\n") == 0 ){
			freq_display(letter_freq);
		}
	}


}

