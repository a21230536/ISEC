#ifndef COMUM_H

#define COMUM_H
#define SERVER_PORT 5432
#define BUFFER_SIZE 256
#define SERVER_ADDR "127.0.0.1"
#define TIMEOUT 10
#define N 5
#define TRUE 1
#define FALSE 0

typedef struct _res {
    char msg[256];
    int casamento;
    struct sockaddr_in noivo;
} RES;

void die(char *);
void sai(char *);
char *erro(char *);
void falha(char *);

#endif
