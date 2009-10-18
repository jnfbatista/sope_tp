#ifndef COMMANDS_H_
#define COMMANDS_H_

/**
 * Executa o o commando who do UNIX
 * @return Devolve 0 se for concluído com sucesso e 1 se houver um erro
 */
int quem();

int psu();

int ver();

int ajuda();

int localiza(char* cmd);

int exit();

#endif

