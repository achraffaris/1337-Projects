#include "pipex.h"

char *ft_strjoin(char *s1, char *s2)
{
    int i;
    int j;

    i = 0;
    j = 0;
    char *tmp = malloc(sizeof(char) * get_length(s1, 0) + get_length(s2, 0) + 1);
    if (!tmp)
        free_buff(&tmp, 0, 0);
    while (s1 && s1[i])
    {
        tmp[i] = s1[i];
        i++;
    }
    while (s2 && s2[j])
        tmp[i++] = s2[j++];
    tmp[i] = '\0';
    return tmp;
}