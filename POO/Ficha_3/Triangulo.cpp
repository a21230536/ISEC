#include <iostream>
#include <string>
#include <sstream>

#include "Triangulo.h"

using namespace std;

Triangulo::Triangulo(string s, int x1, int y1, int x2, int y2,  int x3, int y3)
		:nome(s), p1(x1, y1), p2(x2, y2), p3(x3, y3){

	cout << "Triangulo::Triangulo(\"" << s << "\"," << x1 << "," << y1 << ","
		 << x2 << "," << y2 << "," << x3 << "," << y3 << ")" << endl;

	/*/ d.s.i.
	pontos[0].X(x1);
	pontos[0].Y(y1);
	pontos[1].X(x2);
	pontos[1].Y(y2);
	pontos[2].X(x3);
	pontos[2].Y(y3);
	//*/
}

void Triangulo::setPonto(int x, int y, int n){
	Ponto *p;

	switch (n){
		case 1:
			p = &p1;
			break;
		case 2:
			p = &p2;
			break;
		case 3:
			p = &p3;
			break;
		default:
			return;
	}

	p->setX(x);
	p->setY(y);

	/*/ d.s.i.
	if(n < 0 || n > 2) return;
	pontos[n].X(x);
	pontos[n].X(y);
	//*/
}

Ponto Triangulo::getPonto(int n){
	switch (n){
		case 1: return p1;
		case 2: return p2;
		case 3: return p3;
		default: return p1;
	}

	/*/ d.s.i.
	if(n < 0 || n > 2) return pontos[0];
	return pontos[n];
	//*/
}

string Triangulo::getString(){
	ostringstream textual;

	textual << "[" << p1.getString() << "," << p2.getString() << ","
		<< p3.getString() << "]" << endl;

	return textual.str();
}
