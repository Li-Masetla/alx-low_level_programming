#include "main.h"
#include <stdlib.h>
/**
 * array_range - creates an array of integers.
 * @min: minimum value.
 * @max: maximum value.
 *
 * Return: pointer to the newly created array.
 * if min > max, function returns a null
 * if malloc fails, function returns a null
 */
int *array_range(int min, int max)
{
	int *sr;
	int i;

	if (min > max)
		return (NULL);

	sr = malloc(sizeof(*sr) * ((max - min) + 1));

	if (sr == NULL)
		return (NULL);

	for (i = 0; min <= max; i++, min++)
		sr[i] = min;

	return (sr);
}
