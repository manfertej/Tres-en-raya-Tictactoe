#include "Tablero.h"


Tablero::Tablero() {
	this->acabado = false;
	this->ganador = NULL;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			this->t[i][j] = ' ';
		}
	}
}



void Tablero::imprimir() {
	for (int i = 0; i < 3; i++) {
		cout << " " << this->t[i][0] << " | " << this->t[i][1] << " | " << this->t[i][2] << endl;
		
		if (i != 2) {
			cout << "-----------" << endl;
		}
	}
}



bool Tablero::valido(int mov) {
	int i = mov / 3, j = mov % 3;
	if (t[i][j] == ' ') {
		return true;
	}
	
	return false;
}



void Tablero::marcar(int mov, char ficha) {
	
	if (this->valido(mov)) {
		int i = mov / 3;
		int j = mov % 3;

		t[i][j] = ficha;
		this->huecos--;
	}
	this->check();
}

void Tablero::desmarcar(int mov) {
	this->t[int(mov / 3)][mov % 3] = ' ';
	this->ganador = NULL;
	this->acabado = false;
	this->huecos++;
}



void Tablero::check() {
	
	//Filas y columnas
	for (int i = 0; i < 3; i++) {
		
		if ((this->t[i][0] == this->t[i][1] && this->t[i][0] == this->t[i][2] && this->t[i][0] !=' ') || (this->t[0][i] == this->t[1][i] && this->t[0][i] == this->t[2][i] && this->t[0][i] != ' ')) {
			this->acabado = true;
			this->ganador = t[i][i];
			return;
		}

		
	}
	
	//Diagonales
	if (this->t[0][0] == this->t[1][1] && this->t[0][0] == this->t[2][2] && this->t[0][0] != ' ' || this->t[0][2] == this->t[1][1] && this->t[0][2] == this->t[2][0] && this->t[0][2] != ' ') {
		this->acabado = true;
		this->ganador = t[1][1];
		return;
	}
	
	//El tablero esta lleno?
	if (this->huecos == 0) {
		this->acabado = true;
		this->ganador = ' ';
	}

}



int iaMov(Tablero& tab) {
	int resultado, mejorResultado = mInf, mejorMov;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (tab.valido(i*3+j)) {
				
				tab.marcar(i*3+j, ai);
				resultado = minimax(tab, false);
				tab.desmarcar(i * 3 + j);
				if (resultado > mejorResultado){
					mejorResultado = resultado;
					mejorMov = i * 3 + j;


				}
			}
		}

	}

	return mejorMov;
}



int minimax(Tablero& t, const bool& max) {
	int resultado, mejor;

	
	t.check();
	if (t.wiiner() != NULL) {
		if (t.winner() == 'X') resultado = -1;
		if (t.winner() == 'O') resultado = 1;
		if (t.winner() == ' ') resultado = 0;

		return resultado;
	}

	if (max) {
		mejor = mInf;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (t.valido(i * 3 + j)) {
					t.marcar(i * 3 + j, ai);
					resultado = minimax(t, !max);
					t.desmarcar(i * 3 + j);
					if (resultado > mejor) {
						mejor = resultado;
					}
				}

			}
		}
		return mejor;
	}
	else {
		mejor = MINF;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (t.valido(i * 3 + j)) {
					t.marcar(i * 3 + j, player);
					resultado = minimax(t, !max);
					t.desmarcar(i * 3 + j);
					if (resultado < mejor) {
						mejor = resultado;
					}
				}

			}
		}
		return mejor;
	}
}

