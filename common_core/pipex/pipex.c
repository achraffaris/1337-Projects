#include "pipex.h"


char *get_path_or_none(char *cmd)
{
    char *fcmd[3];
    char *path;
    int pid;
    int fd[2];


    fcmd[0] = "usr/bin/whereis";
    fcmd[1] = cmd;
    fcmd[2] = 0;
    pid = fork();
    if (pid == 0)
    {
        dup2(fd[1], 1);
        execve("usr/bin/whereis", fcmd, 0);
    }
    path = get_next_line(fd[0]);
    return (path);
}
/*
int main(int argc, char **argv)
{
	int fd[2];
    int pid1;
    int cpid;
    char **cmd1;
    char *path;

    pipe(fd);
    pid1 = fork();
    cmd1 = ft_split(argv[1], ' ');
    printf("Command found = '%s'\n", cmd1[0]);
    if (pid1 == 0)
    {
        path = get_path_or_none(cmd1[0]);
        printf("path found = '%s'\n", path);
        dup2(fd[1], 1);
        execve(path, cmd1, 0);
    }
	return 0;
}*/
