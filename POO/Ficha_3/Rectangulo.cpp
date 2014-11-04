#include <iostream>
#include "Ponto.h"
#include "Rectangulo.h"

using namespace std;

int Rectangulo::altura() const
{
    return yy;
}

int Rectangulo::largura() const
{
    return xx;
}

int Rectangulo::area() const
{
    return (largura() * altura());
}
int Rectangulo::perimetro() const
{
    return (2 * xx + 2 * yy);
}

void Rectangulo::altura(int a)
{
    if (a < 0) return;
}

void Rectangulo::largura(int l)
{
    if (l < 0) return;
}

//---------------------------------------------------------------------------------------------------------------------
// (d) Acrescente construtores e destrutores às classes ... ver os objectos ... que estão a ser criados e destruídos.
//---------------------------------------------------------------------------------------------------------------------
Rectangulo::Rectangulo(Ponto *P, int l, int a)
{
    if (l < 0) l = 0;
    if (a < 0) a = 0;

    xx = l;
    yy = a;

    p = P;

    cout << ">>> construindo Rectangulo: largura=" << largura() << ", altura=" << altura() << ", P=" << p->str() << endl;
}
// CENÁRIO (INSINUADO) DO ENUNCIADO
Rectangulo::Rectangulo(Ponto p, int l, int a)
{
    if (l < 0) l = 0;
    if (a < 0) a = 0;

    xx = l;
    yy = a;

    P = p;

    cout << ">>> construindo Rectangulo: largura=" << largura() << ", altura=" << altura() << ", P->" << P.str() << endl;
    this->p = NULL;
}
//
Rectangulo::Rectangulo(int l, int a, int x, int y)
    :O(x, y)
{
    if (l < 0) l = 0;
    if (a < 0) a = 0;

    xx = l;
    yy = a;

    cout << ">>> construindo Rectangulo: largura=" << largura() << ", altura=" << altura() << ", O=" << O.str() << endl;
    this->p = NULL;
}
//
Rectangulo::~Rectangulo(){
    cout << ">>> destruindo Rectangulo: largura=" << largura() << ", altura=" << altura()
        << ", O=" << O.str() << ", P=" << P.str();

    if(p == NULL) cout << endl;
    else cout << ", p->" << p->str() << endl;
}
