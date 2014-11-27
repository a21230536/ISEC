#include <iostream>
#include <fstream>
#include "banco.h"

const string FICHEIRO = "c:\\htdocs\\ISEC\\POO\\Ficha_3\\pessoas.txt";
const int N = 10;

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
    cout << "> caixa.movimento(joe.bi(), 804);// " << caixa.movimento(joe.bi(), 804) << endl;
    cout << "> caixa.nomes();// " << caixa.nomes() << endl;
    cout << "> caixa.soma();// " << caixa.soma() << endl;
    cout << "> Pessoa maria(\"Maria Silva\", \"0000000-0YY\", \"000 000 000\");" << endl;
    Pessoa maria("Maria Silva", "0000000-0YY", "000 000 000");
    cout << "> caixa.conta(&maria);// " << caixa.conta(&maria) << endl;
    cout << "> caixa.movimento(maria.bi(), 1200);// " << caixa.movimento(maria.bi(), 1200) << endl;
    cout << "> caixa.movimento(maria.bi(), -200);// " << caixa.movimento(maria.bi(), -200) << endl;
    cout << "> caixa.saldo(maria.bi());// " << caixa.saldo(maria.bi()) << endl;
    cout << "> caixa.conta(joe.bi())->saldo();// " << caixa.conta(joe.bi()).saldo() << endl;
    cout << "> caixa.soma();// " << caixa.soma() << endl;
    cout << "> caixa.nomes();// " << caixa.nomes() << endl;

    // d)
    Banco branca("Dona Branca");// banco 2
    Pessoa manel("Manuel Maria", "0000001-1XX", "111 111 111");
    Pessoa toze("Antonio Jose Oliveira", "0000010-1XX", "222 222 222");
    Pessoa rita("Maria Rita", "0000011-0XY", "333 333 333");
    branca.conta(&manel);
    branca.conta(&toze);
    branca.conta(&rita);
    branca.conta(&maria);
    caixa.conta(&rita);
    cout << "> branca.nomes();// " << branca.nomes() << endl;
    cout << "> caixa.nomes();// " << caixa.nomes() << endl;
    maria.nome("Maria Augusta da Silva");
    manel.nome("Manuel Maria Antunes");
    cout << "> branca.nomes();// " << branca.nomes() << endl;
    cout << "> caixa.nomes();// " << caixa.nomes() << endl;

    // e)
    ifstream dados(FICHEIRO);
    if (!dados) {
        cout << "> ERRO a abrir o ficheiro " << FICHEIRO << endl;
        return 1;
    }
    cout << "> OBTER PESSOAS DO FICHEIRO " << FICHEIRO << endl;
    int n = 0;
    string nome, bi, nif;
    vector<Pessoa> pessoas;
    while (n < N && dados >> nome) {
        dados >> bi;
        dados >> nif;
        pessoas.push_back(Pessoa(nome, bi, nif));
        n++;
    }
    dados.close();
    for (int i = 0; i < n; i++) {
        caixa.conta(&pessoas[i]);
        caixa.movimento(pessoas[i].bi(), 1000);
        branca.conta(&pessoas[i]);
        branca.movimento(pessoas[i].bi(), 1500);
        cout << "> " << pessoas[i].nome() << endl;
    }
    cout << "> LISTAR OS NOMES DOS CLIENTES DOS BANCOS" << endl;
    cout << "> branca.nomes();// " << branca.nomes() << endl;
    cout << "> caixa.nomes();// " << caixa.nomes() << endl;
    cout << "> ALTERAR NOMES DE PESSOAS" << endl;
    for (int i = 0; i < n; i++) {
        nome = pessoas[i].nome() + " Carvalho";
        switch (i) {
        case 0:
            cout << "> pessoas[0].nome(\"" << nome << "\");" << endl;
            pessoas[0].nome(nome);
            break;
        case 1:
            cout << "> pessoas[1].nome(\"" << nome << "\");" << endl;
            pessoas[1].nome(nome);
            break;
        case 2:
            cout << "> pessoas[2].nome(\"" << nome << "\");" << endl;
            pessoas[2].nome(nome);
        default:;
        }
    }
    cout << "> LISTAR OS NOMES DOS CLIENTES DOS BANCOS (APOS ALTERACAO DE NOMES)" << endl;
    cout << "> branca.nomes();// " << branca.nomes() << endl;
    cout << "> caixa.nomes();// " << caixa.nomes() << endl;
    cout << "> caixa.soma();// " << caixa.soma() << endl;
    cout << "> branca.soma();// " << branca.soma() << endl;

    return 0;
}
