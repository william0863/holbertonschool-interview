#include "holberton.h"

/**
 * wildcmp - Compares two strings allowing for wildcard * in s2
 * @s1: The first string
 * @s2: The second string, which may contain '*'
 *
 * Return: 1 if the strings are identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		if (!*s1)
			return (wildcmp(s1, s2 + 1));
		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
	}
	if (*s1 == *s2)
	{
		if (!*s1)
			return (1);
		return (wildcmp(s1 + 1, s2 + 1));
	}
	return (0);
}
