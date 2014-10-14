#include <iostream>
#include <string>
#include "Televisao.h"

using namespace std;

void comando(Televisao);

int main(){
	int x=0;

	string publica[] = {"RTP1", "RTP2", "SIC", "TVI", "Parlamento"}, cabo[] = {
		"RTP Noticias", "SIC Noticias", "TVI 24 Horas", "Euronews",
		"SIC Radical", "TV Globo", "Fox", "AXN", "MTV Portugal", "Discovery"};

	Televisao samsung(publica, 5), sony(cabo, 10);

	// (a)
	while (true){
		cout << "[1] Televisao 1 (Publica)" << endl
		     << "[2] Televisao 2 (Privada)" << endl;
		cin >> x;
		system("cls");
		if (x == 1) {
			comando(samsung);
		}
		else if (x == 2){
			comando(sony);
		}
		else cout << x << "?" << endl;
	}

	return 0;
}

void comando(Televisao tv){
	bool sair = false;
	char c;

	while (!sair){
		cout << "[1] ligar" << endl
			 << "[2] mais som" << endl
			 << "[3] menos som" << endl
			 << "[4] sem som" << endl
			 << "[5] canal anterior" << endl
			 << "[6] canal seguinte" << endl
			 << "[7] escolher canal" << endl
			 << "[8] info" << endl
			 << "[9] desligar" << endl
			 << "[0] sair" << endl;

		cout << "----------------------------------------" << endl;
		tv.info();
		cout << "----------------------------------------" << endl;

		cin >> c;

		switch (c){
			case '1':
				tv.ligar();
				break;
			case '2':
				tv.maisSom();
				break;
			case '3': tv.menosSom();
				break;
			case '4': tv.semSom();
				break;
			case '5':
				tv.canalAnterior();
				break;
			case '6':
				tv.canalSeguinte();
				break;
			case '7':
				system("cls");
				tv.setCanal();
				break;
			case '8':
				tv.info();
				break;
			case '9':
				tv.desligar();
				break;
			case '0':
				sair = true;
				break;
			default:
				cout << "Accao: " << c << "?" << endl;
		}
		system("cls");
	}
}
