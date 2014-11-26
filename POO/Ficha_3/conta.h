#ifndef CONTA_H
#define CONTA_H

#include "pessoa.h"

class Conta
{
private:
    int _saldo;
    Pessoa *_titular;

public:
    Pessoa const *titular() { return _titular; }
    bool credito(int valor) {
        if (valor + _saldo < 0) return false;
        _saldo += valor;
        return true;
    }
    bool debito(int valor) { return credito(-valor); }
    int saldo() const { return _saldo; }
    Conta(Pessoa *titular) { _titular = titular; _saldo = 0; }
};

#endif
