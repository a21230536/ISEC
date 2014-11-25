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

    // "está preso a um prego ... o prego já existia"
    Prego *_prego;

public:
    // "deve ser possível saber as coodenadas x e y ..."
    int x() const { return _prego->x(); }
    int y() const { return _prego->y(); }
    string local()
    {
        ostringstream pos;
        pos << "(" << x() << "," << y() << ")";
        return pos.str();
    }

    // "quando é criado ... tem sempre um texto e é sempre posto num determinado prego ..."
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
