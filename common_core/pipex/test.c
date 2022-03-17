#include "pipex.h"

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

int main(int argc, char **argv, char **env)
{
    char **paths;
    int i;

    i = 0;
    while (env[i])
    {
        if (start_with("PATH=", env[i]))
            paths = ft_split(&env[i][5], ':');
        i++;
    }
    i = 0;
    while (paths[i])
    {
         printf("path[%d] = %s\n", i, paths[i]);
         i++;
    }
    return 0;
}
