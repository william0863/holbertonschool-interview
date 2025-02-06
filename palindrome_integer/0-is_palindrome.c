#include "palindrome.h"

/**
 * is_palindrome - Checks if a number is a palindrome
 * @n: The number to check
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
    unsigned long reversed = 0, temp = n;

    while (temp != 0)
    {
        reversed = reversed * 10 + (temp % 10);
        temp /= 10;
    }

    return (n == reversed);
}

