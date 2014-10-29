/* Servidor basico UDP
   Destina-se a mostrar os conteudos dos datagramas recebidos.
   O porto de escuta encontra-se definido pela constante SERV_UDP_PORT.
   Assume-se que as mensagens recebida sao cadeias de caracteres (ou seja, 
   "strings"). */
#include <stdio.h>
#include <winsock.h>

#pragma comment(lib, "ws2_32.lib")

#define SERV_UDP_PORT 5432
#define BUFFERSIZE 4096

void Abort(char *msg);

int main( int argc , char *argv[] ){
	SOCKET sockfd;
	int iResult, nbytes, sLen = sizeof(struct sockaddr_in);
	struct sockaddr_in serv_addr, cli_addr;
	char buffer[BUFFERSIZE];
	WSADATA wsaData;

	/* para o exercício 9 */
	char tam[16];

	/* Executar o commando de sistema "cls" para limpar a consola */
	system("cls");

	/* INICIAR OS WINSOCKS */
	iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
	if (iResult != 0) {
	    printf("WSAStartup failed: %d\n", iResult);
	    getchar();
	    exit(1);
	}

	/* CRIAR O SOCKET PARA RECEPCAO/ENVIO DE DATAGRAMAS UDP */
	if ((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET){
	    Abort("Impossibilidade de abrir socket");
	}

	/* ASSOCIAR O SOCKET AO  ENDERECO DE ESCUTA
	   Define que pretende receber datagramas vindos de qualquer interface de
	   rede, no porto pretendido */
	memset( (char*)&serv_addr , 0, sizeof(serv_addr) );
	serv_addr.sin_family = AF_INET; /* Address Family: Internet */
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);  /* Host TO Network Long */
	serv_addr.sin_port = htons(SERV_UDP_PORT);  /* Host TO Network Short */

	/* Associar o socket ao porto pretendido */
	if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR) {
	    Abort("Impossibilidade de registar-se para escuta");
	}

	/* ATENDER OS CLIENTES INTERACTIVAMENTE */
	while(1){
		fprintf(stderr,"<SER1> Esperando um datagrama...\n");

		nbytes = recvfrom(sockfd , buffer , sizeof(buffer) , 0 , (struct sockaddr*)& cli_addr, &sLen);
		
		/*----------------------------------------------------------------------------
		 * 2. ENVIAR A MENSAGEM (DE VOLTA) AO CLIENTE
		 * sendto(sockfd, buffer, nbytes, 0, (struct sockaddr*)&cli_addr, sLen);
		 *--------------------------------------------------------------------------*/

		/*----------------------------------------------------------------------------
		* 9. resposta do servidor com o tamanho da mensagem em ascii
		*--------------------------------------------------------------------------*/
		sprintf(tam, "%d", nbytes);
		sendto(sockfd, tam, strlen(tam), 0, (struct sockaddr*)&cli_addr, sLen);
		
		if (nbytes == SOCKET_ERROR) {
		    Abort("Erro na recepcao de datagramas");
		}
			
		buffer[nbytes]='\0'; /* Termina a cadeia de caracteres recebidos com '\0' */
		
		/* 1. MOSTRAR A MENSAGEM RECEBIDA */
		printf("<SER1> Mensagem recebida {%s}\n", buffer);

		/* 4. MOSTRAR INFORMAÇÃO DO CLIENTE */
		printf("<SER1> IP do Cliente {%s}\n", inet_ntoa(cli_addr.sin_addr));
		printf("<SER1> Porto do Cliente {%d}\n\n", cli_addr.sin_port);
	}
}

/* Abort
 * Mostra uma mensagem de erro e o código associado ao ultimo erro com Winsocks. 
 * Termina a aplicacao com "exit status" a 1 (constante EXIT_FAILURE)
 */
void Abort(char *msg) {
	fprintf(stderr, "<CLI1> Erro fatal: <%s> (%d)\n", msg, WSAGetLastError());
	exit(EXIT_FAILURE);
}
