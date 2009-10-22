#ifndef COMMANDS_H_
#define COMMANDS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>

#define MAX_PATH 1024
#define SEPARATOR "/"

/**
 * Executa o o commando who do UNIX
 * @return Devolve 0 se for concluído com sucesso e 1 se houver um erro
 */
int quem();

int psu();

int ver(char* version);

int ajuda();

int localiza(char* cmd[]);

void sair();

void get_dirs(char* dir, char* expr, char* path); 
#endif

