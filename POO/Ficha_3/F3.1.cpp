#include <iostream>
#include <string>

#include "Ponto.h"

using namespace std;

int main(){
	//-------------------------------------------------------------------------
	// (a) ...testar o classe Ponto
	//-------------------------------------------------------------------------
	Ponto A(1, 2), B(3, 4);
	// instanciar um Ponto sem especificar as coordenadas
	//Ponto P;// ERRO: não existe um construtor para Ponto sem os argumentos

	//-------------------------------------------------------------------------
	// (b) distância entre A e B
	//-------------------------------------------------------------------------
	cout << "|A,B| = " << A.calcDist(B) << endl;

	//-------------------------------------------------------------------------
	// (c) obter coordenadas de C (constante) e tentar modificá-las
	//-------------------------------------------------------------------------
	const Ponto C(5,6);
	cout << "C.x = " << C.getX() << endl << "C.y = " << C.getY() << endl;
	cout << "A(x, y) = " << A.getString() << endl;
	//C.setX(0);// ERRO! C é do tipo constante, tipo não invocável por getX
	//  i) objecto constante 'const Objecto O(0,0);'
	// ii) função constante: 'void Func() const {}'

	//-------------------------------------------------------------------------
	// (d) matriz de 3 objectos Ponto
	//-------------------------------------------------------------------------
	Ponto mat[] = {Ponto(1, 3), Ponto(2, 4), Ponto(5, 7)};
	//mat2[3];// ERRO! não é possível criar um Ponto sem argumentos

	//-----------------------------------------------------------------------------
	// (e) VER Ponto.h - novos pontos sem argumentos ficam na posição (0,0)
	//-----------------------------------------------------------------------------
	Ponto D;
	cout << "D(x, y) = " << D.getString() << endl;
}
