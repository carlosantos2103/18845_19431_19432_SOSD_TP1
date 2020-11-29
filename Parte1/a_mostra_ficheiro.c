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

int main(int argc, char *argv[])
{
    int ficheiro, leitura;
    char ler_ficheiro[51];


    struct dirent *pDirent;
    DIR *pDir;

    // Ensure we can open directory.

    pDir = opendir (argv[1]);
    if (pDir == NULL) {
        printf ("Nao foi possivel abrir a diretoria '%s'\n", argv[1]);
        return 1;
    }

    // Process each entry.

    while ((pDirent = readdir(pDir)) != NULL) {
        printf ("[%s]\n", pDirent->d_name);
    }

    // Close directory and exit.

    closedir (pDir);

    // Verifica se possui este tipo de sintaxe: comando + ficheiro
    if (argc < 2)
    {
        fputs("Nao foi apresentado nenhum ficheiro.\n", stderr);
        exit(1);
    }

    ficheiro = open(argv[1], O_RDONLY);

// Verifica se o ficheiro foi aberto corretamente
    if (ficheiro < 0)
    {
        // Funciona como uma exceção
        perror("Erro na abertura do ficheiro");
        exit(1);
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
        perror("erro na leitura do ficheiro");
        exit(1);
    }

    // Fecha o ficheiro
    close(ficheiro);
    
    exit(0);
}
