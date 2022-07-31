#include "Tabuleiro.h"
#include "ValidaCoordenada.h"


int ganhouLinha() {
	int i, j, igual = 1;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			if (eValido(jogo[i][j]) && jogo[i][j] == jogo[i][j + 1]) {
				igual++;
			}
		}
		if (igual == 3)
			return 1;
		igual = 1;
	}
	return 0;
}

int ganhouColuna() {
	int i, j, igual = 1;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			if (eValido(jogo[j][i]) && jogo[j][i] == jogo[j + 1][i]) {
				igual++;
			}
		}
		if (igual == 3)
			return 1;
		igual = 1;
	}
	return 0;
}

int ganhouPrincipal() {
	int igual = 1;
	for (int i = 0; i < 2; i++) {
		if (eValido(jogo[i][i]) && jogo[i][i] == jogo[i + 1][i + 1]) {
			igual++;
		}
	}
	if (igual == 3)
		return 1;
	else
		return 0;

}

int ganhouSecundaria() {
	int igual = 1;
	for (int i = 0; i < 2; i++) {
		if (eValido(jogo[i][2 - i]) && jogo[i][2 - i] == jogo[i + 1][2 - i - 1]) {
			igual++;
		}

	}
	if (igual == 3)
		return 1;
	else
		return 0;

}