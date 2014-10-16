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
	int msg_len, iResult, nbytes;
	struct sockaddr_in serv_addr;

	/* 3. Variáveis necessárias para o exercício 3 */
	struct sockaddr_in local_name;
	int namelen;

	char buffer[BUFFERSIZE];
	WSADATA wsaData;

	/* TESTAR A SINTAXE */
	if(argc != 2){
	    fprintf(stderr,"Sintaxe: %s frase_a_enviar\n",argv[0]);
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
	serv_addr.sin_addr.s_addr = inet_addr(SERV_HOST_ADDR); /* IP no formato "dotted decimal" => 32 bits */
	serv_addr.sin_port = htons(SERV_UDP_PORT); /* Host TO Netowork Short */

	/* A sugestão do professor para o exercício 3 é neste lugar...
	if (bind(sockfd, (SOCKADDR *)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR) {
		Abort("Bind Error");
	} */

	/* ENVIAR MENSAGEM AO SERVIDOR */
	msg_len = strlen(argv[1]);
	if(sendto(sockfd , argv[1], msg_len, 0, (struct sockaddr*)&serv_addr , sizeof(serv_addr)) == SOCKET_ERROR){
	    Abort("SO nao conseguiu aceitar o datagrama");
	}

	/* 3. MOSTRAR O PORTO LOCAL DO SOCKET */
	namelen = sizeof(local_name);
	if (getsockname(sockfd, (SOCKADDR *)&local_name, &namelen) == SOCKET_ERROR){
	    Abort("Get Socket Name Error");
	}
	printf("<CLI1> Porto Local {%d}\n", local_name.sin_port);


	printf("<CLI1> Mensagem enviada\n<CLI1> A aguadar confirmacao de entrega...\n");

	/* 2. RECEBER A MENSAGEM (DE CONFIRMAÇÃO) DO SERVIDOR E MOSTRÁ-LA */
	if ((nbytes = recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL)) == SOCKET_ERROR) {
	    Abort("Erro na recepcao de datagrams");
	}
	buffer[nbytes] = '\0'; /* Afixar a string recebida no buffer com '\0' */
	printf("<SER1> Mensagem \"%s\" recebida.\n", buffer);

	/* FECHAR O SOCKET */
	closesocket(sockfd);

	printf("\n");
	exit(EXIT_SUCCESS);
}

/* Abort
   Mostra uma mensagem de erro e o código associado ao ultimo erro com Winsocks. 
   Termina a aplicacao com "exit status" a 1 (constante EXIT_FAILURE) */
void Abort(char *msg) {
	fprintf(stderr,"<CLI1>Erro fatal: <%s> (%d)\n",msg, WSAGetLastError());
	exit(EXIT_FAILURE);
}
