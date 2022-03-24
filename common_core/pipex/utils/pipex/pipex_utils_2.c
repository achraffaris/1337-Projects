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

void    ft_end(args *x, args *y)
{
    free_args(x);
    free_args(y);
    perror(NULL);
    exit(0);
}


void    ft_initialize(args *a, char **av, char **env, int pos)
{
    if (av[pos])
    {
        a->cmds = ft_split(av[pos], ' ');
        a->paths = get_paths(env);
        a->cmd = ft_strjoin(a->cmds[0], 0);
        a->path = get_path_or_none(a->paths, a->cmd);
    }
    perror("Command missing!");
}


int on_success(args *x, args *y, int n)
{
    if (n == -1)
        ft_end(x, y);
    else if (n == 0)
        return (1);
    return (n);
}
