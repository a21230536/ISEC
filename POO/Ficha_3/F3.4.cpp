#include <iostream>
#include "Desenho.h"

using namespace std;

int main()
{
    //Ponto::log = true;
    //Rectangulo::log = true;
    Desenho::log = true;

    // criar um desemho
    Desenho desenho;
    cout << "> desenho.areas();// " << desenho.areas() << endl;

    // testar (i) adicionar retângulos ao desenho
    desenho.retangulo(Rectangulo(Ponto(0, 0), 7, 8));// 1
    cout << "> desenho.areas();// " << desenho.areas() << endl;
    Rectangulo retangulo(Ponto(3, 3), 13, 3);// 2
    if (!desenho.retangulo(retangulo)) {// retângulo intersecta outro existente
        cout << "> INTERSECTA! Retangulo " << retangulo.str() << " NAO adicionado ao desenho." << endl;
    }

    // adicionar dois retângulos no mesmo ponto...
    Ponto P(10, 17);
    desenho.retangulo(Rectangulo(P, 2, 8));// 3
    desenho.retangulo(Rectangulo(P, 4, 9));// 4
    
    // testar (ii) obter um conjunto de retângulos no mesmo ponto
    vector<Rectangulo> conjunto = desenho.conjunto(P);
    for (Rectangulo elemento : conjunto) {
        cout << "> elemento.str();" << elemento.str() << endl;
    }

    // testar (iii) eliminar retângulos com area superior a 50
    cout << "> desenho.eliminar(50);" << endl;
    int n = desenho.eliminar_area_superior(50);
    cout << "> fo" << (n == 1? "i eliminado " : "ram eliminados ") << n << " retangulo" << (n != 1? "s" : "") 
         << endl;

    // testar (iv) obter a área total dos retângulos
    cout << "> desenho.areas();// " << desenho.areas() << endl;

    // testar (v) obter informação sobre o desenho
    cout << "> desenho.str();// " << desenho.str() << endl;

    return 0;
}
