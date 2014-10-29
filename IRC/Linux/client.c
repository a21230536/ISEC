#include <stdio.h>/* standard I/O: fprintf, stderr, FILE, ... */ 
#include <netdb.h>/* hostent, gethostbyname, ... */
#include <sys/socket.h>/* bind, connect, ... */
#include <string.h>/* bzero, bcopy, strlen, ... */

#define MAX_LINHA 256
#define SERVIDOR_PORTO 5432

int main(int argc, char *argv[]){
	FILE *fp;/* */
	struct hostent *hp;/* para a informação do host (nome do servidor) */
	struct sockaddr_in sin;/* para a informação do servidor */
	char *host;/* para guardar o nome do host */
	char buffer[MAX_LINHA];/* para as linhas de texto obtidas a partir de stdin */
	int s;
	int len;

	if(argc != 2 || isalpha(host[0])){
		fprintf(stderr, "uso: %s <host_nome>\n", argv[0]);
		return 1;
	}
	
	host = argv[1];
//puts("One");
	/* Obter IP a partir do nome do host */
	hp = gethostbyname(host);
	if(hp == NULL){
		fprintf(stderr, "host %s desconhecido\n", argv[1]);
		return 1;
	}
puts("Two");
//return 1;
	/*-------------------------------------------------------------------------
	 * preparar a estrutura de dados do enderesso do servidor
	 *-----------------------------------------------------------------------*/
	/* limpar a estrututra: preencher o espaço ocupado por sin com zeros */
	bzero((char *)&sin, sizeof(sin));
	/* endereço da família Internet */
	sin.sin_family = AF_INET;
	/* copiar os bytes em h_addr para o enderesso do servidor */
	bcopy(hp->h_addr, (char *)&sin.sin_addr, hp->h_length);
	/* porto do servidor */
	sin.sin_port = htons(5432);

puts("3");
return 1;
 	/*-------------------------------------------------------------------------
 	 * Criar o Socket
 	 *-----------------------------------------------------------------------*/
 	 /* PF_INET: família Internet; SOCK_STREAM: fluxo de bytes; 0: protocolo */
 	 if((s = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
 	 	perror("erro ao criar o socket");
 	 	return 1;
 	 }
puts("Four");
return 1;
 	/*-------------------------------------------------------------------------
 	 * Usar o Socket para ligar ao servidor
 	 *-----------------------------------------------------------------------*/
 	 if(connect(s, (struct sockaddr*)&sin, sizeof(sin)) < 0){
 	 	perror("erro a usar o socket");
 	 	close(s);/* fechar o socket */
 	 	return 1;
 	 }

 	/*-------------------------------------------------------------------------
 	 * Obter e Enviar Linhas de Texto
 	 *-----------------------------------------------------------------------*/
	/* Ciclo Principal: obtém texto a partir do fluxo de entrada comum */
 	while (fgets(buffer, sizeof(buffer), stdin)){
 		buffer[MAX_LINHA-1] = '\0';
 		len = strlen(buffer) + 1;
 		/* enviar a linha de texto no buffer  */
 		send(s, buffer, len, 0);
 	}

	return 0;
}
