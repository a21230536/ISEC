#include <iostream>
#include "Televisao.h"

using namespace std;

Televisao::Televisao(string canais[], int n){
	setCanais(canais, n);
	ligada = false;
	volume = 0;
	canal = 1;
}

void Televisao::setCanais(string canais0[], int n){
	if (n > DIM){
		n = DIM;
	}
	for (int i = 0; i < n; i++){
		canais[i] = canais0[i];
	}
	nCanais = n;
}

void Televisao::ligar(){
	if (!ligada){
		ligada = true;
	}
}

void Televisao::desligar(){
	if (ligada){
		ligada = false;
	}
}

// Volume
void Televisao::maisSom(){
	if (volume < 10){
		volume++;
	}
}
void Televisao::menosSom(){
	if (volume > 0){
		volume--;
	}
}
void Televisao::semSom(){
	if (volume != 0){
		volume = 0;
	}
}

// canais
void Televisao::canalSeguinte(){
	if (canal < nCanais){
		canal++;
	}
	else canal = 1;
}
void Televisao::canalAnterior(){
	if (canal > 1) {
		canal--;
	}
	else canal = nCanais;
}
void Televisao::setCanal(){
	int n;
	string s;

	if (!ligada) return;

	for (int i = 0; i < nCanais; i++){
		cout << "[" << i + 1 << "] " << canais[i] << endl;
	}

	cin >> s;

	n = stoi(s);

	cout << "n: " << n << endl;

	if (n > 0 && n <= nCanais){
		canal = n;
	}
}

// informação
void Televisao::info(){
	if (!ligada) {
		cout << "Televisao Desligada" << endl;
		return;
	}

	cout << "Canal: "
		<< canal
		<< " - "
		<< canais[canal - 1]
		<< endl
		<< "Volume: "
		<< volume << endl;
}
