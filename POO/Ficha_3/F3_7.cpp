#include <iostream>
#include "banco.h"

using namespace std;

int main()
{
    cout << "> Pessoa joe(\"Jose Daniel\", \"0999999-9XY\", \"999 999 999\");" << endl;
    Pessoa joe("Jose Daniel", "0999999-9XY", "999 999 999");

    // b) classe Conta
    cout << "> cgd(&joe);" << endl;
    Conta conta(&joe);
    cout << boolalpha;
    cout << "> cgd.saldo();// " << conta.saldo() << endl;// 0
    cout << "> cgd.credito(-1);// " << conta.credito(-1) << endl;// false
    cout << "> cgd.credito(3);// " << conta.credito(3) << endl;// true
    cout << "> cgd.saldo();// " << conta.saldo() << endl;// 3
    cout << "> cgd.debito(5);// " << conta.debito(5) << endl;// false
    cout << "> cgd.debito(1);// " << conta.debito(1) << endl;// true
    cout << "> cgd.saldo();// " << conta.saldo() << endl;// 2
    Pessoa const *titular = conta.titular();
    //titular->nome("Zorro");// ERRO! titular aponta a uma constante
    cout << "> TITULAR: " << titular->nome()
         << "; BI: " << titular->bi()
         << "; NIF: " << titular->nif() << endl;

    // c) classe Banco
    Banco caixa("Caixa");
    cout << "> caixa.nomes();// " << caixa.nomes() << endl;
    cout << "> caixa.soma();// " << caixa.soma() << endl;
    cout << "> caixa.conta(&joe);// " << caixa.conta(&joe) << endl;
    cout << "> caixa.conta(joe.bi(), 804);// " << caixa.movimento(joe.bi(), 804) << endl;
    cout << "> caixa.nomes();// " << caixa.nomes() << endl;
    cout << "> caixa.soma();// " << caixa.soma() << endl;
    cout << "> Pessoa maria(\"Maria Silva\", \"0000000-0YY\", \"000 000 000\");" << endl;
    Pessoa maria("Maria Silva", "0000000-0YY", "000 000 000");
    cout << "> caixa.conta(&maria);// " << caixa.conta(&maria) << endl;
    cout << "> caixa.conta(maria.bi(), 1200);// " << caixa.movimento(maria.bi(), 1200) << endl;
    cout << "> caixa.conta(maria.bi(), -200);// " << caixa.movimento(maria.bi(), -200) << endl;
    cout << "> caixa.saldo(maria.bi());// " << caixa.saldo(maria.bi()) << endl;
    cout << "> caixa.conta(joe.bi())->saldo();// " << caixa.conta(joe.bi()).saldo() << endl;
    cout << "> caixa.soma();// " << caixa.soma() << endl;
    cout << "> caixa.nomes();// " << caixa.nomes() << endl;

    return 0;
}
