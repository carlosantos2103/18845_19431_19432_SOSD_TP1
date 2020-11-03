//acrescenta origem destino–
//Estecomandodeveacrescentaroconteúdoda“origem”nofinaldo“destino”.
//Casoalgumdosficheirosnãoexista,deveser apresentado um aviso ao utilizador;

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char* argv[]){

int ficheiro1,ficheiro2, leitura1,leitura2,escrita,soma=0;
char read_file1[51], read_file2[51];
char string[1001]="";
char *word;

// Verificar se possui este tipo de sintaxe: comando + 1ºficheiro + 2 ficheiro
if (argc < 2) {
    fputs("Nao foi possivel localizar o Ficheiro", stderr);
    exit(1);
  }

// Ficheiro origem
ficheiro1 = open(argv[1], O_RDONLY);
// Ficheiro destino
ficheiro2 = open(argv[2],O_RDWR|O_APPEND);

// Caso dê Erro ao abrir o Ficheiro de Origem
if (ficheiro1 < 0) {
  	// Funciona como uma exceção 
    perror("Erro na abertura do ficheiro ficheiro Origem");
    exit(1);
  }

if (ficheiro2 < 0){
	perror("Erro na abertura do ficheiro de Destino");
	exit(1);
}

leitura1 = read(0,read_file1,50);

// Caso exista um erro na leitura
  if (leitura1 == -1) {
    perror("erro na leitura do 1ºficheiro");
    exit(1);
  }

// Ler todo o Ficheiro da Origem
 while (leitura1 > 0) {
    soma +=leitura1;
    read_file1[leitura1] = '\0';
    //puts(read_file1);
    strcat(string,read_file1);
    leitura1 = read( ficheiro1, read_file1, 50);
  }

// Fecho do ficheiro Origem
close(ficheiro1);  

// Escrever no Ficheiro Destino o conteudo da Origem
write(ficheiro2,string,soma);

// Fecho do ficheiro de Destino
close(ficheiro2);
exit(0);
}
