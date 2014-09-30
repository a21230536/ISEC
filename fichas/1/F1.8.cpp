// Ficha 1, Exercício 8
#include <iostream>

using namespace std;

int main() {
	string palavra, reverso;
	int k, l, m;

	cout << "'fim' para terminar" << endl;

	while (true) {
		cout << "\nPalavra: ";
		getline(cin, palavra);

		if(palavra == "fim") break;

		l = palavra.length();
		m = l / 2;

		for(k=0; k < m; k++)
			if(palavra[k] != palavra[l-k-1])
				break;

		cout << palavra;
		if(k == m) cout << " [palindromo]";
	}

	return 0;
}
