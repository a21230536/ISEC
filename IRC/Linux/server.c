#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define MAX_FILA 5
#define MAX_LINHA 256
#define SERVIDOR_PORTO 5432

int main(){
	struct sockaddr_in sin;
	char buffer[MAX_LINHA];
	int len;
	int s, novo_s;

	/*-------------------------------------------------------------------------
	 * 
	 *-----------------------------------------------------------------------*/
	bzero((char*)&sin, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_port = SERVIDOR_PORTO;

	/*-------------------------------------------------------------------------
	 * 
	 *-----------------------------------------------------------------------*/
	 if((s = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
 	 	perror("erro ao criar o socket");
 	 	return 1;
	 }

	/*-------------------------------------------------------------------------
	 * 
	 *-----------------------------------------------------------------------*/ 
	 if(bind(s, (struct sockaddr*)&sin, sizeof(sin)) < 0){
 	 	perror("erro a ligar ao socket");
 	 	return 1;
	 }

	/*-------------------------------------------------------------------------
	 * 
	 *-----------------------------------------------------------------------*/
	listen(s, MAX_FILA);

	/*-------------------------------------------------------------------------
	 * 
	 *-----------------------------------------------------------------------*/	
	len	= sizeof(sin);
	while(1){
		/* */
		if((novo_s = accept(s, (struct sockaddr*)&sin, &len)) < 0) {
	 	 	perror("erro a receber no socket");
	 	 	return 1;
		}
		/* */
		while(len = recv(novo_s, buffer, sizeof(buffer), 0))
			fputs(buffer, stdout);
		close(novo_s);
	}
}
