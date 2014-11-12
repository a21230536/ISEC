/* 
 * Servidor interactivo TCP
 * ------------------------
 * Este servidor destina-se mostrar mensagens recebidas via TCP, no porto
 * definido pela constante SERV_TCP_PORT.
 * Trata-se de um servidor que envia confirmacao (o comprimento, em bytes, da
 * mensagem recebida).
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comum.h"

#pragma comment(lib, "Ws2_32.lib")

int main()
{
    SOCKET sock = INVALID_SOCKET, newSock = INVALID_SOCKET;
    int iResult;
    int cliaddr_len;    
    struct sockaddr_in cli_addr,serv_addr;
    WSADATA wsaData;

    /* INICIA OS WINSOCKS */
    if (iResult = WSAStartup(MAKEWORD(2,2), &wsaData)) {
        printf("WSAStartup failed: %d\n", iResult);
        getchar();
        exit(1);
    }

    /* ABRE SOCKET PARA ESCUTA DE CLIENTES */
    if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET) {
        Abort("Impossibilidade de abrir socket", sock);
    }

    /* PREENCHE ENDERECO DE ESCUTA */
    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);/* INADDR_ANY para receber pedidos em qualquer interface */
    serv_addr.sin_port = htons(SERV_TCP_PORT);

    /* REGISTA-SE PARA ESCUTA */
    if (bind(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR) {
        Abort("Impossibilidade de registar-se para escuta", sock);
    }

    /* AVISA QUE ESTA PRONTO A ACEITAR PEDIDOS */
    if(listen(sock, 5) == SOCKET_ERROR) Abort("Impossibilidade de escutar pedidos", sock);

    /* PASSAR A ATENDER CLIENTES INTERACTIVAMENTE */
    cliaddr_len = sizeof(cli_addr);
    while(1) {
        /* ATENDER PEDIDO */
        if ((newSock = accept(sock, (struct sockaddr *)&cli_addr, &cliaddr_len)) == SOCKET_ERROR) {
            fprintf(stderr,"<SERV> Impossibilidade de aceitar cliente...\n");
        }
        else {
            AtendeCliente(newSock);
            closesocket(newSock);
        }
    }
}
