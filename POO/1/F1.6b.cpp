// Ficha 1, Exercício 6
//-----------------------------------------------------------------------------
// (b) Explique por que razão são necessários os ponteiros.
//-----------------------------------------------------------------------------
#include <iostream>

using namespace std;

// troca os valores das variáveis a, b
void troca(int* a, int* b){
	int c = *a;

	*a = *b;
	*b = c;
}

int main(){
	int a = 5, b = 10;

	troca(&a, &b);

	// mostra "a = 10; b = 5"
	cout << "\na = " << a << "; b = " << b << "\n";

	return 0;
}
