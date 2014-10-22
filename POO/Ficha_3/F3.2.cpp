#include <iostream>
#include <string>

#include "Triangulo.h"
#include "Ponto.h"

using namespace std;

int main(){
	//-----------------------------------------------------------------------------
	// (a) ... testar a class Triangulo
	//-----------------------------------------------------------------------------
	// testar o construtor
	Triangulo q("tri", 1, 2, 3, 4, 5, 6);
	// testar getString
	cout << "T" << q.getString();
	for(int i = 1; i < 4; i++){
		// testar getPonto
		cout << "P" << i << q.getPonto(i).getString() << endl;
		// testar setPonto
		q.setPonto(10+i, 20+i, i);
	}
	cout << "T" << q.getString();

	return 0;
}
