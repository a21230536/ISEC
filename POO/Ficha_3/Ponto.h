#pragma once

#ifndef PONTO_H
#define PONTO_H

#include <string>
using namespace std;

//-----------------------------------------------------------------------------
// (a) desenvolver a classe Ponto...
//-----------------------------------------------------------------------------
class Ponto{
private:
    // - as variáveis só podem ser acedidas pelas funções públicas
    int _x;
    int _y;

public:
    // - funções para obter os dados "podem chamar objectos Pontos constantes"
    int x() const { return _x; }// "'int &x() const;' dá ERRO"
    int y() const { return _y; }

    // - funções para modificar os dados...
    void x(int x) { _x = x; }
    void y(int y) { _y = y; }

    // - calcula a distância entre o préprio ponto e o ponto P fornecido
    double d(const Ponto& P) const;

    string str();

    //-----------------------------------------------------------------------------
    // (e) novos pontos sem argumentos ficam na posição (0,0)
    //-----------------------------------------------------------------------------
    Ponto(int x = 0, int y = 0);// comentar para satisfazer (b) do exercício 2

    // Construtor
    // - só é possivel criar objectos inicializados com as duas coordenadas
    //Ponto(int, int);// descomentar para satisfazer (b) do exercício 2

    // destrutor
    ~Ponto();

    static bool log;
};

#endif
