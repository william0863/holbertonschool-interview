#include <stdlib.h>
#include <string.h>
#include "substring.h"

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    int len_s = strlen(s);
    int word_len;
    int total_len;
    int *indices = NULL;
    int count = 0;

    if (nb_words == 0 || s == NULL || words == NULL || n == NULL)
        return NULL;

    word_len = strlen(words[0]);
    total_len = word_len * nb_words;

    for (int i = 0; i <= len_s - total_len; i++) {
        int used[nb_words];
        memset(used, 0, sizeof(int) * nb_words);
        int j;

        for (j = 0; j < nb_words; j++) {
            int k;
            for (k = 0; k < nb_words; k++) {
                if (!used[k] && strncmp(s + i + j * word_len, words[k], word_len) == 0) {
                    used[k] = 1;
                    break;
                }
            }
            if (k == nb_words)
                break;
        }

        if (j == nb_words) {
            indices = realloc(indices, sizeof(int) * (count + 1));
            indices[count++] = i;
        }
    }

    *n = count;
    return indices;
}

