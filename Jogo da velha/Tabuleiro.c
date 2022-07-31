#include "Tabuleiro.h"

void iniciaTabuleiro() {

	for (int lin = 0; lin < LINHA; lin++) {
		for (int col = 0; col < COLUNA; col++) {
			jogo[lin][col] = ' ';
		}
	}
}