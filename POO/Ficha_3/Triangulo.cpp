#include <iostream>
#include <string>
#include <sstream>

#include "Triangulo.h"

using namespace std;

Triangulo::Triangulo(string s, int x0, int y0, int x1, int y1,  int x2, int y2)
	//-------------------------------------------------------------------------	
	// (c) mecanismo que permite inicializar objectos com ... os três objectos
	//-------------------------------------------------------------------------
	:nome(s), v0(x0, y0), v1(x1, y1), v2(x2, y2) { 
	//, vertices{ Ponto (x0, y0), Ponto (x1, y1), Ponto (x2, y2) } {
	
	//-------------------------------------------------------------------------	
	// (d) mwcanismo que permite inicializar objectos com ... os três objectos
	//-------------------------------------------------------------------------
	cout << ">>> construindo Triangulo " << str() << endl;

	// para vertices[]
	V(0, x0, y0);
	V(1, x1, y1);
	V(2, x2, y2);
}

Triangulo::~Triangulo(){
	//-------------------------------------------------------------------------	
	// (d) mecanismo que permite inicializar objectos com ... os três objectos
	//-------------------------------------------------------------------------
	cout << ">>> destruindo Triangulo" << str() << endl;
}

// setter
void Triangulo::vertice(int i, int x, int y){
	Ponto *p;

	switch (i){
		case 0:
			p = &v0;
			break;
		case 1:
			p = &v1;
			break;
		case 2:
			p = &v2;
			break;
		default:
			return;
	}

	p->X(x);
	p->Y(y);
}

// getter
Ponto Triangulo::vertice(int i){
	switch (i){
		case 0:
			return v0;
		case 1:
			return v1;
		case 2:
			return v2;
		default:
			return v0;
	}
}

string Triangulo::str(){
	ostringstream textual;

	textual << nome << "[" 
		<< v0.str() << ","
		<< v1.str() << ","
		<< v2.str() << "]" << endl;

	return textual.str();
}

int Triangulo::str(string s){
	nome = s;
	//nome = string(s);

	if( nome == s) return -1;
	return 0;
}

// para vertices[]
string Triangulo::txt(){
	ostringstream textual;
	
	textual << nome << " [" 
		<< vertices[0].str() << ","
		<< vertices[1].str() << ","
		<< vertices[2].str() << "]" << endl;
	return textual.str();
}

// setter/getter para vertices[]
void Triangulo::V(int i, int x, int y){
	if (i < 0 || i > 2) return;

	vertices[i].X(x);
	vertices[i].Y(y);
}
Ponto Triangulo::V(int i){
	if (i != 1 && i != 2) 
		return vertices[0];
	return vertices[i];
}
