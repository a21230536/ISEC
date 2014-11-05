/* SUPPER CLIENTE UDP
   Servidor recebe uma mensagem (ascii), converte-a em maiúsculas e devolve-a ao cliente */
#include <stdio.h>
#include <winsock.h>
#include <string.h>
#include "publico.h"

#pragma comment(lib, "ws2_32.lib")

main(int argc, char *argv[])
{
    SOCKET sock;
    WSADATA wsadata;
    SOCKADDR_IN servidor, remetente;
    char msg[256];
    int len, size;

    /* iniciar WinSock */
    if (WSAStartup(MAKEWORD(2, 2), &wsadata)) {
        sair("falha ao iniciar o WinSock");
    }

    /* construir o endereço do servidor */
    memset((char *)&servidor, 0, sizeof(servidor));
    servidor.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    servidor.sin_port = htons(SERVER_PORT);
    servidor.sin_family = AF_INET;

    /* criar um Socket */
    if ((sock = socket(PF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) {
        falha("socket");
    }

    /* mensagem */
    printf("> MSG: ");
    gets(msg);

    /* enviar a mensagem ao servidor */
    if (sendto(sock, msg, strlen(msg), 0, (SOCKADDR *)&servidor, sizeof(servidor)) == SOCKET_ERROR) {
        falha("sendto");
    }

    /* receber mensagem do servidor */
    size = sizeof(SOCKADDR_IN);
    if ((len = recvfrom(sock, msg, sizeof(msg), 0, (SOCKADDR *)&remetente, &size)) == SOCKET_ERROR) {
        falha("recvfrom");
    }

    msg[len] = '\0';

    /* mostrar a mensagem recebida */
    printf("> MSG FROM %s:%d\n", inet_ntoa(remetente.sin_addr), ntohs(remetente.sin_port));
    printf("> \"%s\"\n", msg);

    /* fechar o Socket */
    closesocket(sock);
}
