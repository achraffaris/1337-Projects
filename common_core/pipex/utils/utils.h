#ifndef UTILS_H
# define UTILS_H
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <sys/wait.h>
# include "gnl/get_next_line.h"

int     get_length(char *str, char c);
int     start_with(char *str, char *ptr);
char    *ft_strjoin(char *s1, char *s2);
char    *get_absolute_path(char *path, char *cmd);
char    **get_paths(char **env);
char    **ft_split(char *str, char sep);
void    free_buff(char **buff, int el, int multi_mode);
int     str_count(char *str, char c);
int     word_count(char *str, char sep);


#endif