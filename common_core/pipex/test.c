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



void    in_execution(args *x)
{

}

void    out_execution(args *y)
{

}

void    raise_error()
{
    perror(NULL);
}

void    ft_start(args *x, args *y)
{
    int pid1;
    int pid2;
    int fd[2];

    int f = open("input", O_RDWR);

    pipe(fd);
    pid1 = fork();
    if (pid1 == 0)
    {
        pid2 = fork();
        if (pid2 == 0)
        {
            dup2(1, fd[1]);
            execve(y->path, y->cmds, 0);
        }
        waitpid(pid2, 0, 0);
        dup2(fd[0], 0);
        execve(x->path, x->cmds, 0);
    }
    waitpid(pid1, 0, 0);
}

void    ft_end(args *x, args *y)
{
    free_args(x);
    free_args(y);
    raise_error();
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
}