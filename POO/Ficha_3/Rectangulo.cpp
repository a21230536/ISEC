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

Rectangulo::Rectangulo(Ponto *p, int l, int a)
{
    if (l < 0) l = 0;
    if (a < 0) a = 0;

    xx = l;
    yy = a;

    P = p;

    cout << "> novo Rectangulo - largura = " << largura() << ", altura = " << altura() << endl;
}

Rectangulo::Rectangulo(int l, int a, int x, int y)
    :O(x, y)
{
    if (l < 0) l = 0;
    if (a < 0) a = 0;

    xx = l;
    yy = a;

    cout << "> novo Rectangulo - largura = " << largura() << ", altura = " << altura() << endl;
}
