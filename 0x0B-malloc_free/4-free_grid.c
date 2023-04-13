#include <stdlib.h>
#include "holberton.h"

/**
 * free_grid - frees the memory allocated for the previously created grid
 * by alloc_grid
 * @grid: the address of the two dimensional grid
 * @height: height of the grid
 */
void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL || height == 0)
		return;

	for (i = 0; i < height; i++)
		free(grid[i]);

	free(grid);
}
