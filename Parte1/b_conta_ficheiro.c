/* TP1-SOSD-Parte1
b) conta ficheiro
Este comando deve contar o numero de caracteres existentes de um ficheiro.
Se o ficheiro nao existir, devera ser indicado ao utilizador uma mensagem de erro.
*/

#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]){

	int ficheiro, leitura, soma=0;
	char ler_ficheiro[21];

	// Verifica se possui este tipo de sintaxe: comando + ficheiro
	if (argc < 2) {
		fputs("Nao foi apresentado nenhum ficheiro.\n", stderr);
		exit(1);
	}

	ficheiro = open(argv[1], O_RDONLY);

	// Verifica se o ficheiro foi aberto corretamente
	if (ficheiro < 0) {
		// Funciona como uma exceção 
		perror("Erro na abertura do ficheiro");
		exit(1);
	}

	// Ficheiro disponivel no descritor fd
	leitura = read(ficheiro, ler_ficheiro, 20);
	
	
	while (leitura > 0) 
    {
		soma += leitura;
		ler_ficheiro[leitura] = '\0';

		leitura = read(ficheiro, ler_ficheiro, 20);
	}

	printf("O ficheiro possui %d caracteres", soma);

	// Verifica se houve erro na leitura do ficheiro
	if (leitura == -1) {
		perror("Erro na leitura do ficheiro");
		exit(1);
	}
    
	// Fecha o ficheiro
	close(ficheiro);

	exit(0);
}
