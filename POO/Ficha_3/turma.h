#ifndef TURMA_H
#define TURMA_H
#include "pessoa.h"

class Turma
{
private:
    const unsigned int N = 20;
    Pessoa *_professor = nullptr;
    vector<Pessoa *> _alunos;
public:
    // list students
    void alunos();
    // add student
    bool aluno(Pessoa *);
    // get student
    Pessoa *aluno(string);
    // remove student
    bool anula(string);
    // constructor
    Turma(Pessoa *);
};

#endif
