// Ficha 1, Exercício 2

//-----------------------------------------------------------------------------
// (a) Obtém nome e idade, utilizando conhecimentos da linguagem C++
//-----------------------------------------------------------------------------
#include <iostream>

int main(){
	int idade;
	char nome[32];

	std::cout << "Nome: ";
	std::cin >> nome;

	std::cout << "Idade: ";
	std::cin >> idade;

	std::cout << std::endl;
	std::cout << "Nome=\"" << nome << "\"\n";
	std::cout << "Idade=" << idade << std::endl;

	return 0;
}

//-----------------------------------------------------------------------------
// (b) Identificar os pontos fracos...
//-----------------------------------------------------------------------------
