// Ficha 1, Exercício 5
//-----------------------------------------------------------------------------
// (a) Function Overloading/Sobrecarga de Funções
//-----------------------------------------------------------------------------
#include <iostream>

using namespace std;

int soma(){
    return 0;
}

int soma(int i){
    return i;
}

int soma(int i, int j){
    return i+j;
}

int soma(int i, int j, int k){
    return i+j+k;
}

int main(){
    cout << "\n" << soma() << soma(1);
    cout << soma(1,2) << soma(1,2,3) << "\n";

    return 0;
}
