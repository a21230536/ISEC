#pragma once
#ifndef BANCO_H
#define BANCO_H

#include <string>
#include <vector>
#include "conta.h"

using namespace std;

class Banco
{
private:
    string _nome;
    vector<Conta> _contas;

    // encontra/obtem conta
    vector<Conta>::iterator _conta(string bi);

public:
    // nome do banco
    void nome(string nome) { _nome = nome; }
    string nome() const { return _nome; }

    // deposita (levanta) quantia na conta
    bool movimento(string bi, int quantia);

    // acrescenta conta
    bool conta(Pessoa *titular);

    int saldo(string bi);

    // verifica se uma conta existe
    bool existe(string bi) const;

    // obtém "a imagem de" uma conta
    Conta conta(string bi) const;

    // elimina conta
    bool encerrar_conta(string bi);

    // obtém a soma total dos saldos
    int soma();

    // nomes dos titulares das contas do banco
    string nomes() const;
    Banco(string nome) { this->nome(nome); }
};

#endif
