#include "utils.h"

char    *get_absolute_path(char *path, char *cmd)
{
    char *tmp;

    tmp = ft_strjoin(path, "/");
    return (ft_strjoin(tmp, cmd));
}

char    **get_paths(char **env)
{
    int i;

    i = 0;
    while (env[i])
    {
        if (start_with("PATH=", env[i]))
            return (ft_split(&env[i][5], ':'));
        i++;
    }
    return 0;
}
