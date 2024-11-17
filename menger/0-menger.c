#include "menger.h"
#include <stdio.h>
#include <math.h>

/**
 * is_empty - Checks if the current position should be empty
 * @row: Row index
 * @col: Column index
 *
 * Return: 1 if the position should be empty, 0 otherwise
 */
int is_empty(int row, int col)
{
	while (row > 0 || col > 0)
	{
		if (row % 3 == 1 && col % 3 == 1)
			return (1);
		row /= 3;
		col /= 3;
	}
	return (0);
}

/**
 * menger - Draws a 2D Menger Sponge
 * @level: The level of the sponge
 *
 * Description: If level is less than 0, the function does nothing.
 * Otherwise, it draws a 2D representation of the Menger Sponge
 * of the given level using the '#' character.
 */
void menger(int level)
{
	int size, row, col;

	if (level < 0)
		return;

	size = pow(3, level);

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			if (is_empty(row, col))
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}
