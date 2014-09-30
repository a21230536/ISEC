// Ficha 2, Exercício 4
//-----------------------------------------------------------------------------
// Enunciado do exercício anterior, com Caderno como class (em vez de struct)
//-----------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

// class é a estrutura de um objecto
class Caderno {
//private:// já é private por defeito
	string marca;
	string cor;
	string tamanho;
	int nFolhas;

public:
	// variáveis
	string getMarca();
	string getCor();
	string getTamanho();
	int getNFolhas();

	// funções para obter valores
	void setMarca();
	void setCor();
	void setTamanho();
	void setNFolhas();

	// funções para atribuir valores
	void mostra();
	void preenche();

	// construtor (executa ao inicializar o objecto, a instância da class)
	Caderno(string m="M", string c="C", int n=0, string t="X");
};

int main(){
	// objecto caderno, instância de Caderno, sem valores iniciais
	Caderno caderno;
	// mostra os valores (atribuídos por omissão pelo construtor) de caderno
	caderno.mostra();

	// outro objecto, caderno2, com valores iniciais para o construtor
	Caderno caderno2("MARCA", "COR", 0, "TAMANHO");
	// mostra os valores de caderno2
	caderno2.mostra();

	// preencher caderno com dados do utilizador
	caderno.preenche();
	// mostrar os novos valores de caderno
	caderno.mostra();

	return 0;
}

// Inicializa objectos da class Caderno
Caderno::Caderno(string m, string c, int n, string t){
	cout << "__constructor\n";
	marca = m;
	cor = c;
	tamanho = t;
	nFolhas = n;
}

// Mostra todos os valores das variáveis...
void Caderno::mostra(){
	cout << endl;
	cout << "marca: " << getMarca() << endl;
	cout << "cor: " << getCor() << endl;
	cout << "tamanho: " << getTamanho() << endl;
	cout << "nFolhas: " << getNFolhas() << endl;
	cout << endl;
}

// preenche instâncias de Caderno
void Caderno::preenche(){
	setMarca();
	setCor();
	setTamanho();
	setNFolhas();
}

// Obtém o valor da variável marca
string Caderno::getMarca(){
	return marca;
}

// Obtém o valor da variável cor
string Caderno::getCor(){
	return cor;
}

// Obtém o valor da variável tamanho
string Caderno::getTamanho(){
	return tamanho;
}

// Obtém o valor da variável nFolhas
int Caderno::getNFolhas(){
	if(nFolhas <0 ) return 0;
	return nFolhas;
}

// Atribúi valor à variável marca
void Caderno::setMarca(){
	cout << "Marca: ";
	getline(cin, marca);
}

// Atribúi valor à variável cor
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
