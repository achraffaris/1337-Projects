#include "pipex.h"

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

void    ft_initialize(args *a, char **av, char **env, int index)
{
    if (av[index])
    {
        a->cmds = ft_split(av[index], ' ');
        a->paths = get_paths(env);
        a->cmd = ft_strjoin(av[index], 0);
        a->path = get_path_or_none(a->paths, a->cmd);
        if (a->path)
            a->is_valid = 1;
        else
            a->is_valid = 0;
    }
    else
        a->is_valid = 0;
}

void    ft_start(args *x, args *y)
{
    printf("ready!\n");
}

void    ft_end(args *x, args *y)
{
    free_args(x);
    free_args(y);
}

int main(int ac, char **av, char **env)
{
    args x;
    args y;

    ft_initialize(&x, av, env, 2);
    ft_initialize(&y, av, env, 3);
    
    if (x.is_valid)
        ft_start(&x, &y);
    if (y.is_valid)
        ft_start(&x, &y);
}