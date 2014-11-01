/* CASAMENTEIRO CLIENTE - SIMPLEX */
#include <stdio.h>
#include <winsock.h>
#include <string.h>

#pragma comment(lib, "ws2_32.lib")

void die(char *msg)
{
    fprintf(stderr, "ERRO <%s> (%d)\n", msg, WSAGetLastError());
    exit(-1);
}

main(int argc, char *argv[])
{
    SOCKET sock;
    WSADATA wsa_data;
    struct sockaddr_in servidor, remetente, par;
    int wsa_result, sa_len = sizeof(struct sockaddr_in);
    char msg[256];

    if (argc < 4) {
        printf("> Uso: %s <mensagem> <endereco ip> <porto>\n", argv[0]);
        exit(1);
    }

    /* Inicializar WinSock */
    if (wsa_result = WSAStartup(MAKEWORD(2, 2), &wsa_data)) {
        sprintf(msg, "Falha <%d> a Inicializar WinSock", wsa_result);
        die(msg);
    }

    /* Criar Socket */
    if ((sock = socket(PF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) {
        die("Falha a Criar Socket");
    }

    /* Contruir Estrutura de Endereço (do Servidor) */
    memset((char *)&servidor, 0, sizeof(servidor));
    servidor.sin_family = AF_INET;
    servidor.sin_addr.s_addr = inet_addr(argv[2]);
    servidor.sin_port = htons(atoi(argv[3]));

    /* Enviar Mensagem ao Servidor */
    if (sendto(sock, argv[1], strlen(argv[1]), 0, (SOCKADDR*)&servidor, sa_len) == SOCKET_ERROR) {
        die("Falha a Enviar Mensagem ao Servidor");
    }

    /* Receber a Estrutura de Endereço do Socket */
    puts("> esperando o meu par");
    if (recvfrom(sock, &par, sa_len, 0, (SOCKADDR*)&remetente, &sa_len) == SOCKET_ERROR) {
        die("Falha a Receber Mensagem");
    }

    /* Verificar de quem se recebeu a Estrutura */
    if (strcmp(argv[2], inet_ntoa(remetente.sin_addr)) == 0 && atoi(argv[3]) == ntohs(remetente.sin_port)) {
        /* Mensagem Recebida do Servidor */
        printf("> o meu par - %s:%d\n", inet_ntoa(par.sin_addr), ntohs(par.sin_port));
        
        /* Encaminhar a estrutura ao Par */
        puts("> a contactar o meu par ...");
        if (sendto(sock, &par, sa_len, 0, (SOCKADDR*)&par, sa_len) == SOCKET_ERROR) {
            die("Falha a Enviar Mensagem ao Par");
        }

        printf(">\n> n%c dado\n", 162);
    }
    else {
        /* Mensagenm Recebida do Par */
        printf("> o meu par - %s:%d\n", inet_ntoa(remetente.sin_addr), ntohs(remetente.sin_port));
        printf("> o meu Endereco - %s:%d\n", inet_ntoa(par.sin_addr), ntohs(par.sin_port));

        printf(">\n> n%c recebido\n", 162);
    }

    printf("> n%c concluido\n", 162);
}
