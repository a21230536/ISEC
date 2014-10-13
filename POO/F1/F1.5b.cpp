// Ficha 1, Exercício 5
//-----------------------------------------------------------------------------
// (b) argumentos de funções com valores por omissão
//-----------------------------------------------------------------------------
#include <iostream>

using namespace std;

int soma(int i=0, int j=0, int k=0){
    return i + j + k;
}

int main(){
    cout << "\n" << soma() << soma(1);
    cout << soma(1, 2) << soma(1, 2, 3) << "\n";
    return 0;
}
