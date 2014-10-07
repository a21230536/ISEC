// Ficha 2, Exercício 7
#include <iostream>
#include <sstream>// (c)
#include <string>

using namespace std;

//-----------------------------------------------------------------------------
// (a) Construir uma classe ...
//-----------------------------------------------------------------------------
class MSG{
	char letra;
	int num;

public:
	string getAsString();
	static int contador;

	//-------------------------------------------------------------------------
	// (f) Remover da classe MSG a característica que permite que os seus
	//     objectos fiquem com a letra ‘x’ se nenhuma letra for especificada.
	//-------------------------------------------------------------------------
	// R: causa erro ao compilar quando inicializado sem o argumento c
	//MSG(char c);

	// construtor
	MSG(char c='x');

	// *Construtor por cópia
	MSG(MSG& ob);

	// destrucor
	~MSG();

};

int MSG::contador = 0;

// (g)
void teste();

int main(){
	MSG a('a'), b;

	//-------------------------------------------------------------------------
	// (b) Uma referência com o nome c para o objecto que tem a letra ‘x’.
	//-------------------------------------------------------------------------
	// R: Não há evidência (ou testemunho) de ter sido criado algum objecto.
	MSG& c = b;

	//-------------------------------------------------------------------------
	// (c) Acrescentar à função main ... a seguinte declaração: MSG d=b;
	//-------------------------------------------------------------------------
	// R: d é um novo object, uma cópia (ver construção por cópia)* do objecto b
	MSG d = b;

	//-------------------------------------------------------------------------
	// (d) Acrescentar à função main a seguinte declaração: a = b;
	//-------------------------------------------------------------------------
	// R: a fica com os valores de b
	a = b;

	//-------------------------------------------------------------------------
	// (e) Acrescentar uma matriz de objectos de MSG de dimensão dois.
	//-------------------------------------------------------------------------
	MSG mat1[2];
	// R: sim... //MSG mat0[2] = {{'O'}, {'P'}};
	//TODO testar no Visual Studio
	// construção por omissão
	//MSG mat[] = {MSG(), MSG()};
	//MSG mat[2] = {'M', 'N'};
	//MSG mat[] = {MSG('M'), MSG('N')};

	//-------------------------------------------------------------------------
	// (g) Acrescentar uma função teste do tipo void e sem parâmetros e
	//     declarar nela um objecto MSG aux inicializado com a letra ‘y’.
	//-------------------------------------------------------------------------
	// compila (g++) sem erros/avisos; inicializado um objecto com a letra 'y'
	teste();// provavelmente erro de comunicação no enunciado ...

	//a = w('W'), z('Z');

    return 0;
}

// Construtor
MSG::MSG(char c){
	letra = c;
	num = ++contador;

	cout << "\ncriado: " << getAsString();
}

// *Construtor por cópia
MSG::MSG(MSG& ob){
	//letra = ob.letra;
	letra = 'y';
	num = -ob.num;

	cout << "\ncriado por copia: " << getAsString();
}

// Destrutor (não pode ter parâmetros nem tipo de retorno)
MSG::~MSG(){
	cout << "\nterminado: " << getAsString();
}

string MSG::getAsString(){
	ostringstream oss;
	oss << "letra: " << letra << "; numero: " << num << endl;

	return oss.str();
}

// (g)
void teste(){
	MSG aux('y');
}

//-----------------------------------------------------------------------------
// ()
//-----------------------------------------------------------------------------
// R:
