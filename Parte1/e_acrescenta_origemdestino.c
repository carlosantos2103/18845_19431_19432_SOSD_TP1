/* TP1-SOSD-Parte1
e) acrescenta origem destino
Este comando deve acrescentar o conteúdo da “origem” no final do “destino”.
Caso algum dos ficheiros não exista, deve ser apresentado um aviso ao utilizador;
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char* argv[]){

	int ficheiro1, ficheiro2, leitura, escrita, soma=0;
	char ler_ficheiro[21];
	char texto[1001] = "";

	// Verificar se possui este tipo de sintaxe: comando + 1ºficheiro + 2 ficheiro
	if (argc < 3) {
		fputs("Nao foram apresentados os dois ficheiros 1º e 2º.\n", stderr);
		exit(1);
  	}	

	// Ficheiro origem
	ficheiro1 = open(argv[1], O_RDONLY);
	// Ficheiro destino
	ficheiro2 = open(argv[2], O_WRONLY|O_APPEND);

	// Caso dê Erro ao abrir o Ficheiro de Origem
	if (ficheiro1 < 0) {
	  	// Funciona como uma exceção 
		perror("Erro na abertura do ficheiro ficheiro Origem\n");
		exit(1);
	  }

	if (ficheiro2 < 0){
		perror("Erro na abertura do ficheiro de Destino\n");
		exit(1);
	}

	leitura = read(ficheiro1, ler_ficheiro, 20); //0->ficheiro1
	
	// Ler todo o Ficheiro da Origem
 	while (leitura > 0) {
		soma += leitura;
		ler_ficheiro[leitura] = '\0';
		strcat(texto, ler_ficheiro);
		leitura = read(ficheiro1, ler_ficheiro, 20);
	}
	
	// Caso exista um erro na leitura
	if (leitura == -1) {
		perror("erro na leitura do 1ºficheiro\n");
		exit(1);
	}

	
	// Fecho do ficheiro Origem
	close(ficheiro1);  

	// Escrever no Ficheiro Destino o conteudo da Origem
	escrita = write(ficheiro2, texto, soma);
	
	if (escrita == -1){
		perror("Erro na escrita do 2ºficheiro\n");
		exit(1);
	}

	// Fecho do ficheiro de Destino
	close(ficheiro2);
	exit(0);
}
