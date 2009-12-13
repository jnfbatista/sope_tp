#ifndef COMMANDS_H_
#define COMMANDS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>

#define MAX_PATH 1024
#define SEPARATOR "/"
#define PIPE "/tmp/sosh.canal"
#define CMD_PIPE "/tmp/sosh.cmd"

/**
 * Executa o o commando who do UNIX
 * @return Devolve 0 se for concluído com sucesso e -1 se houver um erro
 */
int cmd_quem();

/**
 * Executa o commando "ps u" através do execlp para listar
 * os processos deste utilizador
 *
 * @return Devolve 0 se for executado com sucesso e -1 se existir um erro
 */
int cmd_psu();

/**
 * Imprime a versão no ecrã
 */
int cmd_ver(char* version);

/**
 * imprime uma listagem dos comandos suportados
 */
int cmd_ajuda();

/**
 * Termina a shell
 */
void cmd_sair();

/**
 * Implementa o comando locate com a ajuda da fnção get_dirs
 *
 * @return  Retorna 0 em caso de sucesso
 */
int cmd_localiza(char* cmd[]);

/**
 * Função auxiliar do localiza() que trata da parte recursiva da pesquisa
 * fazendo a impressão quando encontra a string que tem como parâmetro de
 * entrada
 *
 * @param dir Pasta a pesquisar
 * @param expr Expressao a ser pesquisada
 * @param path Caminho global da pasta
 */
void get_dirs(char* dir, char* expr, char* path); 

/**
 * Executa aplicações (passando os respectivos argumentos) desde que as mesmas
 * se encontrem nos caminhos especificados pela variável de ambiente PATH
 *
 * @param argv Array de strings com o comando e os respectivos argumentos
 * @param argc Tamanho do array argv
 *
 * @return Retorna 0 se for executado com sucesso
 */
int cmd_usrbin(char* argv[], int argc);

/**
 * Write the input commands to the fifo
 */
int cmd_write_pipe(char buffer[]);

/**
 * Gets the frequency stats from freq server
 */
void cmd_stat();

#endif

