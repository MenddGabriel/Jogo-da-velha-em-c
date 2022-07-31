#include <stdio.h>
#include <windows.h>
#include "Tabuleiro.h"

void imprimirTela(const int player, const int ganhou) {


	printf("     ********************\n"
		"     *  Jogo da Velha!  *\n"
		"     ********************\n\n\n");
	if (ganhou != 0) {
		if (player == 0)
			printf("      Eh essa deu velha :(\n");
		else
			printf("      O Player %d ganhou essa!\n\n", player);
	}
	else
		printf("      Vez do Player %d!\n\n", player);


	int lin = 3;
	for (int linha = 0; linha < LINHA; linha++) {
		printf("         ");
		printf("%d", lin);
		for (int coluna = 0; coluna < COLUNA; coluna++) {
			if (coluna < COLUNA - 1) {
				printf(" %c |", jogo[linha][coluna]);
			}
			else {
				printf(" %c ", jogo[linha][coluna]);
			}

		}
		printf("\n");
		if (linha < LINHA - 1)
			printf("           ---------\n");
		lin--;
	}
	printf("%20s\n", "A   B   C");
}


void limpaTela() {

	DWORD n;  						/* Número de caracteres escritos */
	DWORD size;						/* número de caracteres visíveis */
	COORD coord = { 0, 0 };			/* Posição superior esquerda da tela */
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	/* Obter um identificador para o console */
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(h, &csbi);

	/* Encontre o número de caracteres a serem sobrescritos */
	size = csbi.dwSize.X * csbi.dwSize.Y;

	/* Sobrescrever o buffer de tela com espaços em branco */
	FillConsoleOutputCharacter(h, TEXT(' '), size, coord, &n);
	GetConsoleScreenBufferInfo(h, &csbi);
	FillConsoleOutputAttribute(h, csbi.wAttributes, size, coord, &n);

	/* Redefine o cursor para a posição superior esquerda */
	SetConsoleCursorPosition(h, coord);
}