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

    // "Acrescentar um rectângulo; esta operação só será possível se o novo rectângulo não intersectar os que já existem
    // no desenho.Esta operação deve retornar um código de sucesso ou insucesso da operação(bool); Nota: a verificação
    // se dois rectângulos se intersectam é uma operação que diz respeito a rectângulos."
    bool retangulo(Rectangulo);

    // "Obter o conjunto de rectângulos cujo canto superior esquerdo esteja num dado ponto."
    vector<Rectangulo> retangulo(Ponto) const;

    // "Eliminar todos os rectângulos cuja área seja superior a um valor dado;"
    int eliminar(double);

    // "Obter a soma das áreas de todos os rectângulos do desenho;"
    double areas() { return _area; };// inline

    // "Obter uma string com a descrição de toda a informação relativa ao desenho."
    string str() const;

    // construtor
    Desenho() { cout << "> Desenho::Desenho();" << endl; _area = 0; }
    Desenho(vector<Rectangulo>);

    // destrutor
    ~Desenho() { cout << "> Desenho::~Desenho();" << endl; }
};

#endif
