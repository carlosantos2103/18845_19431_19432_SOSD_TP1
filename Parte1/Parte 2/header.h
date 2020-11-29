// Fazer update nisto !!
#pragma region Funcao de mostrar
// Recebe como parametros quantos argumentos foram dados e qual o ficheiro para mostar
int mostra(int argc,char *argv){ 
    int ficheiro, leitura;
    char ler_ficheiro[51];

    // Verifica se possui este tipo de sintaxe: comando + ficheiro
    if (argc < 2)
    {
        fputs("Nao foi apresentado nenhum ficheiro.\n", stderr);
        return 1;
    }

	ficheiro = open(argv, O_RDONLY);

	// Verifica se o ficheiro foi aberto corretamente
    if (ficheiro < 0)
    {
        // Funciona como uma exceção
        perror("Erro na abertura do ficheiro");
        return 1;
    }
    // ficheiro disponivel no descritor fd
    leitura = read(ficheiro, ler_ficheiro, 50);

    while (leitura > 0)
    {
        ler_ficheiro[leitura] = '\0';
        printf("%s", ler_ficheiro);
        leitura = read(ficheiro, ler_ficheiro, 50);
    }
    puts("");
    // Caso exista um erro na leitura
    if (leitura == -1)
    {
        perror("erro na leitura do ficheiro");
        return 1;
    }

    // Fecha o ficheiro
    close(ficheiro);
    
    return 0;
}
#pragma endregion

#pragma region Funcao de contar
// Recebe como parametros quantos argumentos foram dados e qual o ficheiro para contar os caracteres
int conta(int argc,char *argv){
    int ficheiro, leitura, soma=0;
	char ler_ficheiro[21];

	// Verifica se possui este tipo de sintaxe: comando + ficheiro
	if (argc < 2) {
		fputs("Nao foi apresentado nenhum ficheiro.\n", stderr);
		return 1;
	}

	ficheiro = open(argv, O_RDONLY);

	// Verifica se o ficheiro foi aberto corretamente
	if (ficheiro < 0) {
		// Funciona como uma exceção 
		perror("Erro na abertura do ficheiro");
		return 1;
	}

	// Ficheiro disponivel no descritor fd
	leitura = read(ficheiro, ler_ficheiro, 20);
	
	
	while (leitura > 0) 
    {
		soma += leitura;
		ler_ficheiro[leitura] = '\0';

		leitura = read(ficheiro, ler_ficheiro, 20);
	}

	printf("O ficheiro possui %d caracteres\n", soma);
    

	// Verifica se houve erro na leitura do ficheiro
	if (leitura == -1) {
		perror("Erro na leitura do ficheiro");
		return 1;
	}
    
	// Fecha o ficheiro
	close(ficheiro);

	return 0;
}
#pragma endregion

#pragma region Funcao de apaga
int apaga(int argc,char *argv){
    int fd;
	
	// Verifica se foi enviado o segundo argumento: comando + ficheiro
	if (argc < 2) {
		fputs("Nao foi apresentado nenhum ficheiro.\n", stderr);
		return 1;
	}
	
	// Executa a funcao system call, unlink 
	fd = unlink(argv);
	
	// Verifica se existe um erro ao executar a funcao
	if (fd < 0) {
		perror("Erro ao apagar o ficheiro");
		return 1;
	}
	
	// Fecha o ficheiro
	close(fd);

	return 0;	
}
#pragma endregion

#pragma region Funcao de acrescentar
int acrescenta(int argc,char *argv1,char *argv2){
    int ficheiro1, ficheiro2, leitura, escrita, soma=0;
	char ler_ficheiro[21];
	char texto[1001] = "";

	// Verificar se possui este tipo de sintaxe: comando + 1ºficheiro + 2 ficheiro
	if (argc < 3) {
		fputs("Nao foram apresentados os dois ficheiros 1º e 2º.\n", stderr);
		return 1;
  	}	

	// Ficheiro origem
	ficheiro1 = open(argv1, O_RDONLY);
	// Ficheiro destino
	ficheiro2 = open(argv2, O_WRONLY|O_APPEND);

	// Caso dê Erro ao abrir o Ficheiro de Origem
	if (ficheiro1 < 0) {
	  	// Funciona como uma exceção 
		perror("Erro na abertura do ficheiro ficheiro Origem\n");
        return 1;
	  }

	if (ficheiro2 < 0){
		perror("Erro na abertura do ficheiro de Destino\n");
        return 1;

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
		return 1;

	}
	
	// Fecho do ficheiro Origem
	close(ficheiro1);  

	// Escrever no Ficheiro Destino o conteudo da Origem
	escrita = write(ficheiro2, texto, soma);
	
	if (escrita == -1){
		perror("Erro na escrita do 2ºficheiro\n");
	    return 1;

	}

	// Fecho do ficheiro de Destino
	close(ficheiro2);
    return 0;
}
#pragma endregion
