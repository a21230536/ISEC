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

void testRectangulo(Rectangulo &, char s[]="a");
void linha(int n = 80, char c = '-');

int main()
{
    Ponto P;
    Rectangulo A(&P, 72, 73);// II
    Rectangulo B(60,61,62,63);// I
    Rectangulo C(Ponto(80, 81), 82, 83);// III (CENÁRIO DO ENUNCIADO)

    //-----------------------------------------------------------------------------------------------------------------
    // (b) Um objecto ponto p1 nas coordenadas (1,2) e dois rectângulos a e b quaisquer que partilham o mesmo ponto ...
    //     Apresentar os dados de todos os objectos no ecrã.
    //-----------------------------------------------------------------------------------------------------------------
    Ponto p1(1, 2);
    Rectangulo a(p1, 4, 5);
    Rectangulo b(p1, 6, 7);
    linha();
    cout << "> p1.str();// " << p1.str() << endl;
    linha();
    testRectangulo(a);
    linha();
    testRectangulo(b, "b");

    //-----------------------------------------------------------------------------------------------------------------
    // (c) Modificar as coordenadas do ponto do rectângulo a para (4, 5) ...
    //-----------------------------------------------------------------------------------------------------------------
    linha();
    cout << "> a.P.X(4);" << endl;
    a.P.X(4);
    cout << "> a.P.Y(5);" << endl;
    a.P.Y(5);
    linha();
    testRectangulo(a);
    linha();
    testRectangulo(b, "b");
    linha();

    return 0;
}

void testRectangulo(Rectangulo &a, char s[])
{
    cout << "> " << s << ".P.str();// " << a.P.str() << endl;
    cout << "> " << s << ".largura();// " << a.largura() << endl;
    cout << "> " << s << ".altura();// " << a.altura() << endl;
    cout << "> " << s << ".area();// " << a.area() << endl;
    cout << "> " << s << ".perimetro();// " << a.perimetro() << endl;
}

void linha(int n, char c)
{
    for (int i = 0; i < n; i++) cout << c;
    //cout << endl;
}
