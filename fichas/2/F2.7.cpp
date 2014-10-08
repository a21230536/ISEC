// ConsoleApplication1.cpp : Defines the entry point for the console application.
//#include "stdafx.h"// para o Visual Studio

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

	//-------------------------------------------------------------------------
	// (i) "Acrescente um construtor privado à classe MSG que recebe como
	//      parâmetro o seguinte: 'const MSG& z' e lhe dê um corpo vazio
	// R: Construtor privado fica inaacessível
	//-------------------------------------------------------------------------
	//MSG(const MSG& z);

public:
	void setLetra(char c){
		letra = c;
	}

	void setNum(int n){
		num = n;
	}

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

	//-------------------------------------------------------------------------
	// (j) "Passe o construtor a publico e coloque no seu corpo apenas a
	//      seguinte linha cout << 'construído por cópia';
	//-------------------------------------------------------------------------
	MSG(const MSG& z);// se passarmos para a parte privada, fica inaacessível

	//-------------------------------------------------------------------------
	// (k) s/const
	//-------------------------------------------------------------------------
	MSG(MSG& ob);// Construtor por cópia

	// destrucor
	~MSG();

};

int MSG::contador = 0;

//-----------------------------------------------------------------------------
// (g) Acrescentar uma função teste do tipo void e sem parâmetros e
//     declarar nela um objecto MSG aux inicializado com a letra ‘y’.
//-----------------------------------------------------------------------------
// (g++) compila sem erros/avisos; inicializado um objecto com a letra 'y'
// (ms) o objecto é destruido ao sair da função
void teste_g(){
	MSG aux('y');
}

//-----------------------------------------------------------------------------
// (h) modificar a função de forma a que receba como parâmetro um objecto MSG
//-----------------------------------------------------------------------------
void teste_h(MSG z){
	MSG aux('y');
}

//-----------------------------------------------------------------------------
// (l) modificar função para que o seu parâmetro seja passado por referência
//-----------------------------------------------------------------------------
// apenas aux é criado (e destruido ao sair da função)
void teste_l(MSG& z){
	cout << "z eh b >>> " << z.getAsString();
	MSG aux('y');
}

//-----------------------------------------------------------------------------
// (m) modificar a função para retornar um objecto do tipo MSG... s/parametros
//----------------------------------------------------------------------------
MSG teste_m(){
	MSG aux('y');
	return aux;
}

//-----------------------------------------------------------------------------
// (n) modificar função teste para que o retorno passe a ser por referência
//-----------------------------------------------------------------------------
MSG& teste_n(MSG& aux){
	cout << "A alterar a letra de aux/a para 'A'" << endl;
	aux.setLetra('B');
	return aux;
}

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
	// R: sim: MSG mat[2] = {'M', 'N'};
	//MSG mat0[2] = {{'O'}, {'P'}};
	//TODO testar no Visual Studio
	// construção por omissão
	//MSG mat[] = {MSG(), MSG()};
	//MSG mat[] = {MSG('M'), MSG('N')};

	//-------------------------------------------------------------------------
	cout << ">>>Inicio (g)" << endl;
	teste_g();
	cout << "<<<Fim (g)" << endl;
	//-------------------------------------------------------------------------
	cout << ">>>Inicio (h)" << endl;
	teste_h(a);
	cout << "<<<Fim (h)" << endl;
	//-------------------------------------------------------------------------
	cout << ">>>Inicio (l)" << endl;
	teste_l(b);
	cout << "<<<Fim (l)" << endl;
	//-------------------------------------------------------------------------
	cout << ">>>Inicio (m)" << endl;
	a = teste_m();
	cout << "<<<Fim (m)" << endl;
	//-------------------------------------------------------------------------
	cout << ">>>Inicio (n)" << endl;
	b = teste_n(a);
	cout << "<<<Fim (n)" << endl;
	//-------------------------------------------------------------------------

    return 0;
}

// Construtor
MSG::MSG(char c){
	letra = c;
	num = ++contador;

	cout << "criado: " << getAsString();
}


MSG::MSG(const MSG& z){
	cout << "construido por copia (j)" << endl;
}

// *Construtor por cópia
MSG::MSG(MSG& ob){
	//letra = ob.letra;
	letra = 'y';
	num = -ob.num;

	cout << "*criado por copia* " << getAsString();
}

// Destrutor (não pode ter parâmetros nem tipo de retorno)
MSG::~MSG(){
	cout << "terminado: " << getAsString();
}

string MSG::getAsString(){
	ostringstream oss;
	oss << "letra: " << letra << "; numero: " << num << endl;

	return oss.str();
}

/* Explicação da profwssora no final da aula (a uma pergunta de um aluno)
#ifndef MSG_H
#define MSG_H
// fazer algo...
#enif
*/
