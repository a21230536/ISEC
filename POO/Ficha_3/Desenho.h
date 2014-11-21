#ifndef DESENHO_H
#define DESENHO_H
#include <vector>
#include "Rectangulo.h"

using namespace std;

class Desenho
{
private:

    vector<Rectangulo> _retangulos;
    double _area;
    bool _fora(Ponto, Rectangulo);
    int _pos(Ponto, Rectangulo);
    bool _intersecta(Rectangulo, Rectangulo);
    enum Pos { N = 1, NE, E, SE, S, SO, O, NO };

public:

    // "Acrescentar um rect�ngulo; esta opera��o s� ser� poss�vel se o novo rect�ngulo n�o intersectar os que j� existem
    // no desenho.Esta opera��o deve retornar um c�digo de sucesso ou insucesso da opera��o(bool); Nota: a verifica��o
    // se dois rect�ngulos se intersectam � uma opera��o que diz respeito a rect�ngulos."
    bool retangulo(Rectangulo);

    // "Obter o conjunto de rect�ngulos cujo canto superior esquerdo esteja num dado ponto."
    vector<Rectangulo> retangulo(Ponto) const;

    // "Eliminar todos os rect�ngulos cuja �rea seja superior a um valor dado;"
    int eliminar(double);

    // "Obter a soma das �reas de todos os rect�ngulos do desenho;"
    double areas() { return _area; };// inline

    // "Obter uma string com a descri��o de toda a informa��o relativa ao desenho."
    string str() const;

    // construtor
    Desenho() { cout << "> Desenho::Desenho();" << endl; _area = 0; }
    Desenho(vector<Rectangulo>);

    // destrutor
    ~Desenho() { cout << "> Desenho::~Desenho();" << endl; }
};

#endif
