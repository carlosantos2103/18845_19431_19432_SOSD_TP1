// Apagar Este comando deve apagar o ficheiro com o nome indicado
//(da diretoria atual). No caso de o ficheiro indicado ​ não existir, e apenas,
//deve ser apresentado um aviso ao utilizador;
#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char* argv[]){

int ficheiro,leitura;
char read_file[51];

if(argc <= 1){
	perror("Nao foi possivel localizar o Ficheiro");
	exit(1);
}

ficheiro = open(argv[1], O_TRUNC);

if(ficheiro < 0){
 perror("Erro na abertura do ficheiro");
    exit(1);
}

  close(ficheiro);
  exit(0);
}

