#include "commands.h"


int quem() {
	int pid = fork();
	//Pai
	if (pid == 0) {
		execlp("who", "", (const char*)NULL);
		exit(0);
	} else {
		wait(&pid);
	}

	return 0;
}

int psu() {
	int p = fork();
	int result;
	char* cmd = "ps";
	char* cmd_w_args = "u";

	if (p == 0) {
		if((result = execlp(cmd, cmd, cmd_w_args, (const char*)NULL))== -1) {
			perror("execlp");
			exit(1);
		}
	} else {
		wait(&p);
	}

	return 0;
}

int ver(char* version) {
	printf("sosh: Versão %s\n", version);
	return 0;
}

int ajuda() {
	printf("\nComandos suportados;\n");
	printf("ajuda\t\tImprime este ecrã\n");
	printf("localiza <cmd>\tLocaliza ficheiros que contenham <cmd>\n");
	printf("psu\t\tLista os processos que lhe pertencem a correr\n");
	printf("quem\t\tExecuta o comando \"who\"\n");
	printf("ver\t\tIndica a versão desta shell\n");

	return 0;
}

void sair() {
	exit(0);
}


/**
 * Searches for files that contain <cmd> in their name
 * @param cmd expression to find in the files
 */
int localiza(char* cmd[]) {
	DIR* caminho;
	struct dirent* dir;
	char* root = "/";

	char* tmp = "sh";

	int pid = fork();
	//Pai
	if (pid == 0) {
		get_dirs("", cmd[1], "");
	} else {
		wait(&pid);
	} 
	return 0;

	//opens the directory
	if((caminho = opendir(root)) == NULL) {
		perror("opendir");
		return 1;
	} else {

		while((dir = readdir(caminho)) != NULL) {
			if(strcmp(dir->d_name, ".") == 0)
				continue; //do nothing
			else if(strcmp(dir->d_name, "..") == 0)
				continue; //do nothing
			else if(dir->d_type == DT_DIR)
				get_dirs((char*)&dir->d_name, tmp, root);
		}

		closedir(caminho);
	}

	return 0;
}

/**
 * Trata da recursividade da busca nos directórios
 */
void get_dirs(char* olddir, char* expr, char* path) {
	char* dirs;
	char actual_path[MAX_PATH];
	DIR* caminho;
	struct dirent* dir;

	strcpy(actual_path, path);
	strcat(actual_path, olddir);
	strcat(actual_path, SEPARATOR);


	//opens the new directory
	if((caminho = opendir(actual_path))== NULL) {
		perror(actual_path);
	} else {

		while((dir = readdir(caminho)) != NULL) {
			if(strstr(dir->d_name, expr) != NULL) {	
				printf("%s%s\n",actual_path, dir->d_name);
			}
			if(strcmp(dir->d_name, ".") == 0)
				continue; //do nothing
			if(strcmp(dir->d_name, "..") == 0)
				continue; //do nothing
			if(dir->d_type == DT_DIR) {
				get_dirs(dir->d_name, expr, actual_path);
			}


		}
		closedir(caminho);
	}

}


