#include "regex.h"

/**
 * regex_match - function that checks whether a given pattern matches a given string
 * @str: string
 * @pattern: pattern
 * Return: matched regex
 */
int regex_match(char const *str, char const *pattern)
{
    if (!pattern || !str)
        return 0;

    if (*pattern == '\0')
        return (*str == '\0');

    int first_match = (*str && (*str == *pattern || *pattern == '.'));

    // Handle '*'
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

