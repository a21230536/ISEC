#pragma once

#include <string>

using namespace std;
#include "Ponto.h"

//-----------------------------------------------------------------------------
// (a) a class Triangulo ...
//-----------------------------------------------------------------------------
class Triangulo{
	// "cada tri�ngulo tem um nome"
	string nome;
	
	// v�rtices do tri�ngulo
	Ponto v0;
	Ponto v1;
	Ponto v2;

	// para V setter/getter
	Ponto vertices[3];// ERRO para (b)
	
public:
	//  modifica o v�rtice de ind�ce i do tri�ngulo
	void vertice(int i, int x, int y);
	void V(int i, int x, int y);

	// obt�m o v�rtice de ind�ce i
	Ponto vertice(int i);
	Ponto V(int i);
	
	// obt�m a representa��o textual do tri�ngulo
	int str(string s);
	string str();
	string txt();

	// construtor
	Triangulo(string s, int x1, int y1, int x2, int y2, int x3, int y3);

	// destrutor
	~Triangulo();
};
