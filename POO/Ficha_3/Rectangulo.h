#pragma once

#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "Ponto.h"

class Rectangulo
{
    Ponto *p;
    Ponto _P;

    int _largura;
    int _altura;

public:

    Ponto P;
    Ponto ponto() const { return _P; }

    int Rectangulo::largura() const { return _largura; }
    int Rectangulo::altura() const { return _altura; }
    void largura(int);
    void altura(int);   

    int area() const;
    int perimetro() const;
    
    string str();
    void info() { cout << "> " << str() << endl; }

    //-----------------------------------------------------------------------------------------------------------------
    // (d) Acrescente construtores e destrutores �s classes ...
    //-----------------------------------------------------------------------------------------------------------------
    Rectangulo() {}

    // I - A posi��o (Ponto P) do rect�ngulo � independente (pertence ao pr�prio Rect�ngulo)
    Rectangulo(Ponto, int, int);// CEN�RIO DO ENUNCIADO (?)

    // II - A posi��o do rect�ngulo (Ponto *) � dependente (pertence a um Ponto exterior)
    Rectangulo(Ponto*, int, int);

    // III - A posi��o (Ponto O) do rect�ngulo � privada
    Rectangulo(int, int, int, int);

    // destrutor
    ~Rectangulo();

    static bool log;
};

#endif
