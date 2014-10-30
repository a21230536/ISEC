#include <stdio.h>
#include <winsock.h>

#pragma comment(lib, "ws2_32.lib")

void Abort(char *msg) {
	fprintf(stderr, "<CLI1> Erro fatal: <%s> (%d)\n", msg, WSAGetLastError());
	exit(EXIT_FAILURE);
}
