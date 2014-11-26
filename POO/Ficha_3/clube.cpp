#include <iostream>
#include "clube.h"

using namespace std;

// Deve ser poss�vel saber se uma pessoa � s�cia do clube.
// Para tal � indicada um objecto pessoa
// e se o seu bilhete de identidade for igual ao de algu�m no clube,
// a resposta ser� positiva(�resposta� = retorno da fun��o que trata dessa quest�o).
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

// Deve ser poss�vel remover um s�cio do clube dado o seu bilhete de identidade
bool Clube::remove(string bi)
{
    itPessoa it = socio(bi);
    if (it == _socios.end()) return false;

    _socios.erase(it);
    return true;
}

// Deve ser poss�vel acrescentar uma pessoa a um clube.
void Clube::adiciona(Pessoa socio)
{
    _socios.push_back(socio);
}

// Deve ser poss�vel listar os dados de todos os s�cios de um clube.
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

// Um objecto de Clube s� pode ser criado mediante a indica��o do seu nome e da actividade.
// Inicialmente n�o existem pessoas nesse clube.
Clube::Clube(string nome, string atividade)
{
    _nome = nome;
    _atividade = atividade;
}
