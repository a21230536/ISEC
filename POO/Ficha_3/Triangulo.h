#pragma once

#include <string>

using namespace std;
#include "Ponto.h"

//-----------------------------------------------------------------------------
// (a) a class Triangulo ...
//-----------------------------------------------------------------------------
class Triangulo{
	// "cada triângulo tem um nome"
	string nome;
	
	// vértices do triângulo
	Ponto v0;
	Ponto v1;
	Ponto v2;

	// para V setter/getter
	Ponto vertices[3];// ERRO para (b)
	
public:
	//  modifica o vértice de indíce i do triângulo
	void vertice(int i, int x, int y);
	void V(int i, int x, int y);

	// obtém o vértice de indíce i
	Ponto vertice(int i);
	Ponto V(int i);
	
	// obtém a representação textual do triângulo
	int str(string s);
	string str();
	string txt();

	// construtor
	Triangulo(string s, int x1, int y1, int x2, int y2, int x3, int y3);

	// destrutor
	~Triangulo();
};
