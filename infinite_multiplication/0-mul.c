#include "holberton.h"
#include <stdlib.h>

/**
 * is_digit - Checks if a string contains only digits
 * @s: string
 *
 * Return: 1 if all digits, or 0 if not
 */
int is_digit(char *s)
{
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

/**
 * _strlen - Returns the length of a string
 * @s: string
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s++)
		len++;
	return (len);
}

/**
 * print_result - Prints the result of multiplication
 * @result: array of integers representing the result
 * @size: size of array
 */
void print_result(int *result, int size)
{
	int i = 0;

	while (i < size && result[i] == 0)
		i++;
	if (i == size)
		_putchar('0');
	while (i < size)
		_putchar(result[i++] + '0');
	_putchar('\n');
}

/**
 * main - Multiplies two positive numbers
 * @argc: argument count
 * @argv: array of argument
 *
 * Return: 0 if success, 98 if failure
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int len1, len2, i, j, carry, n1, n2, *result;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		exit(98);
	}

	num1 = argv[1];
	num2 = argv[2];
	len1 = _strlen(num1);
	len2 = _strlen(num2);

	result = malloc(sizeof(int) * (len1 + len2));
	if (!result)
		exit(98);

	for (i = 0; i < len1 + len2; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = num1[i] - '0';
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			carry += result[i + j + 1] + n1 * n2;
			result[i + j + 1] = carry % 10;
			carry /= 10;
		}
		result[i + j + 1] += carry;
	}

	print_result(result, len1 + len2);
	free(result);
	return (0);
}
