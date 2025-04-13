#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * find_substring - finds all possible substrings in a string
 * @s: string
 * @words: Array of words
 * @nb_words: Number of words in array
 * @n: Pointer to store the number of matches found
 *
 * Return: array of indices
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int len_s = strlen(s);
	int word_len;
	int total_len;
	int *indices = NULL;
	int count = 0;
	int i;

	if (nb_words == 0 || s == NULL || words == NULL || n == NULL)
	{
		return (NULL);
	}

	word_len = strlen(words[0]);
	total_len = word_len * nb_words;

	for (i = 0; i <= len_s - total_len; i++)
	{
		int result = process_substring(s, words, nb_words, i, word_len);

		if (result != -1)
		{
			indices = realloc(indices, sizeof(int) * (count + 1));
			if (indices == NULL)
			{
				return (NULL);
			}
			indices[count++] = i;
		}
	}

	*n = count;
	return (indices);
}

/**
 * process_substring - Checks if substring concatenate words
 * @s: string
 * @words: Array of words 
 * @nb_words: Number of words
 * @i: index
 * @word_len: Length of each word
 *
 * Return: Pointer to result if match is found
 */
int process_substring(char const *s, char const **words, int nb_words, int i, int word_len)
{
	int used[nb_words];
	int j, k;

	memset(used, 0, sizeof(int) * nb_words);

	for (j = 0; j < nb_words; j++)
	{
		for (k = 0; k < nb_words; k++)
		{
			if (!used[k] && strncmp(s + i + j * word_len, words[k], word_len) == 0)
			{
				used[k] = 1;
				break;
			}
		}
		if (k == nb_words)
		{
			return (-1);
		}
	}

	return (i);
}
