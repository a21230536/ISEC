#include <iostream>
#include <cmath>
#include <sstream>
#include "Ponto.h"

using namespace std;

bool Ponto::log = false;

Ponto::Ponto(int x, int y){
    this->x(x), this->y(y);

    if (log) cout << "> Ponto > construindo " << str() << endl;
}

Ponto::~Ponto(){
    if (log) cout << "> ~Ponto > destruindo Ponto " << str() << endl;
}

double Ponto::d(const Ponto& P) const{
    int X = x() - P.x();
    int Y = y() - P.y();

    return sqrt(X*X + Y*Y);
    //double d2 = (x - P.x)*(x - P.x) + (y - P.y)*(y - P.y);
    //return sqrt(d2);
}

string Ponto::str(){
    ostringstream textual;

    textual << "(" << x() << "," << y() << ")";

    return textual.str();
}
