#ifndef COMMANDS_H_
#define COMMANDS_H_

#include <stdio.h>
#include <unistd.h>

/**
 * Executa o o commando who do UNIX
 * @return Devolve 0 se for concluído com sucesso e 1 se houver um erro
 */
int quem(char* envp[]);

int psu();

int ver(char* version);

int ajuda();

int localiza(char* cmd);

int sair();

#endif

