#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char* argv[]){

  int ficheiro, leitura;
  char read_file[51];

  if (argc < 2) {
    fputs("Nao foi possivel localizar o Ficheiro", stderr);
    exit(1);
  }

  ficheiro = open(argv[1], O_RDONLY);

  if (ficheiro < 0) {
  	// Funciona como uma exceção 
    perror("erro na abertura do ficheiro");
    exit(1);
  }

  // ficheiro disponivel no descritor fd
  leitura = read(ficheiro, read_file, 50);

  while (leitura > 0) {
    read_file[leitura] = '\0';
    puts(read_file);
    leitura = read( ficheiro, read_file, 50);
  }

  // Caso exista um erro na leitura
  if (leitura == -1) {
    perror("erro na leitura do ficheiro");
    exit(1);
  } else {
  }
  close(ficheiro);
  exit(0);
}
