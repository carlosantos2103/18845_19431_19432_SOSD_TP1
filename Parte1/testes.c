#include <stdlib.h>
#include <stdio.h>
//#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "header.h"

int main(int argc, char *argv[])
{
    system("cls");
    int contador = 0;
    char *token;
    const char del[2] = " ";
    char palavra[200];
    char function[50];
    char file1[50];
    char file2[50];
    printf("$./interpretador");
    puts("");
    while (1)
    {
        printf("%% ");
        fgets(palavra, 200, stdin);
        if (strcmp(palavra, "termina") == 0)
        {
            exit(0);
        }

        token = strtok(palavra,del);
        
        while (token != NULL)
        {
            strcpy(function,token);
            printf("Function: %s \n", function);

            if (strcmp(function, "contar") == 0 || strcmp(function, "mostra") == 0
            || strcmp(function, "apaga") == 0 )
            {
                token = strtok(NULL, del);
                strcpy(file1,token);
                printf("File1: %s \n", file1);
                token = NULL;
            }else if (strcmp(function, "acrescenta") == 0 ){
                token = strtok(NULL, del);
                strcpy(file1,token);
                printf("File1: %s \n", file1);
                    
                token = strtok(NULL, del);
                strcpy(file2,token);
                printf("File2: %s \n", file2);
                token = NULL;
            }else{
                break;
            }
        }

        if (strcmp(function, "contar") == 0){
            conta(2,file1);
        }else if (strcmp(function, "mostra") == 0)
        {
            mostra(2,file1);
        }else if (strcmp(function, "apaga") == 0)
        {
            apaga(2,file1);
        }else if (strcmp(function, "acrescenta") == 0){
            acrescenta(3,file1,file2);
        }else if (strcmp(function, "termina") == 0)
        {
            exit(0);
        }else
        {
            strcpy(function,"");
            strcpy(palavra,"");
            strcpy(file1,"");
            strcpy(file2,"");
            continue;
        }
    }
    return 0;
}