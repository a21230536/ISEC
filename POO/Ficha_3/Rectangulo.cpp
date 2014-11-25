#include <iostream>
#include <sstream>
#include "Ponto.h"
#include "Rectangulo.h"

using namespace std;

bool Rectangulo::log = false;

int Rectangulo::area() const
{
    return (largura() * altura());
}
int Rectangulo::perimetro() const
{
    return (2*largura() + 2*altura());
}

void Rectangulo::altura(int a)
{
    if (a < 0) return;
}

void Rectangulo::largura(int l)
{
    if (l < 0) return;
}

string Rectangulo::str()
{
	ostringstream textual;
	textual << "[" << P.str() << "," << largura() << "," << altura() << "]";
	return textual.str();
}

//---------------------------------------------------------------------------------------------------------------------
// (d) Acrescente construtores e destrutores às classes ... ver os objectos ... que estão a ser criados e destruídos.
//---------------------------------------------------------------------------------------------------------------------
Rectangulo::Rectangulo(Ponto *P, int largura, int altura)
{
	if (largura < 0) largura = 0;
	if (altura < 0) altura = 0;

	_largura = largura;
	_altura = altura;

    p = P;

	if (log) cout << "> LOG Rectangulo construindo " << str() << "; P=" << p->str() << endl;
}
// CENÁRIO DO ENUNCIADO (?)
Rectangulo::Rectangulo(Ponto p, int largura, int altura)
{
    if (largura < 0) largura = 0;
    if (altura < 0) altura = 0;

	_largura = largura;
	_altura = altura;

    P = p;

	if (log) cout << "> LOG Rectangulo construindo " << str() << "; P->" << P.str() << endl;
    this->p = NULL;
}
//
Rectangulo::Rectangulo(int largura, int altura, int x, int y)
    :_P(x, y)
{
    if (largura < 0) largura = 0;
    if (altura < 0) altura = 0;

    _largura = largura;
    _altura = altura;

	if (log) cout << "> LOG Rectangulo construindo " << str() << "; _P=" << _P.str() << endl;
    this->p = NULL;
}
//
Rectangulo::~Rectangulo(){
	if (log) {
		cout << "> LOG ~Rectangulo destruindo " << str();
		if (p != NULL) cout << "; p->" << p->str();
		cout << endl;
	}
}
