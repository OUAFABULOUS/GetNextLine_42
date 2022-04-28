#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
char *get_next_line(int fd);
int ft_strlen(char *str);
char *ft_strndup(char *str, int n);
char *ft_strjoin(char *str1, char *str2);
int eol_n(char *str);
char *b_buff_to_line(char **str);
#endif