// Ficha 1, Exercício 3
//-----------------------------------------------------------------------------
// (a) Obtém nome e idade, utilizando apenas conhecimentos da linguagem C++
//-----------------------------------------------------------------------------
#include <iostream>

int main(){
	int idade;
	std::string nome;

	std::cout << "Nome: ";
	getline(std::cin, nome);

	std::cout << "Idade: ";
	std::cin >> idade;

	std::cout << std::endl;
	std::cout << "Nome=\"" << nome << "\"\n";
	std::cout << "Idade=" << idade << std::endl;

	return 0;
}

//-----------------------------------------------------------------------------
// (b) Comparar com o exercício 2
//-----------------------------------------------------------------------------
// ...
