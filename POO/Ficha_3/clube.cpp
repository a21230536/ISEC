#include <iostream>
#include "clube.h"

using namespace std;

// Deve ser possível saber se uma pessoa é sócia do clube.
// Para tal é indicada um objecto pessoa
// e se o seu bilhete de identidade for igual ao de alguém no clube,
// a resposta será positiva(“resposta” = retorno da função que trata dessa questão).
bool Clube::socio(Pessoa pessoa)
{
    if (socio(pessoa.bi()) != _socios.end()) return true;
    return false;
}
itPessoa Clube::socio(string bi)
{
    itPessoa it = _socios.begin();
    for (it; it != _socios.end(); it++) {
        if (bi == it->bi()) {
            return it;
        }
    }
    return it;
}

// Deve ser possível remover um sócio do clube dado o seu bilhete de identidade
bool Clube::remove(string bi)
{
    itPessoa it = socio(bi);
    if (it == _socios.end()) return false;

    _socios.erase(it);
    return true;
}

// Deve ser possível acrescentar uma pessoa a um clube.
void Clube::adiciona(Pessoa socio)
{
    _socios.push_back(socio);
}

// Deve ser possível listar os dados de todos os sócios de um clube.
void Clube::lista()
{
    if (_socios.empty()) cout << "> vazio" << endl;
    else for (Pessoa pessoa : _socios) {
        cout << "> NOME: " << pessoa.nome() << endl;
        cout << ">   BI: " << pessoa.bi() << endl;
        cout << ">  NIF: " << pessoa.nif() << endl;
        cout << ">" << endl;
    }
}

// Um objecto de Clube só pode ser criado mediante a indicação do seu nome e da actividade.
// Inicialmente não existem pessoas nesse clube.
Clube::Clube(string nome, string atividade)
{
    _nome = nome;
    _atividade = atividade;
}
