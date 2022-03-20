#ifndef PIPEX_UTILS_H
#define PIPEX_UTILS_H

#include "../utils.h"

char    **get_paths(char **env);
int     command_exists(char *path, char *cmd);

#endif