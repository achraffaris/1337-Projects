#include "pipex.h"

void    in_execution(char **av, char **env, int pos, int *fd)
{
    args *a;

    int in;
    ft_initialize(a, av, env, 2);
    in = on_success(a, 0, open(av[0], O_RDONLY));
    if (on_success(a, 0, fork()))
    {
        if (on_success(a, 0, dup2(in, 0)) && on_success(a, 0, dup2(fd[1], 1)))
            execve(a->path, a->cmds, env);
    }
    if (on_success(a, 0, wait(0)))
        free_args(a);
}

void    out_execution(args x, args y, int *fd)
{
    int out = open("outfile", O_CREAT | O_TRUNC | O_RDWR, 0677);
    if (on_success(&x, &y, out) == 0)
    {
        int pid = fork();
        if (on_success(&x, &y, pid) == 0)
        {
            // we are in the child process
            dup2(fd[0], 0);
            dup2(1, fd[1]);
            execve(y.path, y.cmds, 0);
        }     
    }
}

int main(int ac, char **av, char **env)
{
    int fd[2];

    if (on_success(0, 0, pipe(fd)))
    {
        in_execution(av, env, 2, fd);
        // mid_execution(av, env, 3, &fd);
        // out_execution(av, env, ac - 2, &fd);
    }
    printf("result:\n%s\n", get_next_line(fd[0]));
}