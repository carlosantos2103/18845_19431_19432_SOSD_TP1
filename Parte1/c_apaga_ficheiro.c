/* TP1-SOSD-Parte1
c) apaga ficheiro
Este comando deve apagar o ficheiro com o nome indicado (da diretoria atual). 
No caso de o ficheiro indicado não existir, e apenas, deve ser apresentado um aviso ao utilizador;
*/

#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	int fd;
	
	// Verifica se foi enviado o segundo argumento: comando + ficheiro
	if (argc != 2) {
		fputs("Erro na apresentacao do ficheiro.\n", stderr);
		exit(EXIT_FAILURE);
	}
	
	// Executa a funcao system call, unlink 
	fd = unlink(argv[1]);
	
	// Verifica se existe um erro ao executar a funcao
	if (fd < 0) {
		perror("Erro ao apagar o ficheiro");
		exit(EXIT_FAILURE);
	}
	
	// Fecha o ficheiro
	close(fd);

	exit(EXIT_SUCCESS);	
}
