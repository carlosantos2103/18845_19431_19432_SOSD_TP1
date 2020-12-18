/* TP1-SOSD-Parte1
a) mostra ficheiro
Este comando deve apresentar no ecrã o conteúdo do ficheiro indicado como parâmetro.
Caso o ficheiro não exista (na diretoria de trabalho atual), o interpretador deve avisar o utilizador que o ficheiro não existe;
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

int main(int argc,char *argv[])
{
    int ficheiro, leitura;
    char ler_ficheiro[51];

    // Verifica se possui este tipo de sintaxe: comando + ficheiro
    if (argc != 2)
    {
        fputs("Erro na apresentacao do ficheiro.\n", stderr);
        exit(EXIT_FAILURE);
    }

    ficheiro = open(argv[1], O_RDONLY);

	// Verifica se o ficheiro foi aberto corretamente
    if (ficheiro < 0)
    {
        // Funciona como uma exceção
        perror("Erro na abertura do ficheiro");
        exit(EXIT_FAILURE);
    }

    // ficheiro disponivel no descritor fd
    leitura = read(ficheiro, ler_ficheiro, 50);

    while (leitura > 0)
    {
        ler_ficheiro[leitura] = '\0';
        puts(ler_ficheiro);
        leitura = read(ficheiro, ler_ficheiro, 50);
    }

    // Caso exista um erro na leitura
    if (leitura == -1)
    {
        perror("Erro na leitura do ficheiro");
        exit(EXIT_FAILURE);
    }

    // Fecha o ficheiro
    close(ficheiro);

    exit(EXIT_SUCCESS);
}
