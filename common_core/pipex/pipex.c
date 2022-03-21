#include "pipex.h"
/*
char    *get_path_or_none(char **paths, char *cmd)
{
    var v;

    v.i = 0;
    v.tmp = ft_strjoin("/", cmd);
    while(paths[v.i])
    {
        if (command_exists(paths[v.i], v.tmp))
        {
            printf("Command Found!\n");
            return (paths[v.i]);
        }
        v.i++;
    }
    return (NULL);
}

void    ft_init(args *a, char **argv, char **env)
{
    // get & split paths from env variables
    a->paths = get_paths(env);
    // get & cmd from its flags 
    a->cmds = ft_split(argv[1], ' ');
    // get cmd with no flags
    a->cmd = ft_strjoin(a->cmds[0], 0);
    // get the path of the cmd or NULL
    a->cmd_path = get_absolute_path_or_none(a->paths, a->cmd);
}

int main(int argc, char **argv, char **env)
{
    args a;
    var v;
    ft_init(&a, argv, env);
    
    v.i = 0;
    printf("path = ∏∏%s\n", a.cmd_path);
    return (0);
}*/