// Ficha 1, Exercício 6
//-----------------------------------------------------------------------------
// (c) Escreva a função pretendida utilizando parâmetros do tipo referência.
//-----------------------------------------------------------------------------
#include <iostream>

using namespace std;

// constantes não podem ser alterados
//void troca(const int& a, const int& b){}

void troca(int& a, int& b){
	int c = a;

	a = b;
	b = c;
}


int main(){
	int a = 5, b = 10;
	troca(a, b);

	// mostra a = 10; b = 5
	cout << "\na = " << a << "; b = " << b << "\n";

	return 0;
}

//-----------------------------------------------------------------------------
// (d) Comparar parâmetros do tipo referência com os do tipo ponteiro
//-----------------------------------------------------------------------------
// ...
