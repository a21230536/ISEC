#include <iostream>
#include <sstream>
#include "Ponto.h"
#include "Rectangulo.h"
#include "Desenho.h"

using namespace std;

bool Desenho::log = false;

Desenho::Desenho(vector<Rectangulo> retangulos)
{
    for (unsigned int i = 0; i < retangulos.size(); i++) {
        _retangulos.push_back(retangulos[i]);
    }
}

double Desenho::areas() {
    double area = 0;

    for (Rectangulo retangulo : _retangulos) {
        area += retangulo.area();
    }

    return area;
};

// adiciona um retângulo ao desenho
bool Desenho::retangulo(Rectangulo retangulo)
{
    // validar o retangulo
    for (Rectangulo existente : _retangulos) {
        if (_intersecta(retangulo, existente)) {
            return false;// o retângulo intersecta um existente
        }
    }

    // adiconar retângulo
    _retangulos.push_back(retangulo);

    return true;
}

// devolve um conjunto de retângulos num ponto
vector<Rectangulo> Desenho::conjunto(Ponto ponto) const
{
    vector<Rectangulo> conjunto;

    for (Rectangulo retangulo : _retangulos) {
        if (retangulo.P.x() == ponto.x() && retangulo.P.y() == ponto.y()) {
            conjunto.push_back(retangulo);
        }
    }

    return conjunto;
}

// elimina os rectângulos com área superior a area
int Desenho::eliminar_area_superior(double area)
{
    int n = 0;

    for (std::vector<Rectangulo>::iterator it = _retangulos.begin(); it != _retangulos.end(); it++) {
        if (it->area() > area) {
            cout << "> a eliminar retangulo " << it->str() << endl;
            it = _retangulos.erase(it);
            n++;
        }
    }

    return n;// n = número de rectângulos eliminados
}

// devolve uma string descritiva do desenho
string Desenho::str() //const
{
    ostringstream textual;

    textual << "o desenho tem " << _retangulos.size() << " retangulo(s) que totaliza(m) " << areas() << " de area";
    return textual.str();
}

// verifica se um ponto está fora dum retângulo
bool Desenho::_fora(Ponto p, Rectangulo r)
{
    return !_pos(p, r);
}

// obtém a posição dum ponto em relação a um rectângulo
int Desenho::_pos(Ponto p, Rectangulo r)
{
    int x0 = r.P.x();
    int y0 = r.P.y();
    int x1 = r.P.x() + r.largura();
    int y1 = r.P.y() + r.altura();

    // oeste
    if (p.x() < x0) {
        if (p.y() < y0) return NO;
        else if (p.y() > y0) return SO;
        return O;
    }

    // este
    if(p.x() > x1) {
        if (p.y() > y0) return SE;
        else if (p.y() < y0) return NE;
        return E;
    }

    // norte
    if (p.y() < y0) return N;

    // sul
    if (p.y() > y1) return S;

    // dentro
    return 0;
}

// verifica se um retãngulo intersecta outro
bool Desenho::_intersecta(Rectangulo R0, Rectangulo R1)
{
    Ponto P(R1.P.x(), R1.P.y());
    Ponto Q(R1.P.x() + R1.largura(), R1.P.y() + R1.altura());

    int posP = _pos(P, R0);
    int posQ = _pos(Q, R0);

    switch (posP) {
    case N:
        if (Q.y() < R0.P.y()) return false;
        return true;
    case NE:
        if (posQ == O || posQ == S) return true;
        return false;
    case E:
        if (Q.x() > R0.P.x() + R0.largura()) return false;
        return true;
    case SE:
        if (posQ == O || posQ == N) return true;
        return false;
    case S:
        if (Q.y() > R0.P.y() + R0.altura()) return false;
        return true;
    case SO:
        if (posQ == O || posQ == E) return true;
        return false;
    case O:
        if (Q.x() < R0.P.x()) return false;
        return true;
    case NO:
        if (posQ == S || posQ == E) return true;
        return false;
    default:
        return false;
    }
}
