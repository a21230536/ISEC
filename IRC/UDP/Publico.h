
#ifndef UDP_PUBLICO
#define UDP_PUBLICO
#define SERV_UDP_PORT 5432
#define BUFFERSIZE 4096
#define SERV_HOST_ADDR "127.0.0.1"
#define TIMEOUT 10

typedef struct _req {
	char msg[BUFFERSIZE];
} Req;

typedef struct _res {
	int nbytes;
	char msg[256];
} Res;

void Abort(char *msg);

#endif
