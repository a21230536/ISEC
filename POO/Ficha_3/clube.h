#ifndef CLUBE_H
#define CLUBE_h

#include <vector>
#include "pessoa.h"

using namespace std;

typedef vector<Pessoa>::iterator itPessoa;

class Clube
{
private:
    // Não existe limite para o número de sócios.
    vector<Pessoa> _socios;
    string _nome;
    string _atividade;

public:
    // Deve ser possível saber se uma pessoa é sócia do clube.
    // Para tal é indicada um objecto pessoa
    // e se o seu bilhete de identidade for igual ao de alguém no clube,
    // a resposta será positiva(“resposta” = retorno da função que trata dessa questão).
    bool socio(Pessoa pessoa);
    itPessoa socio(string bi);

    // Deve ser possível remover um sócio do clube dado o seu bilhete de identidade
    bool remove(string bi);

    // Deve ser possível acrescentar uma pessoa a um clube.
    void adiciona(Pessoa socio);

    // Deve ser possível listar os dados de todos os sócios de um clube.
    void lista();

    // Um objecto de Clube só pode ser criado mediante a indicação do seu nome e da actividade.
    // Inicialmente não existem pessoas nesse clube.
    Clube(string nome, string atividade);
};

#endif;
