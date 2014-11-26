#include <sstream>
#include <string>
#include <vector>
#include "conta.h"
#include "banco.h"

using namespace std;

// encontra/obtem conta
vector<Conta>::iterator Banco::_conta(string bi)
{
    vector<Conta>::iterator it = _contas.begin();
    for (it; it != _contas.end(); it++) {
        if (it->titular()->bi() == bi) break;
    }
    return it;
}

// deposita (levanta) quantia na conta
bool Banco::movimento(string bi, int quantia)
{
    vector<Conta>::iterator it = _conta(bi);
    if (it == _contas.end()) return false;
    return it->credito(quantia);
}

// acrescenta conta
bool Banco::conta(Pessoa *titular)
{
    // considerando que uma pessoa NAO pode ter mais que uma conta
    if (_conta(titular->bi()) != _contas.end()) return false;

    _contas.push_back(Conta(titular));
    return true;
}

int Banco::saldo(string bi)
{
    vector<Conta>::iterator conta = _conta(bi);
    if (conta == _contas.end()) return 0;
    return conta->saldo();
}

bool Banco::existe(string bi) const
{
    for (Conta conta : _contas) {
        if (conta.titular()->bi() == bi) return true;
    }
    return false;
}

Conta Banco::conta(string bi) const
{
    for (Conta conta : _contas) {
        if (conta.titular()->bi() == bi) return conta;
    }

    return Conta(nullptr);
}

// elimina conta
bool Banco::encerrar_conta(string bi)
{
    vector<Conta>::iterator it = _conta(bi);
    if (it == _contas.end()) return false;
    _contas.erase(it);
    return true;
}

// obtém a soma total dos saldos
int Banco::soma()
{
    int total = 0;
    for (Conta conta : _contas) {
        total += conta.saldo();
    }
    return total;
}

// nomes dos titulares das contas do banco
string Banco::nomes() const
{
    ostringstream nomes;
    bool primeiro = true;

    if (_contas.empty()) return "[]";

    nomes << "[\"";

    for (Conta conta : _contas) {
        if (primeiro) primeiro = false;
        else nomes << "\", \"";
        nomes << conta.titular()->nome();
    }

    nomes << "\"]";

    return nomes.str();
}
