/* Cliente basico UDP
   Este cliente destina-se a enviar mensagens passadas na linha de comando, sob
   a forma de um argumento, para um servidor especifico cuja locacao e' dada
   pelas seguintes constantes: SERV_HOST_ADDR (endereco IP) e SERV_UDP_PORT (porto)
   O protocolo usado e' o UDP. */
#include <winsock.h>
#include <stdio.h>

#pragma comment(lib, "ws2_32.lib")

#define SERV_HOST_ADDR "127.0.0.1"
#define SERV_UDP_PORT  5432
#define BUFFERSIZE     4096

void Abort(char *msg);

int main( int argc , char *argv[] ){
	SOCKET sockfd;
	int iResult, nbytes;
	struct sockaddr_in serv_addr;
	char buffer[BUFFERSIZE] = {'\0'};
	WSADATA wsaData;

	/* variáveis para o exercício 3 */
	struct sockaddr_in local_name, reply_addr;
	int sockaddr_in_len;

	/* variáveis para o exercício 6 */
	int serv_udp_port = 0;
	char serv_host_addr[16] = {'\0'};
	char sintaxe[] = "-msg <mensagem> [-ip <server_ip> [-port <server_port>]]";
	int i;

	/* 6. MENSAGEM/IP/PORTO RECEBIDOS POR ARGUMENTO
	      a sintaxe anterior (2 argumentos) continua válida */
	if(argc == 2) strcpy(buffer, argv[1]);
	else for (i = 1; i < argc; i++) {
		/* mensagem */
		if (strcmp("-msg", argv[i]) == 0)
			strcpy(buffer, argv[++i]);/* ++i para copiar/saltar 1 argumento */
		/* enderesso ip */
		else if (strcmp("-ip", argv[i]) == 0)
			serv_udp_port = atoi(argv[++i]);
		/* porto */
		else if (strcmp("-port", argv[i]) == 0)
			strcpy(serv_host_addr, argv[++i]);
	}
	/* usar o porto em SERV_UDP_PORT se não foi recebido por argumento */
	if (!serv_udp_port) serv_udp_port = SERV_UDP_PORT;
	/* usar o ip em SERV_HOST_ADDR se não foi recebido por argumento */
	if (!strlen(serv_host_addr)) strcpy(serv_host_addr, SERV_HOST_ADDR);

	/* TESTAR A SINTAXE
	   a condição foi alterada para o exercício 6 */
	if (argc < 2 || !strlen(buffer)){
		fprintf(stderr, "sintaxe:\n  %s <mensagem>\n", argv[0]);
		/* Sintaxe 2 foi adicionada para complementar o exercício 6 */
		fprintf(stderr, "  %s %s\n", argv[0], sintaxe);
		exit(EXIT_FAILURE);
	}

	/* INICIAR OS WINSOCKS */
	iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
	if (iResult != 0) {
	    printf("WSAStartup failed: %d\n", iResult);
	    getchar();
	    exit(1);
	}

	/* CRIAR SOCKET PARA O ENVIO/RECEPCAO DE DATAGRAMAS */
	sockfd = socket( PF_INET , SOCK_DGRAM , 0 );
	if(sockfd == INVALID_SOCKET) {
	    Abort("Impossibilidade de criar socket");	
	}

	/* PREENCHER O ENDERECO DO SERVIDOR */
	memset( (char*)&serv_addr , 0, sizeof(serv_addr) ); /* Coloca a zero todos os bytes */
	serv_addr.sin_family = AF_INET; /* Address Family: Internet */
	serv_addr.sin_addr.s_addr = inet_addr(serv_host_addr); /* IP no formato "dotted decimal" => 32 bits */
	serv_addr.sin_port = htons(serv_udp_port); /* Host TO Netowork Short */

	/* A sugestão do professor para o exercício 3 é neste lugar...
	if (bind(sockfd, (SOCKADDR *)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR) {
		Abort("Bind Error");
	} */

	/* ENVIAR MENSAGEM AO SERVIDOR
	   info da ligação com o servidor guardada na estrutura serv_addr */
	if (sendto(sockfd, buffer, strlen(buffer), 0,
			(struct sockaddr*)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR){
	    Abort("SO nao conseguiu aceitar o datagrama");
	}

	/* 3. INFORMAÇÃO LOCAL DO SOCKET */
	sockaddr_in_len = sizeof(local_name);
	if (getsockname(sockfd, (SOCKADDR *)&local_name, &sockaddr_in_len) == SOCKET_ERROR){
	    Abort("Get Socket Name Error");
	}
	/* mostrar enderesso local - porto emissor */
	printf("<CLI1> cliente %s:%d >>>\n", inet_ntoa(local_name.sin_addr), local_name.sin_port);
	/* mostrar enderesso do servidor - porto receptor */
	printf("<CLI1> servidor %s:%d <<<\n", serv_host_addr, serv_udp_port);
	/* mostrar enderesso do servidor - porto emissor */
	printf("<CLI1> servidor %s:%d >>>\n", inet_ntoa(serv_addr.sin_addr), serv_addr.sin_port);

	printf("<CLI1> mensagem enviada\n<CLI1> a aguadar a confirmacao de entrega\n");

	/* 2. RECEBER A MENSAGEM (DE CONFIRMAÇÃO) DO SERVIDOR E MOSTRÁ-LA
	      informação da ligação que se recebe guardada na estrutura reply_addr */
	if ((nbytes = recvfrom(sockfd, buffer, sizeof(buffer), 0,
			(SOCKADDR *)& reply_addr, &sockaddr_in_len)) == SOCKET_ERROR) {
	    Abort("erro na recepcao de datagramas");
	}
	buffer[nbytes] = '\0'; /* Afixar a string recebida no buffer com '\0' */

	printf("<CLI1> recepcao da mensagem \"%s\" confirmada\n", buffer);

	/* 5. DETECTAR SE A RESPOSTA VEM DE UM IMPOSTOR
	      comparar a informação entre as estruturas serv_addr (info da ligação com o servidor)
	      e reply_addr (info da ligação de qual se recebeu a resposta) */
	if (inet_ntoa(serv_addr.sin_addr) == inet_ntoa(reply_addr.sin_addr)
			&& serv_addr.sin_port == reply_addr.sin_port)
		printf("<CLI1> servidor %s:%d >>> OK\n",
			inet_ntoa(reply_addr.sin_addr), reply_addr.sin_port);
	else
		printf("<CLI1> emissor %s:%d >>> IMPOSTOR\n",
			inet_ntoa(reply_addr.sin_addr), reply_addr.sin_port);

	/* FECHAR O SOCKET */
	closesocket(sockfd);

	exit(EXIT_SUCCESS);
}

/* Abort
   Mostra uma mensagem de erro e o código associado ao ultimo erro com Winsocks. 
   Termina a aplicacao com "exit status" a 1 (constante EXIT_FAILURE) */
void Abort(char *msg) {
	fprintf(stderr,"<CLI1>Erro Fatal: <%s> (%d)\n",msg, WSAGetLastError());
	exit(EXIT_FAILURE);
}
