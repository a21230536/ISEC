#include <iostream>
#include "Desenho.h"

using namespace std;

int main()
{
    Desenho desenho;
    cout << "> desenho.areas();// " << desenho.areas() << endl;

    Ponto O(0, 0);
    Rectangulo retangulo(O, 7, 8);
    desenho.retangulo(retangulo);
    cout << "\n>\n> desenho.areas();// " << desenho.areas() << endl;

    Ponto P(10, 17);
    Rectangulo retangulo2(P, 2, 8);
    desenho.retangulo(retangulo2);

    Ponto Q(3, 3);
    Rectangulo retangulo3(Q, 13, 3);
    if (!desenho.retangulo(retangulo3)) {
        cout << "\n>\n> ERRO! Retangulo 3 NAO adicionado ao desenho." << endl;
    }

    cout << "> desenho.str();// " << desenho.str();
    cout << "> desenho.eliminar(1000);// " << desenho.eliminar(1000);

    return 0;
}
