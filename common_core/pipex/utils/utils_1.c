#include "utils.h"

int str_count(char *str, char c)
{
    int i;
    
    i = 0;
    while(str[i] != c && str[i])
        i++;
    return (i);
}

void    free_buff(char **buff, int el, int multi_mode)
{
    int i;

    i = 0;
    while (multi_mode && i <= el)
    {
        free(buff[i]);
        buff[i] = 0;
        i++;
    }
    free(buff);
    buff = NULL;
}

int	get_length(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str && str[i] != c && str[i])
		i++;
	return (i);
}

int start_with(char *str, char *ptr)
{
    int i;
    int str_len;

    str_len = get_length(str, '\0');
    i = 0;
    while (ptr[i] == str[i])
    {
        i++;
    }
    if (i == str_len)
        return (1);
    return (0);
}

char    *ft_strjoin(char *s1, char *s2)
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