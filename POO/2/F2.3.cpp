// Ficha 2, Exercício 3
#include <iostream>
#include <string>

using namespace std;

// estrutura Caderno
struct Caderno {
	string marca;
	string cor;
	string tamanho;
	int nFolhas;
};

// protótipo para (a)
void preenche(Caderno&);
//void inicializa(Caderno&, string marca,...);

// protótipos para (b)
string getMarca(Caderno);
string getCor(Caderno);
string getTamanho(Caderno);
int getNFolhas(Caderno);

// protótipos para (c)
void setMarca(Caderno&);
void setCor(Caderno&);
void setTamanho(Caderno&);
void setNFolhas(Caderno&);

// função principal
int main(){
	// caderno é estrutura do tipo Caderno
	Caderno caderno;

	// preencher caderno
	preenche(caderno);

	// mostrar os valores de caderno
	cout << endl;
	cout << "marca: " << getMarca(caderno) << endl;
	cout << "cor: " << getCor(caderno) << endl;
	cout << "tamanho: " << getTamanho(caderno) << endl;
	cout << "nFolhas: " << getNFolhas(caderno) << endl;

	return 0;
}

//-----------------------------------------------------------------------------
// (a) função que preenche valores da estrutura do tipo Caderno
//-----------------------------------------------------------------------------
void preenche(Caderno& caderno){
	setMarca(caderno);
	setCor(caderno);
	setTamanho(caderno);
	setNFolhas(caderno);
}

//-----------------------------------------------------------------------------
// (b) Funções para obter valores da estrutura do tipo Caderno
//-----------------------------------------------------------------------------
string getMarca(Caderno caderno){
	return caderno.marca;
}
string getCor(Caderno caderno){
	return caderno.cor;
}
string getTamanho(Caderno caderno){
	return caderno.tamanho;
}
int getNFolhas(Caderno caderno){
	if(caderno.nFolhas <0 ) return 0;
	return caderno.nFolhas;
}

//-----------------------------------------------------------------------------
// (c)  Funções para atribuir/modificar valores da estrutura do tipo Caderno
//-----------------------------------------------------------------------------
void setMarca(Caderno& caderno){
	cout << "Marca: ";
	getline(cin, caderno.marca);
}
void setCor(Caderno& caderno){
	cout << "Cor: ";
	getline(cin, caderno.cor);
}
void setTamanho(Caderno& caderno){
	cout << "Tamanho: ";
	getline(cin, caderno.tamanho);
}
void setNFolhas(Caderno& caderno){
	cout << "Folhas: ";
	cin >> caderno.nFolhas;
}
