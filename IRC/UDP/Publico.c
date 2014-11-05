#include <stdlib.h>
#include <stdio.h>
#include <winsock.h>
#include <string.h>

#pragma comment(lib, "ws2_32.lib")

void die(char *msg)
{
    fprintf(stderr, "<CLI1> ERRO <%s> (%d)\n", msg, WSAGetLastError());
    exit(EXIT_FAILURE);
}

void sai(char *msg)
{
    fprintf(stderr, "ERRO [%s]\n", msg);
    exit(1);
}

char *erro(char *msg)
{
    sprintf(msg, "WSA ERROR %d\n", WSAGetLastError());
    return msg;
}

void falha(char *s)
{
	char wsaerr[32];
	char msg[256];

	erro(wsaerr);
	sprintf(msg, "FALHA <%s - %s>", s, wsaerr);
	sai(msg);
}

void supper(char *s)
{
    int i, n = strlen(s);

    for(i=0; i<n; i++) {
        s[i] = toupper(s[i]);
    }
}
