#ifndef AVISO_H
#define AVISO_H
#include <sstream>
#include "Prego.h"

using namespace std;

class Aviso
{
private:
    // "tem um texto"
    string _aviso;

    // "est� preso a um prego ... o prego j� existia"
    Prego *_prego;

public:
    // "deve ser poss�vel saber as coodenadas x e y ..."
    int x() const { return _prego->x(); }
    int y() const { return _prego->y(); }
    string local()
    {
        ostringstream pos;
        pos << "(" << x() << "," << y() << ")";
        return pos.str();
    }

    // "quando � criado ... tem sempre um texto e � sempre posto num determinado prego ..."
    Aviso(string aviso, Prego *prego)
    {
        _aviso = aviso;
        _prego = prego;
        cout << "> Aviso criado \"" << _aviso << "\"" << endl;
    }
    // (e)
    Aviso(string aviso, Prego &prego)
    {
        _aviso = aviso;
        _prego = &prego;
        cout << "> Aviso criado \"" << _aviso << "\"" << endl;
    }

    ~Aviso()
    {
        cout << "> ~Aviso destruido \"" << _aviso << "\"" << endl;
    }
};

#endif
