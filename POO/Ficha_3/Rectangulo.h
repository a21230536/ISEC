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
    // (d) Acrescente construtores e destrutores às classes ...
    //-----------------------------------------------------------------------------------------------------------------
    Rectangulo() {}

    // I - A posição (Ponto P) do rectângulo é independente (pertence ao próprio Rectângulo)
    Rectangulo(Ponto, int, int);// CENÁRIO DO ENUNCIADO (?)

    // II - A posição do rectângulo (Ponto *) é dependente (pertence a um Ponto exterior)
    Rectangulo(Ponto*, int, int);

    // III - A posição (Ponto O) do rectângulo é privada
    Rectangulo(int, int, int, int);

    // destrutor
    ~Rectangulo();

    static bool log;
};

#endif
