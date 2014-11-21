#pragma once
#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "Ponto.h"

class Rectangulo
{
    Ponto *p;
    Ponto O;

    int xx;
    int yy;

public:
    Ponto P;
    int altura () const;
    int largura() const;
    int area() const;
    int perimetro() const;
    Ponto ponto() const{
        return O;
    }

    void altura(int a);
    void largura(int l);

    //-----------------------------------------------------------------------------------------------------------------
    // (d) Acrescente construtores e destrutores �s classes ...
    //-----------------------------------------------------------------------------------------------------------------
    Rectangulo(){}

    // I - A posi��o (Ponto P) do rect�ngulo � independente (pertence ao pr�prio Rect�ngulo)
    Rectangulo(Ponto, int, int);// CEN�RIO (INSINUADO) DO ENUNCIADO

    // II - A posi��o do rect�ngulo (Ponto *) � dependente (pertence a um Ponto exterior)
    Rectangulo(Ponto*, int, int);

    // III - A posi��o (Ponto O) do rect�ngulo � privada
    Rectangulo(int, int, int, int);

    // destrutor
    ~Rectangulo();
};

#endif
