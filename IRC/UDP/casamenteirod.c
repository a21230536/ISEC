/* IRC UDP Exercício 11 - CASAMENTEIRO SERVIDOR */
#include <stdio.h>
#include <winsock.h>
#include <string.h>
#include "Publico.h"

#pragma comment(lib, "ws2_32.lib")

int main()
{
    SOCKET sock;
    WSADATA wsadata;
    RES response;
    int wsa_result, len, salen = sizeof(struct sockaddr_in);
    char buffer[BUFFER_SIZE] = {'\0'};
	char addrs[2][16];
    struct sockaddr_in servidor, cliente;

    /* inicializar o WinSock (especificação 2.2) */
    if (wsa_result = WSAStartup(MAKEWORD(2,2), &wsadata)) {
        sprintf(buffer, "ERRO WSAStartup %d", wsa_result);
        die(buffer);
    }

    /* criar um socket UDP da família Internet Protocol Family */
    if ((sock = socket(PF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) {
        die("Criar o Socket");
    }

    /* construir a estrutura do enderesso do servidor */
    memset((char *) &servidor, 0, sizeof(servidor));
    servidor.sin_family = AF_INET;
    servidor.sin_addr.s_addr = INADDR_ANY;
    servidor.sin_port = htons(SERVER_PORT);

    /* ligar-se ao socket */
    if (bind(sock, (struct sockaddr*) &servidor, sizeof(servidor)) == SOCKET_ERROR) {
        die("Ligar ao Socket");
    }

    /* casamento inicial sem noivo */
    response.casamento = FALSE;

    /* ciclo de casamentos */
    while (TRUE) {
        printf("> aguardando um%snoivo\n", (response.casamento? " cliente para o ": " "));

        /* receber datagrama */
        if ((len = recvfrom(sock, buffer, sizeof(buffer), 0, (SOCKADDR *) &cliente, &salen)) == SOCKET_ERROR) {
            perror("ERRO receber datagrama");
        }

        /* mostrar a mensagem recebida */
        buffer[len] = '\0';
		printf("> DATAGRAMA DE %s:%d\n", inet_ntoa(cliente.sin_addr), htons(cliente.sin_port));
        printf("> MSG: \"%s\"\n", buffer);

        /* cliente fica noivo */
        if (!response.casamento) {
            response.casamento = TRUE;
            response.noivo = cliente;
            strcpy(response.msg, "tem noivo");
			strcpy(addrs[0], inet_ntoa(cliente.sin_addr));
            printf("> NOIVO: %s:%d\n", inet_ntoa(cliente.sin_addr), htons(cliente.sin_port));

            continue;
        }

        /* comparar o endereço do cliente com o do noivo */
		strcpy(addrs[1], inet_ntoa(cliente.sin_addr));
		if ((len = strcmp(addrs[0], addrs[1])) == 0) {
			response.casamento = FALSE;
			sprintf(response.msg, "incesto nao %c permitido!", 130);
			printf("> %s\n", response.msg);

			/* enviar aviso ao cliente */
			if (sendto(sock, &response, sizeof(response), 0, (SOCKADDR *)&cliente, salen) == SOCKET_ERROR) {
				perror("ERRO enviar noivo ao cliente");
			}

			response.casamento = TRUE;
			continue;
		}

		printf("len=%d | 0:%s 1:%s\n", len, addrs[0], addrs[1]);

        /* enviar o noivo ao cliente */
        if (sendto(sock, &response, sizeof(response), 0, (SOCKADDR *) &cliente, salen) == SOCKET_ERROR) {
            perror("ERRO enviar noivo ao cliente");
            continue;
        }

        /* nó concluido no lado do servidor */
		printf("> CASAMENTO! %s >>> %s\n", inet_ntoa(response.noivo.sin_addr), inet_ntoa(cliente.sin_addr));

        /* preparar outro casamento */
        response.casamento = FALSE;
    }
}
