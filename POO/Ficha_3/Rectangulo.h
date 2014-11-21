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
    // (d) Acrescente construtores e destrutores às classes ...
    //-----------------------------------------------------------------------------------------------------------------
    Rectangulo(){}

    // I - A posição (Ponto P) do rectângulo é independente (pertence ao próprio Rectângulo)
    Rectangulo(Ponto, int, int);// CENÁRIO (INSINUADO) DO ENUNCIADO

    // II - A posição do rectângulo (Ponto *) é dependente (pertence a um Ponto exterior)
    Rectangulo(Ponto*, int, int);

    // III - A posição (Ponto O) do rectângulo é privada
    Rectangulo(int, int, int, int);

    // destrutor
    ~Rectangulo();
};

#endif
