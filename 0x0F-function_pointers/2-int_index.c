#include "function_pointers.h"
/**
 * int_index - searches for an integer
 * @array: an array
 * @size: number of elements in an array
 * @cmp: pointer to the function that will be used to compare values
 *
 * Return: the index of the first element, or -1 (no element matches)
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || size <= 0 || cmp == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}
	return (-1);
}
