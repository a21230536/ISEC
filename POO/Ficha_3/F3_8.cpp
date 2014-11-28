#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "turma.h"

using namespace std;

const string FICHEIRO = "c:\\htdocs\\ISEC\\POO\\Ficha_3\\pessoas.txt";

int main()
{
    ifstream dados(FICHEIRO);
    if (!dados) {
        cout << "> ERRO a abrir o ficheiro " << FICHEIRO << endl;
        exit(1);
    }

    vector<Pessoa> pessoas;
    string nome, bi, nif;
    while(dados >> nome) {
        dados >> bi;
        dados >> nif;
        pessoas.push_back(Pessoa(nome, bi, nif));
    }

    if (pessoas.size() < 30) {
        cout << "> requer pelo menos 30 alunos" << endl;
    }

    Turma um(&pessoas.at(0));
    Turma dois(&pessoas.at(1));
    Turma tres(&pessoas.at(2));

    for (int i = 3; i < 30; i++) {
        um.aluno(&pessoas.at(i));
        if (i % 2) dois.aluno(&pessoas.at(30 - i));
    }

    cout << "> um.alunos();" << endl;
    um.alunos();

    cout << "> dois.alunos();" << endl;
    dois.alunos();
    cout << "> tres.alunos();" << endl;
    tres.alunos();

    cout << "> pessoas.at(3).nome(\"Berta Duarte\");" << endl;
    pessoas.at(3).nome("Berta Duarte");
    cout << "> pessoas.at(5).nome(\"Carlos Alberto\");" << endl;
    pessoas.at(5).nome("Carlos Alberto");

    cout << "> pessoas.at(8).nome();// " << pessoas.at(8).nome() << endl;
    cout << "> pessoas.at(9).nome();// " << pessoas.at(9).nome() << endl;
    cout << "> pessoas.at(10).nome();// " << pessoas.at(10).nome() << endl;
    cout << "> pessoas.at(12).nome();// " << pessoas.at(12).nome() << endl;
    cout << "> pessoas.at(16).nome();// " << pessoas.at(16).nome() << endl;
    cout << "> pessoas.at(21).nome();// " << pessoas.at(21).nome() << endl;
    cout << boolalpha;
    cout << "> um.anula(pessoas.at(8).bi());// " << um.anula(pessoas.at(8).bi()) << endl;
    cout << "> um.anula(pessoas.at(10).bi());// " << um.anula(pessoas.at(10).bi()) << endl;  
    cout << "> um.anula(pessoas.at(12).bi());// " << um.anula(pessoas.at(12).bi()) << endl;
    cout << "> um.anula(pessoas.at(21).bi());// " << um.anula(pessoas.at(21).bi()) << endl;
    cout << "> dois.anula(pessoas.at(9).bi());// " << dois.anula(pessoas.at(9).bi()) << endl;
    cout << "> dois.anula(pessoas.at(16).bi());// " << dois.anula(pessoas.at(16).bi()) << endl;

    cout << "> um.alunos();" << endl;
    um.alunos();
    cout << "> dois.alunos();" << endl;
    dois.alunos();

    return 0;
}
