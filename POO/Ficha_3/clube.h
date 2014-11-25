#ifndef CLUBE_H
#define CLUBE_h

#include <vector>
#include "pessoa.h"

using namespace std;

typedef vector<Pessoa>::iterator itPessoa;

class Clube
{
private:
    // N�o existe limite para o n�mero de s�cios.
    vector<Pessoa> _socios;
    string _nome;
    string _atividade;

public:
    // Deve ser poss�vel saber se uma pessoa � s�cia do clube.
    // Para tal � indicada um objecto pessoa
    // e se o seu bilhete de identidade for igual ao de algu�m no clube,
    // a resposta ser� positiva(�resposta� = retorno da fun��o que trata dessa quest�o).
    bool socio(Pessoa pessoa);
    itPessoa socio(string bi);

    // Deve ser poss�vel remover um s�cio do clube dado o seu bilhete de identidade
    bool remove(string bi);

    // Deve ser poss�vel acrescentar uma pessoa a um clube.
    void adiciona(Pessoa socio);

    // Deve ser poss�vel listar os dados de todos os s�cios de um clube.
    void lista();

    // Um objecto de Clube s� pode ser criado mediante a indica��o do seu nome e da actividade.
    // Inicialmente n�o existem pessoas nesse clube.
    Clube(string nome, string atividade);
};

#endif;
