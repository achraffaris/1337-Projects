#include "../utils.h"

char    *get_path_or_none(char **paths, char *cmd)
{
    var v;

    v.i = 0;
    if (!cmd)
        return (NULL);
    v.tmp = ft_strjoin("/", cmd);
    while(paths[v.i])
    {
        if (command_exists(paths[v.i], v.tmp))
            return (ft_strjoin(paths[v.i], v.tmp));
        v.i++;
    }
    return (NULL);
}


