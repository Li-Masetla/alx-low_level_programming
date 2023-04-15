#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**
 * _is_zero - determines if any number is zero
 * @argv: argument vector.
 *
 * Return: no return.
 */
void _is_zero(char *argv[])
{
	int j, isn1 = 1, isn2 = 1;

	for (j = 0; argv[1][j]; j++)
		if (argv[1][j] != '0')
		{
			isn1 = 0;
			break;
		}

	for (j = 0; argv[2][j]; j++)
		if (argv[2][j] != '0')
		{
			isn2 = 0;
			break;
		}

	if (isn1 == 1 || isn2 == 1)
	{
		printf("0\n");
		exit(0);
	}
}

/**
 * _initialize_array - set memery to zero in a new array
 * @ar: char array.
 * @lar: length of the char array.
 *
 * Return: pointer of a char array.
 */
char *_initialize_array(char *ar, int lar)
{
	int j = 0;

	for (j = 0; j < lar; j++)
		ar[j] = '0';
	ar[lar] = '\0';
	return (ar);
}

/**
 * _checknum - determines length of the number
 * and checks if number is in base 10.
 * @argv: arguments vector.
 * @n: row of the array.
 *
 * Return: length of the number.
 */
int _checknum(char *argv[], int n)
{
	int sn;

	for (sn = 0; argv[n][sn]; sn++)
		if (!isdigit(argv[n][sn]))
		{
			printf("Error\n");
			exit(98);
		}

	return (sn);
}

/**
 * main - Entry point.
 * program that multiplies two positive numbers.
 * @argc: number of arguments.
 * @argv: arguments vector.
 *
 * Return: 0 - success.
 */
int main(int argc, char *argv[])
{
	int ln1, ln2, lnout, add, addl, i, j, k, ca;
	char *sout;

	if (argc != 3)
		printf("Error\n"), exit(98);
	ln1 = _checknum(argv, 1), ln2 = _checknum(argv, 2);
	_is_zero(argv), lnout = ln1 + ln2, sout = malloc(lnout + 1);
	if (sout == NULL)
		printf("Error\n"), exit(98);
	sout = _initialize_array(sout, lnout);
	k = lnout - 1, i = ln1 - 1, j = ln2 - 1, ca = addl = 0;
	for (; k >= 0; k--, i--)
	{
		if (i < 0)
		{
			if (addl > 0)
			{
				add = (sout[k] - '0') + addl;
				if (add > 9)
					sout[k - 1] = (add / 10) + '0';
				sout[k] = (add % 10) + '0';
			}
			i = ln1 - 1, j--, addl = 0, ca++, k = lnout - (1 + ca);
		}
		if (j < 0)
		{
			if (sout[0] != '0')
				break;
			lnout--;
			free(sout), sout = malloc(lnout + 1), sout = _initialize_array(sout, lnout);
			k = lnout - 1, i = ln1 - 1, j = ln2 - 1, ca = addl = 0;
		}
		if (j >= 0)
		{
			add = ((argv[1][i] - '0') * (argv[2][j] - '0')) + (sout[k] - '0') + addl;
			addl = add / 10, sout[k] = (add % 10) + '0';
		}
	}
	printf("%s\n", sout);
	return (0);
}
