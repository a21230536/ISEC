#include <vector>
#include "turma.h"

using namespace std;

void Turma::alunos()
{
    int n = 1;
    if(_alunos.empty()) {
        cout << "> NAO TEM ALUNOS" << endl;
        return;
    }
    cout << "> ALUNOS:" << endl;
    for (Pessoa *aluno : _alunos) {
        cout << "> " << n++ << ": " << aluno->nome() << endl;
    }
}

// add student
bool Turma::aluno(Pessoa *aluno)
{
    if(_alunos.size() < N) {
        _alunos.push_back(aluno);
        return true;
    }
    return false;
}

// get student
Pessoa *Turma::aluno(string bi)
{
    for(Pessoa *aluno : _alunos) {
        if(aluno->bi() == bi) return aluno;
    }
    return nullptr;
}

// remove student
bool Turma::anula(string bi)
{
    vector<Pessoa *>::iterator aluno = _alunos.begin();
    for(aluno; aluno != _alunos.end(); aluno++) {
        if ((*aluno)->bi() == bi) {
            _alunos.erase(aluno);
            return true;
        }
    }
    return false;
}

// constructor
Turma::Turma(Pessoa *professor)
{
    _professor = professor;
}
