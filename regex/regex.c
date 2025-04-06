#include "regex.h"

/**
 * regex_match - checks if a string matches a regex pattern
 * @str: string
 * @pattern: pattern
 * Return: matched regex
 */
int regex_match(char const *str, char const *pattern)
{
	int first_match;

	if (!pattern || !str)
		return (0);

	if (*pattern == '\0')
		return (*str == '\0' ? 1 : 0);

	first_match = (*str && (*str == *pattern || *pattern == '.'));

	if (*(pattern + 1) == '*')
	{
		return (regex_match(str, pattern + 2) ||
			(first_match && regex_match(str + 1, pattern)));
	}
	else
	{
		return (first_match && regex_match(str + 1, pattern + 1));
	}
}
