#include <iostream>
#include <sstream>
#include "Rectangulo.h"
#include "Desenho.h"

using namespace std;

Desenho::Desenho(vector<Rectangulo> retangulos)
{
    for (unsigned int i = 0; i < retangulos.size(); i++) {
        _retangulos.push_back(retangulos[i]);
    }
}

// adiciona um retângulo ao desenho
bool Desenho::retangulo(Rectangulo retangulo)
{
    // validar o retangulo
    for (unsigned int i = 0; i < _retangulos.size(); i++) {
        if (_intersecta(retangulo, _retangulos[i])) {
            // intersecta um retângulo existente
            return false;
        }
    }

    _area += retangulo.area();
    _retangulos.push_back(retangulo);

    return true;
}

// devolve um conjunto de retângulos num ponto
vector<Rectangulo> Desenho::retangulo(Ponto ponto) const
{
    vector<Rectangulo> conjunto;

    for (unsigned int i = 0; i < _retangulos.size(); i++) {
        if (_retangulos[i].P.X() == ponto.X() && _retangulos[i].P.Y() == ponto.Y()) {
            conjunto.push_back(_retangulos[i]);
        }
    }

    return conjunto;
}

// elimina os rectângulos com área superior a area
int Desenho::eliminar(double area)
{
    int n = 0;
    for (unsigned int i = 0; i < _retangulos.size(); i++) {
        if (_retangulos[i].area() > area) {
            _area -= _retangulos[i].area();

            //FAZER eliminar retângulo

            n++;
        }
    }

    // rectângulos eliminados
    return n;
}

// devolve uma string descritiva do desenho
string Desenho::str() const
{
    ostringstream textual;

    textual << "o desenho tem " << _retangulos.size() << " retangulos" << endl;
    return textual.str();
}

// verifica se um ponto está fora dum retângulo
bool Desenho::_fora(Ponto p, Rectangulo r)
{
    return !_pos(p, r);
}

// obtém a posição dum ponto em relação a um retãngulo
int Desenho::_pos(Ponto p, Rectangulo r)
{
    int x0 = r.P.X();
    int y0 = r.P.Y();
    int x1 = r.P.X() + r.largura();
    int y1 = r.P.Y() + r.altura();

    // oeste
    if (p.X() < x0) {
        if (p.Y() < y0) return NO;
        else if (p.Y() > y0) return SO;
        return O;
    }

    // este
    if(p.X() > x1) {
        if (p.Y() > y0) return SE;
        else if (p.Y() < y0) return NE;
        return E;
    }

    // norte
    if (p.Y() < y0) return N;

    // sul
    if (p.Y() > y1) return S;

    // dentro
    return 0;
}

// verifica se um retãngulo intersecta outro
bool Desenho::_intersecta(Rectangulo R0, Rectangulo R1)
{
    Ponto P(R1.P.X(), R1.P.Y());
    Ponto Q(R1.P.X() + R1.largura(), R1.P.Y() + R1.altura());

    int posP = _pos(P, R0);
    int posQ = _pos(Q, R0);

    switch (posP) {
    case N:
        if (Q.Y() < R0.P.Y()) return false;
        return true;
    case NE:
        if (posQ == O || posQ == S) return true;
        return false;
    case E:
        if (Q.X() > R0.P.X() + R0.largura()) return false;
        return true;
    case SE:
        if (posQ == O || posQ == N) return true;
        return false;
    case S:
        if (Q.Y() > R0.P.Y() + R0.altura()) return false;
        return true;
    case SO:
        if (posQ == O || posQ == E) return true;
        return false;
    case O:
        if (Q.X() < R0.P.X()) return false;
        return true;
    case NO:
        if (posQ == S || posQ == E) return true;
        return false;
    default:
        return false;
    }
}
