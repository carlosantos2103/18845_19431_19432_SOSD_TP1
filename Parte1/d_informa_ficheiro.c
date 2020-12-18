#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
    int inode;
    char username[_SC_LOGIN_NAME_MAX];
    struct stat stats;
    
    if (argc != 2) {
		fputs("Erro na apresentacao do ficheiro.\n", stderr);
		exit(EXIT_FAILURE);
	}

    if(stat(argv[1], &stats) == 0)
    {
        printf("Tipo de ficheiro: ");
        
        if (S_ISREG(stats.st_mode))
        {
            printf("Ficheiro regular\n");
        }
        else if (S_ISDIR(stats.st_mode))
        {
            printf("Diretório\n");
        }
            
        else if (S_ISCHR(stats.st_mode))
        {
            printf("Dispositivo de personagem\n");
        }
            
        else if (S_ISBLK(stats.st_mode))
        {
            printf("Dispositivo de bloqueio\n");
        }
            
        else if (S_ISFIFO(stats.st_mode))
        {
            printf("FIFO\n");
        }

        else if (S_ISLNK(stats.st_mode))
        {
            printf("Ligação simbólica\n");
        }
            
        else if (S_ISSOCK(stats.st_mode))
        {
            printf("Soquete de rede\n");
        }
    
        inode = stats.st_ino;
        printf("I-node: %d\n", inode);

        getlogin_r(username, _SC_LOGIN_NAME_MAX);
        printf("Utilizador dono: %s\n", username);
        exit(EXIT_SUCCESS);
    }
    else
    {
        perror("Não foi possivel obter as propriedades do ficheiro");
        exit(EXIT_FAILURE);
    }
}

