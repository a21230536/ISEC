#include <iostream>
#include "conta.h"

using namespace std;

int main()
{
    cout << "> Pessoa ze(\"Jose Daniel\", \"0999999-9XY\", \"999 999 999\");" << endl;
    Pessoa joe("Jose Daniel", "0999999-9XY", "999 999 999");

    // b) classe Conta
    cout << "> cgd(&joe);" << endl;
    Conta caixa(&joe);
    cout << boolalpha;
    // saldo inicial
    cout << "> cgd.saldo();// " << caixa.saldo() << endl;
    // tentar adicionar -1 (tirar 1) ao saldo
    cout << "> cgd.credito(-1);// " << caixa.credito(-1) << endl;
    // adicionar 3 ao saldo
    cout << "> cgd.credito(3);// " << caixa.credito(3) << endl;
    // verificar saldo
    cout << "> cgd.saldo();// " << caixa.saldo() << endl;// 3
    // tentar remover 5 do saldo
    cout << "> cgd.debito(5);// " << caixa.debito(5) << endl;// false
    // remover 1 do saldo
    cout << "> cgd.debito(1);// " << caixa.debito(1) << endl;// true
    // verificar o saldo
    cout << "> cgd.saldo();// " << caixa.saldo() << endl;// 2
    // obter o titular da conta
    Pessoa const *titular = caixa.titular();
    // tentar modificar o titular
    //titular->nome("Zorro");// ERRO! titular aponta a uma constante
    // mostrar info do titular
    cout << "> TITULAR: " << titular->nome()
         << "; BI: " << titular->bi()
         << "; NIF: " << titular->nif() << endl;

    return 0;
}
