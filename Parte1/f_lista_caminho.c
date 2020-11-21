#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

void Lista ();

int main()
{
    Lista();
}

void Lista()
{
    char caminho[MAXNAMLEN];    
    DIR *d;
    struct dirent *dir;

    printf("Introduz o caminho da diretoria: ");
    fgets(caminho, MAXNAMLEN, stdin);
    system("clear");

    if (strcmp(caminho, "\n") == 0)
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
        }
    }
    else
    {
        strtok(caminho, "\n");
        d = opendir(caminho);
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
        }
        else
        {
            printf("Não foi possível encontrar essa diretoria\n");
        }
        
    }
}