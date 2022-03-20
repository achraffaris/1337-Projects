# ifndef STRUCT_VARIABLES_H
# define STRUCT_VARIABLES_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct args{
    char **paths;
    char **cmds;
    char *path;
    char *cmd;
    int allowed;
} args;

typedef struct var{
    char *tmp;
    int i;
    int j;
    int len;
    int pos;
} var;

# endif