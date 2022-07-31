#include "Tabuleiro.h"

int posicaoVazia(int x, int y) {
	if (jogo[x][y] != 'X' && jogo[x][y] != 'O') {
		return 1;
	}
	else {
		return 0;
	}

}

int coordenadaEhValida(int x, int y) {

	if (x >= 0 && x < LINHA) {
		if (y >= 0 && y < 3) {
			return 1;
		}
	}
	return 0;
}

int eValido(char letra) {
	if (letra == 'X' || letra == 'O')
		return 1;
	else
		return 0;
}