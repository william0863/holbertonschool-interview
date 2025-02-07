#include "slide_line.h"

/**
 * slide_line - Slide line
 * @line: Pointer
 * @size: size of array
 * @direction: Direction to slide
 *
 * Return: 1 on success, 0 on failure
 */

int slide_line(int *line, size_t size, int direction)
{
    size_t i;
    int temp[size], index = 0;

    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return (0);

    for (i = 0; i < size; i++)
        temp[i] = 0;

    if (direction == SLIDE_LEFT)
    {
        for (i = 0; i < size; i++)
            if (line[i] != 0)
                temp[index++] = line[i];

        for (i = 0; i < size - 1; i++)
        {
            if (temp[i] != 0 && temp[i] == temp[i + 1])
            {
                temp[i] *= 2;
                temp[i + 1] = 0;
            }
        }

        index = 0;
        for (i = 0; i < size; i++)
            if (temp[i] != 0)
                line[index++] = temp[i];
        while ((size_t)index < size)
            line[index++] = 0;
    }
    else
    {
        index = size - 1;
        for (i = size; i > 0; i--)
            if (line[i - 1] != 0)
                temp[index--] = line[i - 1];

        for (i = size - 1; i > 0; i--)
        {
            if (temp[i] != 0 && temp[i] == temp[i - 1])
            {
                temp[i] *= 2;
                temp[i - 1] = 0;
            }
        }

        index = size - 1;
        for (i = size; i > 0; i--)
            if (temp[i - 1] != 0)
                line[index--] = temp[i - 1];
        while ((size_t)index < size - 1)
            line[index--] = 0;
    }
    return (1);
}

