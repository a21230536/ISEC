/* CASAMENTEIRO SERVIDOR - SIMPLES */
#include <stdio.h>
#include <winsock.h>
#include <string.h>

#define SERVER_PORT 5432
#define BUFFER_SIZE 256

#pragma comment(lib, "ws2_32.lib")

void die(char *);

main()
{
    SOCKET sock;
    WSADATA wsa_data;
    struct sockaddr_in servidor, cliente1, cliente2;
    int len, wsa_result, sa_len = sizeof(struct sockaddr_in);
    char buffer[BUFFER_SIZE];

    /* iniciar o WinSock */
    if (wsa_result = WSAStartup(MAKEWORD(2,2), &wsa_data)) {
        die("Iniciar o WinSock");
    }

    /* criar um Socket */
    if ((sock = socket(PF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) {
        die("Criar o Socket");
    }

    /* construir o endereço do Servidor */
    memset((char *) &servidor, 0, sizeof(servidor));
    servidor.sin_family = AF_INET;
    servidor.sin_addr.s_addr = htonl(INADDR_ANY);
    servidor.sin_port = htons(SERVER_PORT);

    /* vincular o enderço ao Socket */
    if (bind(sock, (SOCKADDR*)&servidor, sizeof(servidor)) == SOCKET_ERROR) {
        die("Vincular ao Socket");
    }

    /* ciclo de juntar pares */
    while (1) {
        puts("> novo par");

        /* receber datagrama do primeiro cliente (A) */
        if (recvfrom(sock, buffer, sizeof(buffer), 0, (SOCKADDR*) &cliente1, &sa_len) == SOCKET_ERROR) {
            perror("> ERRO [%d] Receber do Primeiro Cliente\n", WSAGetLastError());
            continue;
        }
        
        printf("> cliente 1 (%s:%d)\n", inet_ntoa(cliente1.sin_addr), ntohs(cliente1.sin_port));

        /* receber datagrama segundo cliente (B) */
        if (recvfrom(sock, buffer, sizeof(buffer), 0, (SOCKADDR*)&cliente2, &sa_len) == SOCKET_ERROR) {
            perror("ERRO [%d] Receber do Segundo Cliente\n", WSAGetLastError());
            continue;
        }
        
        printf("> cliente 2 (%s:%d)\n", inet_ntoa(cliente2.sin_addr), ntohs(cliente2.sin_port));

        /* enviar o endereço do cliente A ao cliente B */
        if (sendto(sock, &cliente1, sa_len, 0, (SOCKADDR*) &cliente2, sa_len) == SOCKET_ERROR) {
            perror("ERRO [%d] Enviar ao Segundo Cliente\n", WSAGetLastError());
            continue;
        }

        puts("> o endereco do cliente 1 foi enviado ao cliente 2\n>");
    }
}

void die(char *msg)
{
    fprintf(stderr, "ERRO <%s> (%d)\n", msg, WSAGetLastError());
    exit(-1);
}