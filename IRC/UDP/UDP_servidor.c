/* Servidor basico UDP
   Destina-se a mostrar os conteudos dos datagramas recebidos.
   O porto de escuta encontra-se definido pela constante SERV_UDP_PORT.
   Assume-se que as mensagens recebida sao cadeias de caracteres (ou seja, 
   "strings"). */
#include <stdio.h>
#include <winsock.h>
#include "Publico.h"

int main( int argc , char *argv[] ){
	SOCKET sockfd;
	int iResult, nbytes, sLen = sizeof(struct sockaddr_in);
	struct sockaddr_in serv_addr, cli_addr;
	char buffer[BUFFERSIZE];
	WSADATA wsaData;
	Res res;/* para a resposta do servidor */

	system("cls");

	/* INICIAR OS WINSOCKS */
	if (iResult = WSAStartup(MAKEWORD(2, 2), &wsaData)) {
		sprintf(buffer, "ERRO WSAStartup falhou (%d)", iResult);
		Abort(buffer);
	}

	/* CRIAR O SOCKET PARA RECEPCAO/ENVIO DE DATAGRAMAS UDP */
	if ((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET){
		Abort("ERRO Impossibilidade de abrir socket");
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
		Abort("ERRO Impossibilidade de registar-se para escuta");
	}

	/* ATENDER CLIENTES INTERACTIVAMENTE */
	while(1){
		fprintf(stdout, "<SER> Esperando um datagrama...\n");
		
		if ((nbytes = recvfrom(sockfd , buffer , sizeof(buffer) , 0,
				(struct sockaddr*)& cli_addr, &sLen)) == SOCKET_ERROR) {
		    fprintf(stderr, "<SER> ERRO recepcao de datagrama\n");
		}

		buffer[nbytes] = '\0';

		/* INFO DA MENSAGEM RECEBIDA */
		printf("<SER> Mensagem recebida {%s}\n", buffer);
		printf("<SER> IP do Cliente {%s}\n", inet_ntoa(cli_addr.sin_addr));
		printf("<SER> Porto do Cliente {%d}\n\n", cli_addr.sin_port);

		/*---------------------------------------------------------------------
		 * 10. resposta do servidor com o tamanho da mensagem em binário
		 *-------------------------------------------------------------------*/
		res.nbytes = nbytes;
		if ((nbytes = sendto(sockfd, &res, sizeof(res), 0,
				(struct sockaddr*)&cli_addr, sLen)) == SOCKET_ERROR){
			fprintf(stderr, "<SER> ERRO envio de resposta\n");
		}
	}
}
