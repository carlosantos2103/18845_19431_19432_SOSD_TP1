#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>

int mysystem(char* cmd, char* args[]) {
	int result;
	int f=0;
	char *path;

    if (strcmp(cmd, "termina") == 0)
    {
        exit(EXIT_SUCCESS);
    }

	strcpy( path, "../Parte1/" );
	strcat( path, cmd );

	f=fork();
	if (f==-1) {
		perror("Erro na criacao de um novo processo");
		return EXIT_FAILURE;
	}

	if (f == 0) {
		execv(path, args);
		perror("Erro ao executar o comando");
		exit(EXIT_FAILURE);
	}

	wait(&result);
	return WEXITSTATUS(result);
}

int main(int argc, char *argv[])
{
    system("clear");
    char input[600];
    char cmd[12] = "";
    char a1[100] = "", a2[100] = "";
    int count = -1;
    int result;

    while (1)
    {
        printf("%% ");
        fgets(input, 600, stdin);
        count = sscanf(input, "%s %s %s", cmd, a1, a2);

		if (count < 1)
        {
            continue;
        }
		else if (count == 3) {
			char *args[] = { cmd, a1, a2, NULL };
			result = mysystem(cmd, args);
		}
		else{
			char *args[] = { cmd, a1, NULL };
			result = mysystem(cmd, args);
		}
		strcpy(a1,"");
		strcpy(a2,"");
        printf("\033[01;33m");
        printf("Terminou o comando %s com codigo %d\n", cmd, result);
        printf("\033[0m");
    }
    return 0;
}
