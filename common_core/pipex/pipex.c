#include "pipex.h"

int main(int argc, char **argv)
{
	int fd[2];
    int pid1;
    char **cmd1;
    char *path;
    f = open("file.txt", O_RDWR);
    path = "/usr/bin/ls";
    pipe(fd);
    pid1 = fork();
    cmd1 = ft_split(argv[1]);
    if (pid1 == 0)
    {
        dup2(fd[1], 1);
        execve(path, cmd1, 0);
    }
    else
    {
        waitpid(pid1, 0, 0);
        printf("%s", get_next_line(fd[0]));
        printf("I have just waited for the child process\n");
    }
	return 0;
}
