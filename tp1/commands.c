#include "commands.h"


int cmd_quem() {
	int result;
	int pid = fork();
	
	//Filho executa o comando who
	if (pid == 0) {
		if(execlp("who", "", (const char*)NULL) == -1) {
			exit(-1);
		}
	} else {
		result = wait(&pid);
	}

	if(result == pid)
		return 0;
	else
		return -1;
}

int cmd_psu() {
	int p = fork();
	int result;
	char* cmd = "ps";
	char* cmd_w_args = "u";

	if (p == 0) {
		signal(SIGINT, SIG_DFL);
		if((result = execlp(cmd, cmd, cmd_w_args, (const char*)NULL))== -1) {
			perror("execlp");
		}
		exit(0);	
	} else {
		wait(&p);
	}

	return 0;
}

int cmd_ver(char* version) {
	printf("sosh: Versão %s\n", version);
	return 0;
}

int cmd_ajuda() {
	printf("\nComandos suportados;\n");
	printf("ajuda\t\tImprime este ecrã\n");
	printf("exit\t\tTermina sosh\n");
	printf("localiza <cmd>\tLocaliza ficheiros que contenham <cmd>\n");
	printf("psu\t\tLista os processos que lhe pertencem a correr\n");
	printf("quem\t\tExecuta o comando \"who\"\n");
	printf("ver\t\tIndica a versão desta shell\n");
	
	return 0;
}

void cmd_sair() {
	exit(0);
}

int cmd_localiza(char* cmd[]) {
	int i = 1, pid = fork();

	//Pai
	if (pid == 0) {
		signal(SIGINT, SIG_DFL);
		get_dirs("", cmd[i], "");
		exit(0);
	} else {
		wait(&pid);
	} 
	return 0;
}

void get_dirs(char* olddir, char* expr, char* path) {
	char actual_path[MAX_PATH];
	DIR* caminho;
	struct dirent* dir;

	// Concatena as strings para passar o caminho completo a opendir()
	strcpy(actual_path, path);
	strcat(actual_path, olddir);
	strcat(actual_path, SEPARATOR);


	// Abre a pasta
	if((caminho = opendir(actual_path))== NULL) {
		perror(actual_path);
	} else {
		// Enquanto tiver ficheiros para percorrer
		while((dir = readdir(caminho)) != NULL) {
			//verifica se contem a expressao pretendida
			if(strstr(dir->d_name, expr) != NULL) {	
				printf("%s%s\n",actual_path, dir->d_name);
			}
			// ignora os indicadores da pasta um nivel acima
			// da própria (".." e ".")
			if(strcmp(dir->d_name, ".") == 0)
				continue; //do nothing
			if(strcmp(dir->d_name, "..") == 0)
				continue; //do nothing
			if(dir->d_type == DT_DIR) { //opens other directories
				get_dirs(dir->d_name, expr, actual_path);
			}
		}
		closedir(caminho); // fecha o directório
	}

}


int cmd_usrbin(char* argv[], int argc){
	int pid = fork();

	// FIlho executa o execvp()
	if(pid == 0) {
		if(execvp(argv[0], argv) == -1) {
			exit(-1);
		}
	} else {
		wait(&pid); // processo pai espera a terminção do filho
	}
	
	return 0;
}
