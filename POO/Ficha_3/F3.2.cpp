#include <iostream>
#include <string>

#include "Triangulo.h"
#include "Ponto.h"

using namespace std;

int main(){
	//-------------------------------------------------------------------------
	// (a) ... testar a class Triangulo
	//-------------------------------------------------------------------------
	Triangulo q("T1", 0,0, 1,1, 2,2);
	cout << endl;
	cout << "> q.str();// => " << q.str();
	for(int i = 0; i < 3; i++){
		cout << "> vertice(" << i << ").str();//=> " << q.vertice(i).str() << endl;
		
		q.vertice(i, i*10 + 1, i*10 + 2);
	}
	cout << "> q.str();// => " << q.str();

	cout << "\n> q.str(\"T2\");" << endl;
	q.str("T2");
	cout << "> q.txt();// => " << q.txt();
	
	for (int i = 0; i < 3; i++){
		cout << "> V(" << i << ").str();// => " << q.V(i).str() << endl;
		cout << "> V(" << i << "," << 100*i + 1 << "," << 100*i + 2 << ");" << endl;
		q.V(i, i*100 + 1, i*100 + 2);
	}

	cout << "> q.txt();// => " << q.txt() << endl;

	return 0;
}

