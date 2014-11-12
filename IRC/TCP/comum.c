#include <stdio.h>
#include <winsock.h>
#include "comum.h"

#pragma comment(lib, "Ws2_32.lib")

/*
* Abort
* -----
* Mostra a mensagem de erro associada ao ultimo erro no SO e abando com "exit status" a 1
*/
void Abort(char *msg, SOCKET sock)
{
    fprintf(stderr, "\a<SER >Erro fatal: <%d>\n", WSAGetLastError());

    if (sock != INVALID_SOCKET) closesocket(sock);

    exit(EXIT_FAILURE);
}

/*
* AtendeCliente
* -------------
* Processa a mensagem do cliente.
*/
void AtendeCliente(int sock)
{
    static char buffer[BUFFERSIZE];
    static unsigned int cont = 0;
    int nbytes, nBytesSent;

    /* PROCESSA PEDIDO */
    switch (nbytes = recv(sock, buffer, BUFFERSIZE, 0)) {

    case SOCKET_ERROR:
        fprintf(stderr, "\n<SER> Erro na recepcao de dados...\n");
        return;

    case  0:
        fprintf(stderr, "\n<SER> O cliente nao enviou dados...\n");
        return;

    default:
        buffer[nbytes] = '\0';
        printf("\n<SER> Mensagem n. %d recebida {%s}\n", ++cont, buffer);

        /* ENVIA CONFIRMACAO */
        printf("<SER> Confirma recepcao de mensagem.\n");
        sprintf_s(buffer, BUFFERSIZE, "%d", nbytes);
        nbytes = strlen(buffer);

        if ((nBytesSent = send(sock, buffer, nbytes, 0)) == SOCKET_ERROR) {
            fprintf(stderr, "<SER> Impossibilidade de Confirmar.\n");
        }
        else if (nBytesSent<nbytes) {
            fprintf(stderr, "<SER> Mensagem confirmada, mas truncada.\n");
        }
        else printf("<SER> Mensagem confirmada.\n");
    }
}
