#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#include "Ganhou.h"
#include "Tela.h"
#include "Tabuleiro.h"
#include "ValidaInput.h"
#include "ValidaCoordenada.h"

void jogar();

int main() {
	int maisUma = 1;
	do {
		ganhou = 0;
		iniciaTabuleiro();
		jogar();

		printf("\nJogar Novamente 1: \n");
		printf("Sair 2: \n");
		scanf("%d", &maisUma);

	} while (maisUma != 2);

	return 0;
}

void jogar() {
	int play = 1, jogadas = 0;
	int x, y, valida;
	do {
		int invalida = 0;
		do {
			limpaTela();
			imprimirTela(play, ganhou);

			printf("\n      Player %d\n", play);

			if (invalida != 0)
				printf("      Cordenada [%s] ja ocupada tente outra!\n", cordenadaDigitada);
			printf("      Cordenada: ");
			invalida++;

			digito();

			x = posX();
			y = posY();

			valida = coordenadaEhValida(x, y);
			if (valida == 1) {
				valida += posicaoVazia(x, y);
			}
		} while (valida != 2);
		if (play == 1) {
			jogo[x][y] = 'X';
		}
		else {
			jogo[x][y] = 'O';
		}
		jogadas++;
		play++;
		if (play == 3) {
			play = 1;
		}

		ganhou += ganhouLinha();
		ganhou += ganhouColuna();
		ganhou += ganhouPrincipal();
		ganhou += ganhouSecundaria();



	} while (ganhou == 0 && jogadas < 9);

	if (jogadas == 9)
		play = 0; //Deu Velha
	else if (play == 2)
		play = 1;
	else
		play = 2;
	limpaTela();
	imprimirTela(play, ganhou);
}