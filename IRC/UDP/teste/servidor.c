/* SERVIDOR UDP - Mini-teste IRC */
#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <string.h>
#include "comum.h"

/* ligação à livraria ws2_32.lib */
#pragma comment(lib, "ws2_32.lib")

main()
{
    SOCKET sock;
    WSADATA wsadata;
    struct sockaddr_in servidor, clis[N];
    int wsaresult, size = sizeof(struct sockaddr_in), n = 0;
    char msg[256];
    double dec, total;

    /* iniciar o WinSock */
    if (wsaresult = WSAStartup(MAKEWORD(2, 2), &wsadata)) {
        sprintf(msg, "falha ao iniciar o WinSock (%d)", wsaresult);
        sai(msg);
    }

    /* construir o endereço do servidor */
    memset((char *) &servidor, 0, sizeof(servidor));
    servidor.sin_port = htons(SERVER_PORT);
    servidor.sin_addr.s_addr = htonl(INADDR_ANY);
    servidor.sin_family = AF_INET;

    /* criar um socket */
    if((sock = socket(PF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) falha("socket");

    /* vincular ao socket */
    if (bind(sock, (SOCKADDR *)&servidor, sizeof(servidor)) == SOCKET_ERROR) falha("bind");

    /* ciclo para receber o valor decimal de N clientes */
    while (1) {
        total = 0.0;
        for (n = 0; n < N; n++) {
            if(recvfrom(sock, (char*)&dec, sizeof(dec), 0, (SOCKADDR *) &clis[n], &size) == SOCKET_ERROR) {
                erro(msg);
                continue;
            }

            /* adicionar o valor decimal ao total */
            total += dec;
            printf("> %d DEC DE %s:%d %f\n", n+1, inet_ntoa(clis[n].sin_addr), ntohs(clis[n].sin_port), dec);
        }

        /* informar os clientes do valor total */
        sprintf(msg, "total %f de %d valores", total, N);
        printf("> TOTAL %f\n", total);
        for (n = 0; n < N; n++) {
            if(sendto(sock, msg, strlen(msg), 0, (SOCKADDR *) &clis[n], sizeof(clis[n])) == SOCKET_ERROR) erro(msg);
        }
    }
}
