#include <iostream>
#include <cmath>
#include <sstream>

#include "Ponto.h"

using namespace std;

Ponto::Ponto(int a, int b){
	x = a;
	y = b;
	cout << "Ponto criado (" << x << ", " << y << ")" << endl;

	/*/ desenvolvimento não influenciado
	X(a);
	Y(b);
	cout << "Ponto(x,y)=(" << X() << "," << Y() << ")" << endl;
	//*/
}

int Ponto::getX() const {
	return x;
	//return x++;// ERRO! porque x é constante
}

void Ponto::setX(int n){
	x = n;
}

int Ponto::getY() const {
	return y;
	//return this->x;
}

void Ponto::setY(int n){
	y = n;
}

double Ponto::calcDist(const Ponto& P) const{
	//double d2 = (x - P.x)*(x - P.x) + (y - P.y)*(y - P.y);
	int X = x - P.x, Y = y - P.y;

	//return sqrt(d2);
	return sqrt(X*X + Y*Y);
}

string Ponto::getString(){
	ostringstream textual;
	textual << "(" << x << ", " << y << ")" << endl;

	return textual.str();
}

/*/ desenvolvimento não influenciado pelos instrutores
int Ponto::X() const{
	return x;
}
void Ponto::X(int X){
	x = X;
}
int Ponto::Y() const{
	return y;
}
void Ponto::Y(int Y){
	y = Y;
}
//*/
