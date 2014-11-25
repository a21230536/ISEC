#pragma once
#ifndef DESENHO_H
#define DESENHO_H

#include <vector>

#include "Ponto.h"
#include "Rectangulo.h"

using namespace std;

class Desenho
{
private:

    vector<Rectangulo> _retangulos;

    bool _fora(Ponto, Rectangulo);
    int _pos(Ponto, Rectangulo);
    bool _intersecta(Rectangulo, Rectangulo);
    enum Pos { N = 1, NE, E, SE, S, SO, O, NO };

public:

    // (i) "Acrescentar um rect�ngulo; esta opera��o s� ser� poss�vel se o novo rect�ngulo n�o intersectar os que j� existem
    // no desenho.Esta opera��o deve retornar um c�digo de sucesso ou insucesso da opera��o(bool); Nota: a verifica��o
    // se dois rect�ngulos se intersectam � uma opera��o que diz respeito a rect�ngulos."
    bool retangulo(Rectangulo);

    // (ii) "Obter o conjunto de rect�ngulos cujo canto superior esquerdo esteja num dado ponto."
    vector<Rectangulo> conjunto(Ponto) const;

    // (iii) "Eliminar todos os rect�ngulos cuja �rea seja superior a um valor dado;"
    int eliminar_area_superior(double);

    // (iv) "Obter a soma das �reas de todos os rect�ngulos do desenho;"
    double areas();

    // (v) "Obter uma string com a descri��o de toda a informa��o relativa ao desenho."
    string str(); //const;

    // construtor
    Desenho() { if(log) cout << "> LOG Desenho();" << endl; }
    Desenho(vector<Rectangulo>);

    // destrutor
    ~Desenho() { if(log) cout << "> LOG ~Desenho();" << endl; }

    static bool log;
};

#endif
