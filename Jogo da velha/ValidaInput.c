#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "ValidaInput.h"

int isLetra(char c)//verifica se a entrada e uma letra a, b ou c
{

	if (c == 'a' || c == 'b' || c == 'c' || c == 'A' || c == 'B' || c == 'C')
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

int isNumero(char c)//verifica se a entrada e um numero 1, 2 ou 3
{

	if (c == '1' || c == '2' || c == '3')
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

void digito()
{
	memset(cordenadaDigitada, '\0', 3);

	char c;
	int i = 0;
	int numero = 0;
	int aceitos = 3;

	do
	{
		c = _getch();

		if (isLetra(c) != 0 && i < 1)
		{
			cordenadaDigitada[i] = c;
			i++;
			printf("%c", c);
		}
		else if (isNumero(c) != 0 && i == 1)
		{
			cordenadaDigitada[i] = c;
			i++;
			printf("%c", c);
		}
		else if (c == 8 && i)
		{
			cordenadaDigitada[i] = '\0';
			i--;
			printf("\b \b");
		}

	} while (c != 13);

	cordenadaDigitada[i] = '\0';


}

int posY()
{
	int y = 0;
	switch (cordenadaDigitada[0])
	{
	case 'A':
	case 'a':
		y = 0;
		break;
	case 'B':
	case 'b':
		y = 1;
		break;
	case 'C':
	case 'c':
		y = 2;
		break;
	}

	return y;

}

int posX()
{
	int x = 0;
	switch (cordenadaDigitada[1])
	{
	case '3':
		x = 0;
		break;
	case '2':
		x = 1;
		break;
	case '1':
		x = 2;
		break;
	}

	return x;

}