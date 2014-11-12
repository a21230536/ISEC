/* IRC UDP Exercício 11 - CASAMENTEIRO CLIENTE */
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
    struct timeval timeout = { TIMEOUT * 1000 * 60, 0 };
    struct sockaddr_in server, from;
    int wsaresult, salen = sizeof(struct sockaddr_in), i, server_port = 0;
    char msg[256] = {'\0'}, server_addr[16], from_addr[16];

    /* argumentos */
    if (argc < 3) {
        printf("Sintaxe: %s -msg <msg> -ip <IP> -port <port>\n", argv[0]);
        return 1;
    }
    else {
        for (i = 1; i < argc; i++) {
            if (strcmp("-msg", argv[i]) == 0  && strlen(argv[i]) < BUFFER_SIZE) {
                strcpy(msg, argv[++i]);/* ++i para saltar 1 argumento ... */
            }
            else if (strcmp("-ip", argv[i]) == 0 && strlen(argv[i]) < 16) {
                strcpy(server_addr, argv[++i]);
            }
            else if (strcmp("-port", argv[i]) == 0) {
                server_port = atoi(argv[++i]);
            }
        }
    }

    /* argumentos por defeito */
    if (!strlen(msg)) sprintf(msg, "Quero dar o n%c.", 162);
    if (!server_port) server_port = SERVER_PORT;
    if (!strlen(server_addr)) strcpy(server_addr, SERVER_ADDR);

    /* inicializar o WinSock */
    if (wsaresult = WSAStartup(MAKEWORD(2,2), &wsadata)) {
        sprintf(msg, "Falha WSAStartup %d", wsaresult);
        die(msg);
    }

    /* criar um socket */
    if ((sock = socket(PF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) {
        die("Socket Invalido");
    }

    /* construir o endereço do servidor */
    memset((char *) &server, 0, sizeof(server));
    server.sin_family = PF_INET;
    server.sin_addr.s_addr = inet_addr(server_addr);
    server.sin_port = htons(server_port);

    /* configurar o socket para timeout */
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        die("Configurar o Socket");
    }

    /* usar o socket para enviar a mensagem ao servidor */
    if (sendto(sock, msg, strlen(msg), 0, (SOCKADDR*) &server, sizeof(server)) == SOCKET_ERROR) {
        die("Enviar um Datagrama ao Servidor");
    }

    /* receber datagrama de ...? */
    printf("> a aguardar datagrama ...\n");
    if (recvfrom(sock, &response, sizeof(response), 0, (SOCKADDR*) &from, &salen) == SOCKET_ERROR) {
        if (WSAGetLastError() == WSAETIMEDOUT) {
            die("TIMEOUT - sem noivo");
        }

        die("receber de ?...");
    }

    /* conteúdo do datagrama */
    if (!response.casamento) {
        die(response.msg);
    }
    printf("> DATAGRAMA DE %s:%d\n", inet_ntoa(from.sin_addr), ntohs(from.sin_port));
    printf("> MSG: \"%s\"\n", response.msg);
    printf("> CASAMENTO: %d\n", response.casamento);
    printf("> NOIVO: %s:%d\n", inet_ntoa(response.noivo.sin_addr), ntohs(response.noivo.sin_port));
    
    /* verificar se o datagrama veio do servidor */
    strcpy(from_addr, inet_ntoa(from.sin_addr));
    if (strcmp(server_addr, from_addr) == 0 && server_port == ntohs(from.sin_port)) {
        printf("> a dar o n%c ...\n", 162);
        
        /* enviar o datagrama ao noivo */
        sprintf(response.msg, "toma l%c o n%c", 160, 162);
        if (sendto(sock, &response, sizeof(response), 0, (SOCKADDR*)&response.noivo, &salen) == SOCKET_ERROR) {
            die("contactar o noivo");
        }
    }
    else {
        printf("> n%c recebido\n", 162);
    }

    printf("> n%c concluido!\n", 162);

    closesocket(sock);

    exit(0);
}
