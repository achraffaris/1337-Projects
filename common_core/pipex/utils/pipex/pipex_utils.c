#include "pipex_utils.h"

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

int command_exists(char *path, char *cmd)
{
    char    *cmd_path;

    cmd_path = ft_strjoin(path, cmd);
    if (access(cmd_path, X_OK) == 0)
    {
        return (1); 
    }
    return (0);
}
