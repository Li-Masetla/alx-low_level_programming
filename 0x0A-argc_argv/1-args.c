#include <stdio.h>
#include "main.h"

/**
 * main - prints the number of arguments passed into the program
 * program prints a number, followed by a new line
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
(void) argv; /*Ignore argv*/
	printf("%d\n", argc - 1);

	return (0);
}
