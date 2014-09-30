// Ficha 1, Exercício 1

//-----------------------------------------------------------------------------
// (a) Obtém nome e idade, utilizando apenas conhecimentos da linguagem C
//-----------------------------------------------------------------------------
#include <stdio.h>

int main(){
	int idade;
	char nome[32];

	printf("Nome: ");
	gets(nome);// ou 'scanf("%s", nome);'

	printf("Idade: ");
	scanf("%d", &idade);

	printf("\nNome=\"%s\"\n", nome);
	printf("Idade=%d\n", idade);

	return 0;
}

//-----------------------------------------------------------------------------
// (b) Identificar pontos fracos
//-----------------------------------------------------------------------------
// - limitação de comprimento de strings
// - limitações do scanf para string streams
// - cuidados a ter com o formato na apresentação de variáveis no printf
// - ...
