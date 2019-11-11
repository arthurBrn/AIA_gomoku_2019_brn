/*
** EPITECH PROJECT, 2019
** my_str_to_word_array.c
** File description:
** ..
*/

#include <stdlib.h>
#include <stdio.h>

void    my_free_tab(char **tab)
{
    int   y = 0;

    while (tab[y] != NULL)
        free(tab[y++]);
    free(tab);
}

int	my_delim(char s, char *lim)
{
    int	i = 0;
    
    while (lim[i]) {
        if (s == lim[i])
            return (0);
        i++;
    }
    return (1);
}

int	count_word(char *str, char *lim)
{
    int	i = 0;
    int	y = 0;
    
    while (str[i]) {
        while (my_delim(str[i], lim) == 0)
            i++;
        y++;
        if (str[i] != '\0')
            while (my_delim(str[i], lim) == 1 && str[i] != '\0')
                i++;
    }
    return (y);
}

int	wordlen(char *str, char *lim, int i)
{
    int	len = 0;
    
    while (my_delim(str[i], lim) != 0 && str[i]) {
        len++;
        i++;
    }
    return (len);
}

char    **my_str_to_word_array(char *str, char *lim)
{
    int	i = 0;
    int	y = 0;
    int	x;
    char	**tab;
    int	word_nb = count_word(str, lim);
    
    tab = malloc(sizeof(char *) * (word_nb + 1));
    for (y = 0; y != word_nb; y++) {
        if (my_delim(str[i], lim) == 1) {
            x = 0;
            tab[y] = malloc(sizeof(char) *
                            (wordlen(str, lim, i) + 1));
            while (my_delim(str[i], lim) == 1 && str[i])
                tab[y][x++] = str[i++];
            tab[y][x] = '\0';
        }
        (str[i] != '\0') ? i++ : 0;
    }
    tab[y] = '\0';
    return (tab);
}
