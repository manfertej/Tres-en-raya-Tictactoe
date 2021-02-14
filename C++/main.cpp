#include<iostream>
#include"Tablero.h"

using namespace std;


int main() {
	
	Tablero ta;
	int mov;

	while (!ta.fin()) {
		system("cls");
		ta.imprimir();
		
		
		do {
			cin >> mov;
			
		} while (!ta.valido(mov));
		ta.marcar(mov, 'X');
		
		if (ta.fin()) break;

		system("cls");
		ta.imprimir();

		ta.marcar(iaMov(ta), 'O');
		
	}


	system("cls");
	ta.imprimir();

	if (ta.winner() != ' ') {
		cout << endl << endl << "El ganador es: " << ta.winner();
	}
	else cout <<endl << endl << "Empate";

	cout << "\n\n\n\n\n";


	return 0;
}