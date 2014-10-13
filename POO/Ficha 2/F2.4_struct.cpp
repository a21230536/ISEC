// Ficha 2, Exercício 4
//-----------------------------------------------------------------------------
// Enunciado do exercício anterior, com as funções dentro da estrutura Caderno
//-----------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

struct Caderno {
    // as variáveis da estrutura
    string marca;
    string cor;
    string tamanho;
    int nFolhas;
    void preenche();
    void mostra();

    // funções para obter valores
    string getMarca();
    string getCor();
    string getTamanho();
    int getNFolhas();

    // funções para atribuir valores
    void setMarca();
    void setCor();
    void setTamanho();
    void setNFolhas();
};

int main(){
    // caderno é instância da estrutura Caderno
    Caderno caderno;

    // preenche caderno
    caderno.preenche();

    // mostrar todos os valores de caderno (estrutura Caderno)
    //AFAZER substituir por função mostra()
    cout << endl;
    cout << "marca: " << caderno.getMarca() << endl;
    cout << "cor: " << caderno.getCor() << endl;
    cout << "tamanho: " << caderno.getTamanho() << endl;
    cout << "nFolhas: " << caderno.getNFolhas() << endl;

    return 0;
}

// preenche (a instância da estrutura) Caderno
void Caderno::preenche(){
    // preencher/atribuir marca
    setMarca();

    // preencher/atribuir cor
    setCor();

    // preencher/atribuir tamanho
    setTamanho();

    // preencher/atribuir nFolhas
    setNFolhas();
}

// mostra o valor da variável marca
string Caderno::getMarca(){
    return marca;
}

// mostra o valor da variável cor
string Caderno::getCor(){
    return cor;
}

// mostra o valor da variável tamanho
string Caderno::getTamanho(){
    return tamanho;
}

// mostra o valor da variável nFolhas
int Caderno::getNFolhas(){
    if(nFolhas < 0 ) return 0;

    return nFolhas;
}

// atribúi valor à variável marca
void Caderno::setMarca(){
    cout << "Marca: ";
    getline(cin, marca);
}

// atribúi valor à variável cor
void Caderno::setCor(){
    cout << "Cor: ";
    getline(cin, cor);
}

// atribúi valor à variável tamanho
void Caderno::setTamanho(){
    cout << "Tamanho: ";
    getline(cin, tamanho);
}

// atribúi valor à variável nFolhas
void Caderno::setNFolhas(){
    cout << "Folhas: ";
    cin >> nFolhas;
}
