/* Cliente basico UDP
Este cliente destina-se a enviar mensagens passadas na linha de comando, sob
a forma de um argumento, para um servidor especifico cuja locacao e' dada
pelas seguintes constantes: SERV_HOST_ADDR (endereco IP) e SERV_UDP_PORT (porto)
O protocolo usado e' o UDP. */
#include <winsock.h>
#include <stdio.h>

#define SERV_UDP_PORT 5432
#define BUFFERSIZE 4096
#define SERV_HOST_ADDR "127.0.0.1"
#define TIMEOUT 10

#pragma comment(lib, "ws2_32.lib")

void Abort(char *msg);

int main(int argc, char *argv[])
{
    SOCKET sockfd;
    WSADATA wsaData;
    int iResult, nbytes, i, serv_udp_port = 0;
    int sockaddr_in_len = sizeof(struct sockaddr_in), res;
    struct sockaddr_in serv_addr, local_name, reply_addr;
    struct timeval timeout = { TIMEOUT * 1000, 0 };/* TIMEOUT em Publico.h */
    char buffer[BUFFERSIZE] = {'\0'}, serv_host_addr[16] = {'\0'};
    char sintaxe[] = "-msg <msg> [-ip <server_ip> [-port <server_port>]]";

    /* MENSAGEM/IP/PORTO RECEBIDOS POR ARGUMENTO */
    if (argc == 2) {
        strcpy(buffer, argv[1]);
    }
    else {
        for (i = 1; i < argc; i++) {
            if (strcmp("-msg", argv[i]) == 0) {
                strcpy(buffer, argv[++i]);/* ++i para saltar 1 argumento ... */
            }
            else if (strcmp("-ip", argv[i]) == 0) {
                strcpy(serv_host_addr, argv[++i]);
            }
            else if (strcmp("-port", argv[i]) == 0) {
                serv_udp_port = atoi(argv[++i]);
            }
        }
    }

    /* porto recebido por argumento? */
    if (!serv_udp_port) {
        serv_udp_port = SERV_UDP_PORT;
    }

    /* IP recebido por argumento? */
    if (!strlen(serv_host_addr)) {
        strcpy(serv_host_addr, SERV_HOST_ADDR);
    }

    /* TESTAR A SINTAXE */
    if (argc < 2 || !strlen(buffer)) {
        fprintf(stderr, "sintaxe:\n  %s <mensagem>\n", argv[0]);
        fprintf(stderr, "  %s %s\n", argv[0], sintaxe);
        exit(EXIT_FAILURE);
    }

    /* INICIAR OS WINSOCKS */
    if (iResult = WSAStartup(MAKEWORD(2, 2), &wsaData)) {
        sprintf(buffer, "ERRO WSAStartup falhou (%d)", iResult);
        Abort(buffer);
    }

    /* CRIAR SOCKET PARA O ENVIO/RECEPCAO DE DATAGRAMAS */
    if ((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) {
        Abort("impossibilidade de criar socket");
    }

    /* PREENCHER O ENDERECO DO SERVIDOR */
    memset((char *) &serv_addr, 0, sizeof(serv_addr));/* bits da struct a zero */
    serv_addr.sin_family = AF_INET;/* AF_INET := Internet (Adress Family) */
    serv_addr.sin_addr.s_addr = inet_addr(serv_host_addr);/* dotted decimal IP */
    serv_addr.sin_port = htons(serv_udp_port);/* Host TO Netowork Short */

    /* opçoes do socket (para o timeout) */
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        Abort("impossibilidade de estabelecer timeout");
    }

    /* ENVIAR MENSAGEM AO SERVIDOR
    info da ligação com o servidor guardada na estrutura serv_addr */
    if (sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR) {
        Abort("SO nao conseguiu aceitar o datagrama");
    }

    printf("<CLI> mensagem enviada\n");

    /* INFO DO CLIENTE E SERVIDOR */
    sockaddr_in_len = sizeof(local_name);
    if (getsockname(sockfd, (SOCKADDR *)&local_name, &sockaddr_in_len) == SOCKET_ERROR) {
        Abort("Get Socket Name Error");
    }
    printf("<CLI> cliente %s:%d >>>\n", inet_ntoa(local_name.sin_addr), local_name.sin_port);
    printf("<CLI> servidor %s:%d <<<\n", serv_host_addr, serv_udp_port);
    printf("<CLI> servidor %s:%d >>>\n", inet_ntoa(serv_addr.sin_addr), serv_addr.sin_port);

    printf("<CLI> a aguadar resposta do servidor...\n");

    /*-------------------------------------------------------------------------
     * 10. resposta do servidor com o tamanho da mensagem em binário
     *-----------------------------------------------------------------------*/
    if ((nbytes = recvfrom(sockfd, &res, sizeof(res), 0, (SOCKADDR *)& reply_addr, &sockaddr_in_len)) == SOCKET_ERROR) {
        if (WSAGetLastError() == WSAETIMEDOUT) {/* WSAETIMEDOUT := 10060 */
            Abort("TIMEOUT na resposta");
        }
        else {
            Abort("ERRO leitura (rececao) resposta");
        }
    }
    else {
        printf("<SRV> nbytes: %d\n", res);
    }

    /* A RESPOSTA VEM DE UM IMPOSTOR? */
    if (inet_ntoa(serv_addr.sin_addr) == inet_ntoa(reply_addr.sin_addr) && serv_addr.sin_port == reply_addr.sin_port) {
        printf("<CLI> servidor %s:%d >>> OK\n", inet_ntoa(reply_addr.sin_addr), reply_addr.sin_port);
    }
    else {
        printf("<CLI> emissor %s:%d >>> IMPOSTOR\n", inet_ntoa(reply_addr.sin_addr), reply_addr.sin_port);
    }

    /* FECHAR O SOCKET */
    closesocket(sockfd);

    exit(EXIT_SUCCESS);
}

void Abort(char *msg)
{
    fprintf(stderr, "<CLI1> Erro fatal: <%s> (%d)\n", msg, WSAGetLastError());
    exit(EXIT_FAILURE);
}
