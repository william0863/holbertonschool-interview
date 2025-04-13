#ifndef SUBSTRING_H
#define SUBSTRING_H

int *find_substring(char const *s, char const **words, int nb_words, int *n);
int process_substring(char const *s, char const **words, int nb_words, int i, int word_len);

#endif
