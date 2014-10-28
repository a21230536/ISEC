#pragma once

#ifndef PONTO_H
#define PONTO_H

#include <string>
using namespace std;

//-----------------------------------------------------------------------------
// (a) desenvolver a classe Ponto...
//-----------------------------------------------------------------------------
class Ponto{
	// privado
	// - as variáveis só podem ser acedidas pelas funções públicas
	int x;
	int y;

public:

	// - funções para obter os dados "podem chamar objectos Pontos constantes"
	int getX() const;// "'int &getX() const;' dá ERRO"
	int getY() const;

	// - funções para modificar os dados...
	void setX(int n);
	void setY(int n);

	// - calcula a distância entre o préprio ponto e o ponto P fornecido
	double calcDist(const Ponto& P) const;

	string getString();
	string str(){ return getString(); }


	//-----------------------------------------------------------------------------
	// (e) novos pontos sem argumentos ficam na posição (0,0)
	//-----------------------------------------------------------------------------
	Ponto(int a=0, int b=0);// comentar para satisfazer (b) do exercício 2

    // Construtor
	// - só é possivel criar objectos inicializados com as duas coordenadas
	//Ponto(int, int);// descomentar para satisfazer (b) do exercício 2

	// destrutor
	~Ponto();

	//TESTE
	int X() const;// getter
	void X(int);// setter
	int Y() const;
	void Y(int);
};

#endif
