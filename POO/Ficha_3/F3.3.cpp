#include <iostream>
#include "Ponto.h"
#include "Rectangulo.h"

using namespace std;

//---------------------------------------------------------------------------------------------------------------------
// (a) Ser� uma c�pia que pertence exclusivamente ao rect�ngulo ? Ou dever� ser um objecto ponto que existe fora do
//     objecto rect�ngulo e que pode ser partilhado entre v�rios rect�ngulos distintos?
//---------------------------------------------------------------------------------------------------------------------
// Se o ponto descreve a posi��o desse rect�ngulo no plano, ent�o o Ponto deve pertencer exclusivamente ao Rectangulo;
// se o ponto depender de uma fonte externa, ent�o o Ponto n�o deve pertencer diretamente ao Rectangulo.

int main()
{
    Ponto O(0, 10);
    Rectangulo A(&O, 2, 3);
    Rectangulo B(20, 30, 40, 41);
    //const Rectangulo C();

    A.O.X(7);
    A.O.Y(8);

    O.X(9);
    O.Y(10);

    cout << "> A.area();// => " << A.area() << endl;
    cout << "> B.area();// => " << B.area() << endl;
}
