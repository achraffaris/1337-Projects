#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <sys/wait.h>
# include "get_next_line.h"

int     str_count(char *str, char c);
void    free_buff(char **buff, int el, int multi_mode);
char    **ft_split(char *str, char sep);
char    *ft_strjoin(char *s1, char *s2);

#endif