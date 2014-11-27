/* 
 * Cliente basico TCP
 * ------------------
 * Este cliente destina-se a enviar mensagens passadas na linha de comando, sob
 * a forma de um argumento, para um servidor especifico cuja localizacao e' fornecida
 * através da linha de comando. Também é aguardada confirmacao (trata-se do 
 * comprimento da mensagem).
 *
 * O protocolo usado e' o TCP.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "comum.h"

#pragma comment(lib, "Ws2_32.lib")

int main(int argc, char *argv[])
{
    int sock = INVALID_SOCKET;
    int msg_len, nbytes, iResult;
    struct sockaddr_in serv_addr;
    char buffer[BUFFERSIZE];
    WSADATA wsaData;
    struct hostent *server_host;

    /* testar a sintaxe */
    if(argc != 4) {
        fprintf(stderr, "<CLI> Sintaxe: %s <mensagem> <servidor> <porto>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* INICIAR WINSOCK */
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed: %d\n", iResult);
        getchar();
        exit(1);
    }

    /* ABRIR UM SOCKET PARA CONTACTAR O SERVIDOR */
    if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET) {
        Abort("Impossibilidade de abrir socket", sock);
    }

    /* CONSTRUIR O ENDEREÇO DO SERVIDOR */
    memset((char*)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[3]));

    /* o endereço do servidor é alfanumérico? */
    if (isalpha(argv[2][0])) {
        server_host = gethostbyname(argv[2]);
        if (server_host == NULL) {
            switch (WSAGetLastError()) {
            case WSAHOST_NOT_FOUND:
                Abort("HOST NAO ENCONTRADO", sock);
            case WSANO_DATA:
                Abort("NENHUM REGISTO ENCONTRADO", sock);
            default:
                Abort("(gethostbyaddr)", sock);
            }
        }
        if (server_host->h_addrtype == AF_INET && server_host->h_addr_list[0] != 0) {
            serv_addr.sin_addr.s_addr = *(u_long *)server_host->h_addr_list[0];
            //printf("> IP address: %s\n", inet_ntoa(serv_addr.sin_addr));
        }
    }
    else serv_addr.sin_addr.s_addr = inet_addr(argv[2]);

    /* ESTABELECER LIGACAO COM O SERVIDOR */
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR) {
        Abort("Impossibilidade de estabelecer ligacao", sock);
    }

    sprintf_s(buffer, BUFFERSIZE, "%s\n", argv[1]);

    while (1) {
        /* ENVIAR MENSAGEM AO SERVIDOR */
        msg_len = strlen(buffer);
        if ((nbytes = writeN(sock, buffer, msg_len)) == SOCKET_ERROR) {
            Abort("Impossibilidade de transmitir mensagem...", sock);
        }
        else if (nbytes < msg_len) {
            fprintf(stderr, "<CLI> Mensagem truncada...\n");
        }
        else {
            fprintf(stderr, "<CLI> Mensagem enviada");
        }

        /* "SAIR\n"? */
        if (strcmp(buffer, "SAIR\n") == 0) break;

        /* RECEBER (ESPERAR) CONFIRMAÇÃO DO SERVIDOR */
        if ((nbytes = readLine(sock, buffer, sizeof(buffer))) == SOCKET_ERROR) {
            Abort("Impossibilidade de receber confirmacao", sock);
        }

        buffer[nbytes] = '\0';
        printf("<CLI> Confirmacao recebida {%s}.\n", buffer);

        printf("<CLI> MSG: ");
        gets_s(buffer, BUFFERSIZE - 1);
    }

    /* FECHAR O SOCKET */
    closesocket(sock);

    exit(EXIT_SUCCESS);
}
