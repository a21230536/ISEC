#pragma once
#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "Ponto.h"

class Rectangulo
{
    Ponto *P;

    int xx;
    int yy;

public:
    Ponto O;
    int altura () const;
    int largura() const;
    int area() const;
    int perimetro() const;

    void altura(int a);
    void largura(int l);

    Rectangulo(Ponto*, int, int);
    Rectangulo(int l, int a, int x, int y);
};

#endif
