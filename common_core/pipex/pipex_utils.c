#include "pipex.h"

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