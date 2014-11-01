#include <stdio.h>
#include <winsock.h>

#pragma comment(lib, "ws2_32.lib")

void die(char *msg)
{
    fprintf(stderr, "<CLI1> ERRO <%s> (%d)\n", msg, WSAGetLastError());
    exit(EXIT_FAILURE);
}
