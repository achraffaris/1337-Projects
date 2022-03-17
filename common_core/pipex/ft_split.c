#include "pipex.h"

int word_count(char *str, char sep)
{
    int i;
    int c;

    i = 0;
    c = 1;
    while (str[i])
    {
        if (str[i] == sep)
            c++;
        i++;
    }
    return (c);
}

char    *allocate_str(char **arr, int el, char *str, int pos, char sep)
{
    char *tmp;
    int i;

    i = 0;
    tmp = malloc(sizeof(char) * str_count(&str[pos], sep) + 1);
    if (!tmp)
        free_buff(arr, el, 1);
    while (str[pos] != sep && str[pos])
    {
        tmp[i] = str[pos];
        pos++;
        i++;
    }
    tmp[i] = '\0';
    return (tmp);
}

char **ft_split(char *str, char sep)
{
    char **arr;
    int i;
    int pos;
    int j;
    int el;

    i = 0;
    j = 0;
    pos = 0;
    el = word_count(str, sep);
    arr = malloc(sizeof(char *) * (el + 1));
    if (!arr)
        free_buff(arr, j, 1);
    while (str[i] && j < el)
    {
        if (str[i] == sep || str[i + 1] == '\0')
        {
            arr[j] = allocate_str(arr, j, str, pos, sep);
            j++;
            pos = i + 1;
        }
        i++;
    }
    arr[j] = NULL;
    return (arr);
}