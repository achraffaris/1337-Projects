#include "pipex.h"

char    *allocate_str(char **arr, int el, char *str, int pos)
{
    char *tmp;
    int i;

    i = 0;
    tmp = malloc(sizeof(char) * str_count(&str[pos], ' ') + 1);
    if (!tmp)
        free_buff(arr, el, 1);
    while (str[pos] != ' ' && str[pos])
    {
        tmp[i] = str[pos];
        pos++;
        i++;
    }
    tmp[i] = '\0';
    return (tmp);
}

char **ft_split(char *str)
{
    char **arr;
    int i;
    int pos;
    int j;

    i = 0;
    j = 0;
    pos = 0;
    arr = malloc(sizeof(char *) * 3);
    if (!arr)
        free_buff(arr, j, 1);
    while (str[i] && j < 3)
    {
        if (str[i] == ' ' || str[i + 1] == '\0')
        {
            arr[j] = allocate_str(arr, j, str, pos);
            j++;
            pos = i + 1;
        }
        i++;
    }
    arr[j] = NULL;
    return (arr);
}