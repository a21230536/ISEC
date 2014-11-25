// classe Pessoa

#ifndef PESSOA_H
#define PESSOA_H
#include <iostream>
#include <sstream>
using namespace std;

class Pessoa
{
private:
    // nome, número de bilhete de identidade, e número de contribuinte.
    string _nome;
    string _bi;
    string _nif;
public:
    // A classe Pessoa deve ter funções membros que permitam obter cada um dos seus dados, actualizar o nome
    // (apenas o nome), e obter uma string com a descrição do seu conteúdo.
    string nome() const { return _nome; }
    void nome(string nome) { _nome = nome; }
    string bi() const { return _bi; }
    string nif() const { return _nif; }

    string str()
    {
        ostringstream info;
        info << "NOME: " << nome() << endl << "; BI: " << bi() << "NIF: " << nif();
        return info.str();
    }

    // Um objecto de Pessoa só pode ser criado se lhe forem indicados todos os seus dados.
    Pessoa(string nome, string bi, string nif) { _nome = nome, _bi = bi, _nif = nif;  }
};

#endif
