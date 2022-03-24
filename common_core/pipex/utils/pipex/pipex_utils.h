#ifndef PIPEX_UTILS_H
#define PIPEX_UTILS_H

#include "../utils.h"

char    **get_paths(char **env);
int     command_exists(char *path, char *cmd);
char    *get_path_or_none(char **paths, char *cmd);
void    ft_end(args *x, args *y);
void    ft_initialize(args *a, char **av, char **env, int pos);
int     on_success(args *x, args *y, int n);
int    child_on_success(args *x, args *y, int n);

#endif