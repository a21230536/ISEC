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

    /* testar a sintaxe */
    if(argc != 4) {
        fprintf(stderr, "<CLI> Sintaxe: %s <frase_a_enviar> <ip_destino> <porto_destino>\n", argv[0]);
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
    serv_addr.sin_addr.s_addr = inet_addr(argv[2]);
    serv_addr.sin_port=htons(atoi(argv[3]));

    /* ESTABELECER LIGACAO COM O SERVIDOR */
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR) {
        Abort("Impossibilidade de estabelecer ligacao", sock);
    }

    /* ENVIAR MENSAGEM AO SERVIDOR */
    sprintf_s(buffer, BUFFERSIZE, "%s\n", argv[1]);
    msg_len = strlen(buffer);
    if ((nbytes = writeN(sock, buffer, msg_len)) == SOCKET_ERROR) {
        Abort("Impossibilidade de transmitir mensagem...", sock);
    }
    else if (nbytes < msg_len) {
        fprintf(stderr, "<CLI> Mensagem truncada...\n");
    }
    else {
        fprintf(stderr, "<CLI> Mensagem \"%s\" enviada\n", argv[1]);
    }

    /* RECEBER (ESPERAR) CONFIRMAÇÃO DO SERVIDOR */
    if ((nbytes = readLine(sock, buffer, sizeof(buffer))) == SOCKET_ERROR) {
        Abort("Impossibilidade de receber confirmacao", sock);
    }

    buffer[nbytes] = '\0';
    printf("<CLI> Confirmacao recebida {%s}.\n", buffer);

    /* FECHAR O SOCKET */
    closesocket(sock);

    exit(EXIT_SUCCESS);
}
