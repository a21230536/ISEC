/* Cliente basico UDP
   Este cliente destina-se a enviar mensagens passadas na linha de comando.
   As mensagens são nostradas no servidor <SERV_UDP_ADDR>:<SERV_UDP_PORT>. */
#include <winsock.h>
#include <stdio.h>
#include "Publico.h"

int main( int argc , char *argv[] ){
	SOCKET sockfd;
	WSADATA wsaData;
	int iResult, nbytes;
	struct sockaddr_in serv_addr, local_name, reply_addr, noivo_addr;
	struct timeval timeout = { TIMEOUT * 1000, 0 };/* TIMEOUT em Publico.h */
	char buffer[BUFFERSIZE] = {'\0'};
	char serv_host_addr[16] = {'\0'};
	char sintaxe[] = "-msg <msg> [-ip <server_ip> [-port <server_port>]]";
	int i, serv_udp_port = 0, sockaddr_in_len = sizeof(struct sockaddr_in);

	/* MENSAGEM/IP/PORTO RECEBIDOS POR ARGUMENTO */
	if(argc == 2) strcpy(buffer, argv[1]);
	else for (i = 1; i < argc; i++) {
		if (strcmp("-msg", argv[i]) == 0){
			/* ++i para saltar 1 argumento ... */
			strcpy(buffer, argv[++i]);
		}
		else if (strcmp("-ip", argv[i]) == 0){
			strcpy(serv_host_addr, argv[++i]);
		}
		else if (strcmp("-port", argv[i]) == 0){
			serv_udp_port = atoi(argv[++i]);
		}	
	}

	/* porto r IP recebidos por argumento? */
	if (!serv_udp_port) serv_udp_port = SERV_UDP_PORT;
	if (!strlen(serv_host_addr)) strcpy(serv_host_addr, SERV_HOST_ADDR);

	/* TESTAR A SINTAXE */
	if (argc < 2 || !strlen(buffer)){
		fprintf(stderr, "sintaxe:\n  %s <mensagem>\n", argv[0]);
		fprintf(stderr, "  %s %s\n", argv[0], sintaxe);
		exit(EXIT_FAILURE);
	}

	/* INICIAR OS WINSOCKS */
	if (iResult = WSAStartup(MAKEWORD(2,2), &wsaData)) {
		sprintf(buffer, "ERRO WSAStartup falhou (%d)", iResult);
		Abort(buffer);
	}

	/* CRIAR SOCKET PARA O ENVIO/RECEPCAO DE DATAGRAMAS */
	if ((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) {
		Abort("Impossibilidade de criar socket");
	}
		
	/* PREENCHER O ENDERECO DO SERVIDOR */
	memset((char*)&serv_addr, 0, sizeof(serv_addr));/* bits da struct a zero */
	serv_addr.sin_family = AF_INET;/* AF_INET := Internet (Adress Family) */
	serv_addr.sin_addr.s_addr = inet_addr(serv_host_addr);/* dotted decimal IP */
	serv_addr.sin_port = htons(serv_udp_port);/* Host TO Netowork Short */

	/* opçoes do socket (para o timeout) */
	if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout,
			sizeof(timeout)) == -1){
		Abort("ERRO impossibilidade de estabelecer timeout");
	}
		
	/* ENVIAR MENSAGEM AO SERVIDOR
	   info da ligação com o servidor guardada na estrutura serv_addr */
	if (sendto(sockfd, buffer, strlen(buffer), 0,
			(struct sockaddr*)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR){
		Abort("SO nao conseguiu aceitar o datagrama");
	}
	
	printf("<CLI> mensagem enviada\n");

	/* INFO DO CLIENTE E SERVIDOR */
	sockaddr_in_len = sizeof(local_name);
	if (getsockname(sockfd, (SOCKADDR *)&local_name,
			&sockaddr_in_len) == SOCKET_ERROR){
		Abort("Get Socket Name Error");
	}
	printf("<CLI> cliente %s:%d >>>\n", inet_ntoa(local_name.sin_addr),
		local_name.sin_port);
	printf("<CLI> servidor %s:%d <<<\n", serv_host_addr, serv_udp_port);
	printf("<CLI> servidor %s:%d >>>\n", inet_ntoa(serv_addr.sin_addr),
		serv_addr.sin_port);

	printf("<CLI> a aguadar Noivo...\n");

	/*-------------------------------------------------------------------------
	 * 11. casamenteiro
	 *-----------------------------------------------------------------------*/
	if ((nbytes = recvfrom(sockfd, &noivo_addr, sizeof(noivo_addr), 0,
			(SOCKADDR *)& reply_addr, &sockaddr_in_len)) == SOCKET_ERROR) {
		/* WSAETIMEDOUT := 10060 */
		if (WSAGetLastError() == WSAETIMEDOUT) {
			Abort("TIMEOUT ficou Noivo?");
		}
		else Abort("ERRO a receber Noivo");
	}
	else{
		puts("<CLI> Noivo recebido");
		printf("<CLI> IP do Noivo {%s}\n", inet_ntoa(noivo_addr.sin_addr));
		printf("<CLI> Porto do Noivo {%d}\n\n", noivo_addr.sin_port);
	}

	/* SERVIDOR IMPOSTOR */
	if (!(inet_ntoa(serv_addr.sin_addr) == inet_ntoa(reply_addr.sin_addr)
			&& serv_addr.sin_port == reply_addr.sin_port)){
		printf("<CLI> emissor %s:%d >>> IMPOSTOR\n",
			inet_ntoa(reply_addr.sin_addr), reply_addr.sin_port);
	}

	closesocket(sockfd);

	exit(EXIT_SUCCESS);
}
