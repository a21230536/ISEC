// Ficha 2, Exercício 6
#include <iostream>
#include <sstream>// (c)
#include <string>

using namespace std;
//-----------------------------------------------------------------------------
// (a) Construir a classe Automovel com as características enunciadas e incluir
//     na função main código que permite testar a classe.
//-----------------------------------------------------------------------------
class Automovel{
	string matricula;
	string combustivel;
	string marca;
	string modelo;
	string cor;
	string outros;

public:

	// funções para obter valores
	string getMatricula();
	string getCombustivel();
	string getMarca();
	string getModelo();
	string getCor();
	string getOutros();

	// funções para o atribuir/modificar valore
	int setMatricula(string);
	int setCombustivel(string);
	int setMarca(string);
	int setModelo(string);
	int setCor(string);
	int setOutros(string);

	// funções para manipular todos os valores
	void mostra();
	void setPorCin();
	int setAttr(string);

	// função modifica os valores por argumentos
	void set(string matricula, string combustivel, string marca,
		string modelo, string cor, string outros);

	// devolve representação textual (c)
	string getString();

	// executar o construtor com valores por omissão
	Automovel(string mat="N/D", string com="N/D", string mar="N/D",
		string mod="N/D", string cor="N/D", string out="N/D");
};

int main(){
	Automovel automovel;

	// mostrar valores oblidos por omissão
	automovel.mostra();

	automovel.set("AH-23-21-AJ", "gasoleo", "Opel", "Corsa", "preto", "especial");
	automovel.mostra();

	while(true){
		automovel.setPorCin();
		cout << automovel.getString() << endl;
	}

	return 0;
}

//-----------------------------------------------------------------------------
// (b) Analisar as regras mais óbvias do mundo real acerca de automóveis,
//     nomeadamente no que diz respeito à sua construção e inicialização...
//-----------------------------------------------------------------------------

// construtor
Automovel::Automovel(string mat, string com, string mar,
		string mod, string cor, string out){
	// validar os valores aqui (b)

	set(mat, com, mar, mod, cor, out);
}

//-----------------------------------------------------------------------------
// (c) Escrever uma função que permite obter a representação textual dos
//     valores do objecto...
//-----------------------------------------------------------------------------
string Automovel::getString(){
	ostringstream automovelString;

	automovelString << "\nAutomovel\nMatricula:" << matricula
		<<"\nCombustivel:" << combustivel
		<<"\nMarca: " << marca
		<< "\nModelo: " << modelo
		<<"\nCor: " << marca
		<< "\nOutros: " << outros << endl;

	return automovelString.str();
}

// mostra na consola todos os valores do objecto
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

int Automovel::setAttr(string attr){
	string valor;
	attr[0] = toupper(attr[0]);

	while (true){
		cout << attr << ": ";
		getline(cin, valor);

		if(attr == "Matricula")
			return setMatricula(valor);

		if(attr == "Combustivel")
			return setCombustivel(valor);

		if(attr == "Marca")
			return setMarca(valor);

		if(attr == "Modelo")
			return setModelo(valor);

		if(attr == "Cor")
			return setCor(valor);

		if(attr == "Outros")
			return setOutros(valor);

		return 0;
	}
}

// modifica as variáveis com valores obtidos pela consola
void Automovel::setPorCin(){
	while(!setAttr("matricula"));
	while(!setAttr("combustivel"));
	while(!setAttr("marca"));
	while(!setAttr("modelo"));
	while(!setAttr("cor"));
	while(!setAttr("outros"));
}

void Automovel::set(string mat, string com, string mar,
		string mod, string cor, string out){
	setMatricula(mat);
	setCombustivel(com);
	setMarca(mar);
	setModelo(mod);
	setCor(cor);
	setOutros(out);
}

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

int Automovel::setMatricula(string s){
	// validar o valor de s aqui (b)
	if(false) return 0;

	matricula = s;
	return 1;
}

int Automovel::setCombustivel(string s){
	// validar o valor de s aqui (b)
	if(false) return 0;

	combustivel = s;
	return 1;
}

int Automovel::setMarca(string s){
	// validar o valor de s aqui (b)
	if(false) return 0;

	marca = s;
	return 1;
}

int Automovel::setModelo(string s){
	// validar o valor de s aqui (b)
	if(false) return 0;

	modelo = s;
	return 1;
}

int Automovel::setCor(string s){
	// validar o valor de s aqui (b)
	if(false) return 0;

	cor = s;
	return 1;
}

int Automovel::setOutros(string s){
	// validar o valor de s aqui (b)
	if(false) return 0;

	outros = s;
	return 1;
}
