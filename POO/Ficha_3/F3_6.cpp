#include <iostream>
#include <string>
#include <vector>
#include "clube.h"

using namespace std;

int main()
{
    // PESSOA
    Pessoa pessoa("dummie", "00000000 0xx", "999 999 999");
    cout << "> NOME: " << pessoa.nome() << endl;
    cout << ">   BI: " << pessoa.bi() << endl;
    cout << ">  NIF: " << pessoa.nif() << endl;
    cout << ">" << endl;

    // CLUBE
    Pessoa ze("Jose", "0678996 9xy", "197 501 532");
    Clube clube("Clubex", "xxx");
    clube.lista();
    cout << ">" << endl;
    clube.adiciona(ze);
    clube.lista();

    return 0;
}
