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

void    cmd_execution(t_args a, var *v, int ac)
{
    t_cmdinfo ci;

    set_cmdinfo(&ci, a, v->pos);
    if (v->pos - 1 == 1){
        dup2(on_success(open(a.av[1], O_RDONLY)), 0);
        dup2(v->fd[1], 1);
        close(v->fd[0]);
    }
    else if (v->pos + 1 == ac - 1)
    {
        dup2(v->fd[0], 0);
        close(v->fd[1]);
        dup2(on_success(open(a.av[ac - 1], O_CREAT | O_TRUNC | O_RDWR, 0777)), 1);
    }
    else
    {
        dup2(v->fd[1], 1);
        dup2(v->fd[0], 0);
    }
    execve(ci.path, ci.cmds, a.env);
}

int main(int ac, char **av, char **env)
{
    t_args  args;
    var     v;
    int     fd[2];

    set_args(&args, av, env);
    v.pos = 2;
    pipe(v.fd);
    while (v.pos < ac)
    {
        if (fork() == 0)
            cmd_execution(args, &v, ac);
        v.pos++;
    }
    wait(0);
}