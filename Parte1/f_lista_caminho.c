#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{    
    DIR *d;
    struct dirent *dir;

    if (argc > 2) {
		fputs("Nao foi possivel localizar o caminho", stderr);
		exit(1);
  	}	

    if (strcmp(argv[1], "") == 0)
    {
        d = opendir(".");
        if (d) 
        {
            printf("------------------------------\n");
            while ((dir = readdir(d)) != NULL) 
            {
                if(dir->d_type==DT_DIR)
                {
                    printf("Diretoria\t| %s\n", dir->d_name);
                }
            }
            rewinddir(d);
            while ((dir = readdir(d)) != NULL)
            {
                if(dir->d_type!=DT_DIR)
                {
                    printf("Ficheiro\t| %s\n", dir->d_name);
                }
            }
            printf("------------------------------\n");
            closedir(d);
            exit(0);
        }
    }
    else
    {
        strtok(argv[1], "\n");
        d = opendir(argv[1]);
        if (d) 
        {
            printf("------------------------------\n");
            while ((dir = readdir(d)) != NULL) 
            {
                if(dir->d_type==DT_DIR)
                {
                    printf("Diretoria\t| %s\n", dir->d_name);
                }
            }
            rewinddir(d);
            while ((dir = readdir(d)) != NULL)
            {
                if(dir->d_type!=DT_DIR)
                {
                    printf("Ficheiro\t| %s\n", dir->d_name);
                }
            }
            printf("------------------------------\n");
            closedir(d);
            exit(0);
        }
        else
        {
            perror("Não foi possível encontrar essa diretoria");
            exit(1);
        }
        
    }
}
