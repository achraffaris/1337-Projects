#include "pipex.h"
/*
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
}


void    ft_initialize(args *a, char **av, char **env, int index)
{
    if (av[index])
    {
        a->cmds = ft_split(av[index], ' ');
        a->paths = get_paths(env);
        a->cmd = ft_strjoin(a->cmds[0], 0);
        a->path = get_path_or_none(a->paths, a->cmd);
        if (a->path)
            a->is_valid = 1;
        else
            a->is_valid = 0;
    }
    else
        a->is_valid = 0;
}


int on_success(args *x, args *y, int n)
{
    if (n == -1)
        ft_end(x, y);
    return (1);
}


int    child_on_success(args *x, args *y, int n)
{
    if (n == -1)
        ft_end(x, y);
    else if (n == 0)
        return (1);
    return (0);
    
}


void    ft_start(args *x, args *y)
{
    int pid1;
    int pid2;
    int in;

    int out;

    in = open("input", O_RDWR);
    out = open("output", O_RDWR);
    int fd[2];
    
    if (on_success(x, y, pipe(fd) && on_success(x, y, in) && on_success(x, y, out)));
    {
        
        pid1 = fork();
        if (child_on_success(x, y, pid1))
            pid2 = fork();
            if (child_on_success(x, y, pid2))
                dup2(in, 0);
                if (on_success(x, y, dup2(1, fd[1])))
                    if (on_success(x, y, execve(x->path, x->cmds, 0)))
            if (on_success(x, y, dup2(0, fd[0])))
                if (on_success(x, y, execve(y->path, y->cmds, 0)))
                    exit(0);
    }
}

int main(int ac, char **av, char **env)
{
    args x;
    args y;

    ft_initialize(&x, av, env, 2);
    ft_initialize(&y, av, env, 3);
    
    if (x.is_valid && y.is_valid)
        ft_start(&x, &y);
    else
        ft_end(&x, &y);
}*/