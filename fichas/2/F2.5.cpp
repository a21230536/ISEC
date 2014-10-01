// Ficha 2, Exercício 5
#include <iostream>
#include <string>

using namespace std;
//-----------------------------------------------------------------------------
// (a) Analisar o problema...
//-----------------------------------------------------------------------------
// (b) Definir a estrutura Automovel e escrever as funções identificadas.
//-----------------------------------------------------------------------------
struct Automovel{
	string matricula;
	string combustivel;
	string marca;
	string modelo;
	string cor;
	string outros;//int ano;//int rodas;

	// funções para obter valores
	string getMatricula();
	string getCombustivel();
	string getMarca();
	string getModelo();
	string getCor();
	string getOutros();

	// funções para o atribuir/modificar valore
	void setMatricula(string);
	void setCombustivel(string);
	void setMarca(string);
	void setModelo(string);
	void setCor(string);
	void setOutros(string);

	// funções para manipular todos os valores
	void mostra();
	void setPorCin();

	// função modifica os valores por argumentos (c)
	void set(string matricula, string combustivel, string marca,
		string modelo, string cor, string outros);
};

int main(){
	Automovel automovel;

	automovel.set("AH-23-21-AJ", "gasoleo", "Opel", "Corsa", "preto", "especial");
	automovel.mostra();

	while(true){
		automovel.setPorCin();
		cout << automovel.getString() << endl;
	}

	return 0;
}

// mostra na consola todos os valores
void Automovel::mostra(){
	cout << endl
	     << "Automovel" << endl
	     << "Matricula: " << getMatricula() << endl
	     << "Combustivel: " << getCombustivel() << endl
	     << "Marca: " << getMarca() << endl
	     << "Modelo: " << getModelo() << endl
	     << "Cor: " << getCor() << endl
	     << "Outros: " << getOutros() << endl
	     << endl;
}

// modifica as variáveis com valores obtidos pela consola
void Automovel::setPorCin(){
	string mat, com, mar, mod, cor, out;

	cout << "Matricula: ";
	getline(cin, mat);
	setMatricula(mat);

	cout << "Combustivel: ";
	getline(cin, com);
	setCombustivel(com);

	cout << "Marca: ";
	getline(cin, mar);
	setMarca(mar);

	cout << "Modelo: ";
	getline(cin, mod);
	setModelo(mod);

	cout << "Cor: ";
	getline(cin, cor);
	setCor(cor);

	cout << "Outros: ";
	getline(cin, out);
	setOutros(out);
}

//-----------------------------------------------------------------------------
// (c) Escrever uma função que preencha o conteúdo de uma variável do tipo
//     Automovel com valores fornecidos. Evitar interagir com o utilizador
//     directamente dentro das funções que manipulam os dados da estrutura.
//-----------------------------------------------------------------------------
void Automovel::set(string mat, string com, string mar,
		string mod, string cor, string out){
	setMatricula(mat);
	setCombustivel(com);
	setMarca(mar);
	setModelo(mod);
	setCor(cor);
	setOutros(out);
}

//-----------------------------------------------------------------------------
// (d) Escreva funções que permitam obter e actualizar cada dado desta estrutura.
//-----------------------------------------------------------------------------
string Automovel::getMatricula(){
	return matricula;
}

string Automovel::getCombustivel(){
	return combustivel;
}

string Automovel::getMarca(){
 return marca;
}

string Automovel::getModelo(){
	return modelo;
}

string Automovel::getCor(){
	return cor;
}

string Automovel::getOutros(){
	return outros;
}
void Automovel::setMatricula(string s){
	matricula = s;
}

void Automovel::setCombustivel(string s){
	combustivel = s;
}

void Automovel::setMarca(string s){
	marca = s;
}

void Automovel::setModelo(string s){
	modelo = s;
}

void Automovel::setCor(string s){
	cor = s;
}

void Automovel::setOutros(string s){
	outros = s;
}
