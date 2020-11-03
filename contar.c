#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]){

int ficheiro, leitura, soma=0;
  char read_file[21];

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
  leitura = read(ficheiro, read_file, 20);

  while (leitura > 0) {
    soma += leitura;
    read_file[leitura] = '\0';

    leitura = read( ficheiro, read_file, 20);
  }
  
  printf("O ficheiro possui %d caracteres", soma);

  // -1 houve erro
  if (leitura == -1) {
    perror("erro na leitura do ficheiro");
    exit(1);
  } else { // 0 EOF
    puts("");
  }

  close(ficheiro);
  
exit(0);
}
