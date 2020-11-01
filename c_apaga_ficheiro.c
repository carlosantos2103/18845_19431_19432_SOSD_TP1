#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	int fd;
	
	if (argc < 2) {
		fputs("Nao foi apresentado nenhum ficheiro.\n", stderr);
		exit(1);
	}
	
	fd = unlink(argv[1]);
	
	if (fd < 0) {
		perror("Erro ao apagar o ficheiro");
		exit(1);
	}
	
	close(fd);

	exit(0);	
}
