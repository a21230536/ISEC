#include <stdio.h>
#include <winsock.h>
#include <string.h>
#include "Publico.h"

#pragma comment(lib, "ws2_32.lib")

int main(int argc, char *argv[])
{
    WSADATA wsadata;
    SOCKET sock;
    RES response;
    struct sockaddr_in server, noivo;
    struct timeval timeout = { TIMEOUT*1000, 0 };
    int wsaresult, salen = sizeof(struct sockaddr_in), i, server_port = 0;
    char buffer[BUFFER_SIZE], server_addr[16];

    /* Sintaxe */
    if (argc == 1) {
        printf("Uso: %s -msg <msg> -ip <IP> -port <port>\n", argv[0]);
        return 1;
    }

    strcpy(buffer, "Quero casar.");

    /* argumentos */
    if (argc == 2) {
        strcpy(buffer, argv[1]);
    }
    else {
        for (i = 1; i < argc; i++) {
            if (strcmp("-msg", argv[i]) == 0  && strlen(argv[i]) < BUFFER_SIZE) {
                /* ++i para saltar 1 argumento ... */
                strcpy(buffer, argv[++i]);
            }
            else if (strcmp("-ip", argv[i]) == 0 && strlen(argv[i]) < 16) {
                strcpy(server_addr, argv[++i]);
            }
            else if (strcmp("-port", argv[i]) == 0) {
                server_port = atoi(argv[++i]);
            }
        }
    }

    if (!server_port) server_port = SERVER_PORT;
    if (!strlen(server_addr)) strcpy(server_addr, SERVER_ADDR);

    /* inicializar o WinSock */
    if (wsaresult = WSAStartup(MAKEWORD(2,2), &wsadata)) {
        sprintf(buffer, "Falha WSAStartup %d", wsaresult);
        die(buffer);
    }

    /* criar um socket UDP */
    if ((sock = socket(PF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) {
        die("Socket Invalido");
    }

    /* construir a estrutura de endereço do servidor */
    memset((char *) &server, 0, sizeof(server));
    server.sin_family = PF_INET;
    server.sin_addr.s_addr = inet_addr(server_addr);
    server.sin_port = htons(server_port);

    /* configurar o socket para o timeout */
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        die("Configurar o Socket");
    }

    /* usar o socket para enviar a mensagem ao servidor */
    if (sendto(sock, buffer, strlen(buffer), 0, (SOCKADDR*) &server, sizeof(server)) == SOCKET_ERROR) {
        die("Enviar um Datagrama ao Servidor");
    }

    /* aguardar resposta do servidor */
    printf("A aguardar resposta do servidor ...\n");
    if (recvfrom(sock, &response, sizeof(response), 0, (SOCKADDR*) &server, &salen) == SOCKET_ERROR) {
        /* o erro não foi por timeout */
        if (WSAGetLastError() != WSAETIMEDOUT) {
            die("Receber resposta do Servidor");
        }

        /* FICOU NOIVO */

        /* reconfigurar o socket para timeout do noivo */
        timeout.tv_sec = 10 * 60 * 1000;
        if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
            die("Reconfigurar o Socket");
        }

        printf("A aguadar noivo ...\n");

        if (recvfrom(sock, &response, sizeof(response), 0, (SOCKADDR*) &noivo, &salen) != SOCKET_ERROR){
            printf("MSG do Noivo %s:%d { %s }\n", inet_ntoa(noivo.sin_addr), noivo.sin_port, response.msg);
            exit(0);
        }

        if (WSAGetLastError() == WSAETIMEDOUT) {
            die("TIMEOUT a Esperar o Noivo");
        }

        die("Falha a Receber Noivo");
    }

    printf("MSG do Casamenteiro { %s }\nA contactar o noivo %s:%d ...\n", response.msg,
        inet_ntoa(response.noivo.sin_addr), response.noivo.sin_port);

    /* "dar o nó" */
    sprintf(response.msg, "Toma l%c o n%c.", 160, 162);
    if (sendto(sock, &response, sizeof(response), 0, (SOCKADDR*) &response.noivo, &salen) == SOCKET_ERROR) {
        die("Contactar Noivo");
    }

    printf("N%c dado!\n", 162);

    closesocket(sock);

    exit(0);
}
