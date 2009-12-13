#ifndef _FREQ_CMDS_H_
#define _FREQ_CMDS_H_

#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

void freq_count(char txt[], int letter[]);

void freq_display(int letters[]);

void freq_sort(int letters[]);

#endif 
