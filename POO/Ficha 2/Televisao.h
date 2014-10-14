#pragma once
#ifndef TELEVISAO_H
#define TELEVISAO_H

#include <string>

using namespace std;

class Televisao {
	static const int DIM = 10;

	string canais[DIM];
	int nCanais;

	bool ligada;
	int volume;// min:0 - max:10
	int canal; // indice actual do array canais
	void setCanais(string[], int);

public:
	// power
	void ligar();
	void desligar();

	// volume
	void maisSom();
	void menosSom();
	void semSom();

	// canais
	void canalSeguinte();
	void canalAnterior();
	void setCanal();

	// informação
	void info();

	Televisao(string canais[], int n);
};

#endif
