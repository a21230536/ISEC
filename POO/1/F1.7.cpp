// Ficha 1, Exercício 7

#include <iostream>
#include <sstream>

using namespace std;

int main(){
	string entrada, nome;

	cout << "Escreva \"fim\" para sair\n";
	while (1){
		cout << "Nome: \n> ";
		getline(cin, entrada);

		if (entrada == "fim") break;

		istringstream iss(entrada);

		while (iss.peek() != EOF){
			iss >> nome;
		//while(iss >> nome){
			cout << nome;
			if (nome == "silva") cout << " nome conhecido";
			cout << endl;
		}
	}
	return 0;
}
