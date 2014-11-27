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
    fprintf(stderr, "\a<SER> Erro fatal: <%d> %s\n", WSAGetLastError(), msg);

    if (sock != INVALID_SOCKET) closesocket(sock);

    exit(EXIT_FAILURE);
}

/*
 * writeN
 * ------
 * Envia n bytes de dados pelo socket.
 */
int writeN(SOCKET sock, char *buffer, int nBytes)
{
    int nRemain = nBytes, nWritten = 0;

    if (buffer[nRemain - 1] != '\n') {
        buffer[nRemain] = '\n';
        /* ... não colocar '\0' fora do BUFFERSIZE */
        buffer[++nRemain] = '\0';
    }

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
 * Lê uma linha de 'texto' do socket.
 */
int readLine(SOCKET sock, char *buffer, int tamMax)
{
    char c;
    int n = 0, i = 0;

    while (i < tamMax - 1) {
        if ((n = recv(sock, &c, sizeof(c), 0)) == SOCKET_ERROR) {
            return SOCKET_ERROR;
        }

        if (n == 0 || c == '\n') break;
        if (c == '\r') continue;
        else buffer[i++] = c;
    }

    return i;
}
