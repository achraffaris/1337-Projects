#include "pipex.h"

int command_exists(char *path, char *cmd)
{
    char    *cmd_path;

    cmd_path = ft_strjoin(path, cmd);
    if (access(cmd_path, X_OK) == 0)
        return (1);       
    return (0);
}

char    *ft_execute(char *cmd, char **env)
{
    char **paths;
    char **cmds;
    int pid;
    int fd[2];
    int i;

    i = 0;
    paths = get_paths(env);
    cmds = ft_split(cmd, ' ');
    pipe(fd);
    pid = fork();
    if (pid == 0)
    {
        while (paths[i])
        {
            if (command_exists(paths[i], ft_strjoin("/", cmds[0])))
            {
                dup2(fd[1], 1);
                execve(get_absolute_path(paths[i], cmds[0]), cmds, 0);
                exit(0);
            }
            i++;
        }
    }
    waitpid(pid, 0, 0);
    return (get_next_line(fd[0]));
}

int main(int argc, char **argv, char **env)
{
    int i;
    i = 0;
    
    printf("return = %s\n", ft_execute(argv[1], env));
    return 0;
}
