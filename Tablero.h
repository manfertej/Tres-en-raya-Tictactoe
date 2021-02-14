#include<iostream>

using namespace std;

#define player  'X'
#define ai  'O'

//En ningun caso estaré fuera de [-1, 1], asi que estos son mis infinitos virtuales.
#define mInf -2
#define MINF 2


#pragma once


class Tablero {

	private:
	char t[3][3];
	int huecos = 9;

	bool acabado;
	char ganador;


	public:
	Tablero();

	bool fin() { return this->acabado; }
	char winner() { return this->ganador; }

	void imprimir();
	bool valido(int mov);
	void marcar(int mov, char ficha);
	void desmarcar(int mov);
	void check();
	
	friend int iaMov(Tablero& t);
	friend int minimax(Tablero& t, const bool& max);


};

