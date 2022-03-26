#include "pipex.h"

void    set_args(t_args *a, char **av, char **env)
{
    a->av = av;
    a->env = env;
    a->env_paths = get_paths(env);
}

void    set_cmdinfo(t_cmdinfo *ci, t_args a, int pos)
{
    ci->cmds = ft_split(a.av[pos], ' ');
    ci->cmd = ft_strjoin(ci->cmds[0], "");
    ci->path = get_path_or_none(a.env_paths, ci->cmd);
}

int on_success(int id)
{
    if (id == -1)
    {
        perror(0);
        exit(0);
    }
    return (id);
}

void    in_execution(int *fd, t_args a, int pos)
{
    t_cmdinfo ci;
    set_cmdinfo(&ci, a, pos);
    int pid;
    int infile;

    infile = open(a.av[1], O_RDONLY);
    if (on_success(infile) == 0)
    {
        pid = fork();
        if (on_success(pid) == 0)
        {
            dup2(infile, 0);
            dup2(fd[1], 1);
            close(fd[0]);
            execve(ci.path, ci.cmds, a.env);
        }
        close(fd[0]);
        close(fd[1]);
    }
}

void    out_execution(int *fd, t_args a, int pos)
{
    t_cmdinfo ci;
    int pid;
    int out;
    
    set_cmdinfo(&ci, a, pos);

    out = open(a.av[pos + 1], O_CREAT, O_RDWR, O_TRUNC, 0644);
    if (on_success(out) == 0)
    {
        pid = fork();
        if (on_success(pid) == 0)
        {
            dup2(out, fd[1]);
            dup2(out, 1);
            dup2(fd[0], 0);
            execve(ci.path, ci.cmds, a.env);
        }
        close(fd[0]);
        close(fd[1]);
    }
}

int main(int ac, char **av, char **env)
{
    t_args args;
    set_args(&args, av, env);

    int fd[2];
    int i;
    int fc;
    int lc;

    fc = 2;
    lc = ac - 2;

    i = fc;
    pipe(fd);
    while (i <= lc)
    {
        if (i == fc)
        {
            in_execution(fd, args, i);
  
        }
            
        else if (i == lc)
        {
            printf("before in_execution\n");
            out_execution(fd, args, i);
            printf("after in_execution\n");
        }
        printf("%d\n", i);
        i++;
    }
}