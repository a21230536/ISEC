#ifndef COMUM_H

#include "winsock.h"

#define COMUM_H
#define BUFFERSIZE 4096
#define SERV_TCP_PORT 5432

void Abort(char *, SOCKET);
void AtendeCliente(int);

#endif
