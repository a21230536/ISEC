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
    switch (nbytes = readLine(sock, buffer, BUFFERSIZE)) {
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

            if ((nBytesSent = writeN(sock, buffer, nbytes)) == SOCKET_ERROR) {
                fprintf(stderr, "<SER> Impossibilidade de Confirmar.\n");
            }
            else if (nBytesSent<nbytes) {
                fprintf(stderr, "<SER> Mensagem confirmada, mas truncada.\n");
            }
            else printf("<SER> Mensagem confirmada.\n");
    }
}

/*
 * writeN
 * ------
 * Sends n bytes of data through socket.
 */
int writeN(SOCKET sock, char *buffer, int nBytes)
{
    int nRemain = nBytes, nWritten = 0;

    while (nRemain > 0) {
        if ((nWritten = send(sock, buffer, nRemain, 0)) == SOCKET_ERROR) {
            return SOCKET_ERROR;
        }

        if (!nWritten) break;

        nRemain -= nWritten;
        buffer += nWritten;
    }

    return nWritten;
}

/*
 * readLine
 * --------
 * Reads a line of data from socket.
 */
int readLine(SOCKET sock, char *buffer, int tamMax)
{
    char c;
    int n = 0, i = 0;

    while (i < tamMax - 1) {
        if ((n = recv(sock, &c, sizeof(c), 0)) == SOCKET_ERROR) return SOCKET_ERROR;

        if (n == 0 || c == '\n') break;
        if (c == '\r') continue;
        else buffer[i++] = c;
    }

    return i;
}
