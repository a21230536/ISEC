/* SUPPER SERVIDOR UDP
   Servidor recebe uma mensagem (ascii), converte-a em maiúsculas e devolve-a ao cliente */
#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <string.h>
#include "publico.h"

#pragma comment(lib, "ws2_32.lib")

main()
{
    SOCKET sock;
    WSADATA wsa_data;
    struct sockaddr_in servidor, cliente;
    int len, size = sizeof(struct sockaddr_in);
    char msg[256];

    /* iniciar o WinSock */
    if(WSAStartup(MAKEWORD(2,2), &wsa_data)) {
        sair("falha ao iniciar o WinSock");
    }

    /* construir o endereço do servidor */
    memset((char *) &servidor, 0, sizeof(servidor));
    servidor.sin_port = htons(SERVER_PORT);
    servidor.sin_addr.s_addr = htonl(INADDR_ANY);
    servidor.sin_family = AF_INET;

    /* criar um socket */
    if((sock = socket(PF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) {
        sair(erro(msg));
    }

    /* vincular ao socket */
    if(bind(sock, (SOCKADDR *) &servidor, sizeof(servidor)) == SOCKET_ERROR) {
        sair(erro(msg));
    }

    /* ciclo para receber>converter>enviar mensagens de clientes*/
    while(1) {
        if((len = recvfrom(sock, msg, sizeof(msg), 0, (SOCKADDR *) &cliente, &size)) == SOCKET_ERROR) {
            erro(msg);
            continue;
        }

        msg[len] = '\0';
        supper(msg);

        if(sendto(sock, msg, len, 0, (SOCKADDR *) &cliente, sizeof(cliente)) == SOCKET_ERROR) {
            erro(msg);
        }
    }
}
