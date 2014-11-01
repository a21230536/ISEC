#include <stdio.h>
#include <winsock.h>
#include <string.h>
#include "Publico.h"

#pragma comment(lib, "ws2_32.lib")

int main(){
	SOCKET sock;
	WSADATA wsadata;
	RES response;
	int wsa_result, len, msglen, salen = sizeof(struct sockaddr_in);
	char buffer[BUFFER_SIZE] = {'\0'}, noivo_ip[16];
	struct sockaddr_in server, client;

	/* inicializar o WinSock (especificação 2.2) */
	if (wsa_result = WSAStartup(MAKEWORD(2, 2), &wsadata)){
		sprintf(buffer, "ERRO WSAStartup %d", wsa_result);
		die(buffer);
	}

	/* criar um socket UDP da família Internet Protocol Family */
	if ((sock = socket(PF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET){
		die("Criar o Socket");
	}

	/* construir a estrutura do enderesso do servidor */
	//bzero((char *)&server, sizeof(server));
	memset((char *)&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(SERVER_PORT);

	/* ligar-se ao socket */
	if (bind(sock, (struct sockaddr*) &server, sizeof(server)) == SOCKET_ERROR){
		die("Ligar ao Socket");
	}

	/* casamento inicial sem noivo */
	response.casamento = FALSE;

	/* ciclo de casamentos */
	while (TRUE){
		printf("\nAguardando um%sNoivo\n", (response.casamento? " cliente para o ": " "));

		/* receber datagrama */
		if ((msglen = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockadder*)&client, &salen)) == SOCKET_ERROR){
			perror("ERRO receber datagrama");
		}

		/* TODO nao aceitar clientes locais (127.0.0.1) */

		/* mostrar a mensagem recebida */
		buffer[BUFFER_SIZE-1] = '\0';
		printf("MSG{ %s } de %s:%d\n", buffer, inet_ntoa(client.sin_addr), client.sin_port);

		/* noivar o cliente */
		if (!response.casamento){
			response.casamento = TRUE;
			response.noivo = client;//memcpy((char *)&res.noivo, (char *)&from, from_len);
			strcpy(response.msg, "Tem noivo.");
			strcpy(noivo_ip, inet_ntoa(client.sin_addr));
			printf("{ %s } >>> NOIVO\n", noivo_ip);

			/* TODO esperar 10 seg (para timeout no cliente) */

			continue;
		}

		/* comparar o enderesso do cliente com o do noivo */
		if (strcmp(noivo_ip, inet_ntoa(client.sin_addr)) == 0){
			printf("incesto nao %c permitido!\n", 130);
			continue;
		}

		/* enviar o noivo ao cliente */
		if ((len = sendto(sock, &response, sizeof(response), 0,
				(struct sockaddr *)&client, salen)) == SOCKET_ERROR){
			perror("ERRO enviar noivo ao cliente");
			continue;
		}

		/* casamento concluido no lado do servidor */
		printf("CASAMENTO!\nnoivo %s enviado ao cliente %s ...\n",
			noivo_ip, inet_ntoa(client.sin_addr));

		/* preparar outro casamento */
		response.casamento = FALSE;
	}
}
