#pragma once

#include <string>

using namespace std;
#include "Ponto.h"

//-----------------------------------------------------------------------------
// (a) a class Triangulo ...
//-----------------------------------------------------------------------------
class Triangulo{
	string nome;
	Ponto p1;
	Ponto p2;
	Ponto p3;

	/*/ desenvolvimento não influenciado
	Ponto pontos[3];
	//*/

public:
	void setPonto(int x, int y, int n);
	Ponto getPonto(int n);
	string getString();
	Triangulo(string s, int x1, int y1, int x2, int y2, int x3, int y3);
};
