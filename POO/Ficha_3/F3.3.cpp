#include <iostream>
#include "Ponto.h"
#include "Rectangulo.h"

using namespace std;

//---------------------------------------------------------------------------------------------------------------------
// (a) Será uma cópia que pertence exclusivamente ao rectângulo ? Ou deverá ser um objecto ponto que existe fora do
//     objecto rectângulo e que pode ser partilhado entre vários rectângulos distintos?
//---------------------------------------------------------------------------------------------------------------------
// Se o ponto descreve a posição desse rectângulo no plano, então o Ponto deve pertencer exclusivamente ao Rectangulo;
// se o ponto depender de uma fonte externa, então o Ponto não deve pertencer diretamente ao Rectangulo.

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
