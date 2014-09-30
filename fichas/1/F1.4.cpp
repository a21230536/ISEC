// Ficha 1,Exercício 4
// Escrever o código necessário para que a seguinte função main execute sem erros.
/*
void main(){
   imprime("ola");
   imprime("a idade é: ", 25);
   imprime(100, "euros");
}
*/

#include <iostream>

using namespace std;

void imprime(string s) {
    cout << "A imprimir string: " << s << endl;
}

void imprime(string s, int n) {
    cout << "A imprimir texto: " << s << n << endl;
}

void imprime(int n, string s) {
    cout << "A imprimir texto: " << s << n << endl;
}

int main() {
    imprime("ola");
    imprime("a idade é: ", 25);
    imprime(100, "euros");

    return 0;
}
