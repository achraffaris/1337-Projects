#include "pipex.h"

char    *get_path_or_none(char **paths, char *cmd)
{
    var v;

    v.i = 0;
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
    if (av[1])
    {
        a->cmds = ft_split(av[index], ' ');
        a->paths = get_paths(env);
        a->cmd = ft_strjoin(av[index], 0);
        a->path = get_path_or_none(a->paths, a->cmd);
        if (a->path)
            a->allowed = 1;
        else
            a->allowed = 0;
    }
    else
        a->allowed = 0;
}

void    ft_start(args *x, args *y, char **av, char **env)
{
    ft_initialize(x, av, env, 2);
    ft_initialize(y, av, env, 3);
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
    ft_start(&x, &y, av, env);
    printf("cmd = %d\n", x.allowed);
    ft_end(&x, &y);
    printf("cmd = %s\n", x.path);
}