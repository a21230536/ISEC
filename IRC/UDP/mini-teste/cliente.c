/* CLIENTE UDP - Mini-teste IRC */
#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <string.h>
#include "comum.h"

/* ligação à livraria ws2_32.lib */
#pragma comment(lib, "ws2_32.lib")

main(int argc, char *argv[])
{
    SOCKET sock;
    WSADATA wsadata;
    SOCKADDR_IN servidor, remetente;
    char msg[256];
    int wsaresult, len, size, timeout = TIMEOUT*1000*60;
    double dec;

    /* verificar os argumentos */
    if (argc != 2) {
        fprintf(stdout, "> SINTAXE: %s <msg>\n", argv[0]);
        return;
    }

    /* iniciar o WinSock */
    if (WSAStartup(MAKEWORD(2, 2), &wsadata)) {
        sprintf(msg, "falha ao iniciar o WinSock (%d)", wsaresult);
        sai(msg);
    }

    /* construir o endereço do servidor */
    memset((char *)&servidor, 0, sizeof(servidor));
    servidor.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    servidor.sin_port = htons(SERVER_PORT);
    servidor.sin_family = AF_INET;

    /* criar um Socket */
    if ((sock = socket(PF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) falha("socket");

    /* valor decimal */
    dec = atof(argv[1]);

    /* enviar a mensagem (valor binário) ao servidor */
    if (sendto(sock, &dec, sizeof(dec), 0, (SOCKADDR *)&servidor, sizeof(servidor)) == SOCKET_ERROR) falha("sendto");

    /* configurar o Socket para timeout */
    if(setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) == -1) falha("setsockopt");

    /* receber mensagem de ... */
    size = sizeof(SOCKADDR_IN);
    if ((len = recvfrom(sock, msg, sizeof(msg), 0, (SOCKADDR *)&remetente, &size)) == SOCKET_ERROR) falha("recvfrom");

    /* mostrar a mensagem recebida */
    msg[len] = '\0';
    printf("> MSG DE %s:%d\n> \"%s\"\n", inet_ntoa(remetente.sin_addr), ntohs(remetente.sin_port), msg);

    /* fechar o Socket */
    closesocket(sock);
}
