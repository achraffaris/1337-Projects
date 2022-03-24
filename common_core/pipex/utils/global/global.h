# ifndef STRUCT_VARIABLES_H
# define STRUCT_VARIABLES_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct args{
    char *file;
    char **paths;
    char **cmds;
    char *path;
    char *cmd;
    int is_valid;
} args;

typedef struct var{
    char *tmp;
    int i;
    int j;
    int len;
    int pos;
} var;

# endif