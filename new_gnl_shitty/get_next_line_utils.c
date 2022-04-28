#include "get_next_line.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
    {
        i++;
    }
    return (i);
}

char *ft_strndup(char *str, int n)
{
    int size;
    int final_size;
    char *ret;
    int i;

    printf("I entered here\n\n");
    if (!str)
        return (NULL);
    size = ft_strlen(str);
    printf("size is : %d\n", size);
    if (n == -1 || size <= n || (size == 1 && n == 0))
        final_size = size;
    else
        final_size = n;
    ret = malloc((final_size + 1) * sizeof(char));
    i = 0;
    while (i < final_size)
    {
        ret[i] = str[i];
        i++;
    }
    ret[i] = '\0';
    return (ret);
}

char *ft_strjoin(char *str1, char *str2)
{
    int i;
    int j;
    int size1;
    int size2;
    char *ret;

    i = 0;
    j = 0;
    size1 = ft_strlen(str1);
    size2 = ft_strlen(str2);
    if (!str1 && !str2)
        return (NULL);
    ret = malloc((size1 + size2 + 1) * sizeof(char));
    while (i < size1)
    {
        ret[i] = str1[i];
        i++;
    }
    while (j < size2)
    {
        ret[i + j] = str2[j];
        j++;
    }
    ret[i + j] = '\0';
    free(str1);
    return (ret);
}

int eol_n(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (-2);
    while (str[i])
    {
        if (str[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}

char *b_buff_to_line(char **str)
{
    char *tmp;
    char *line;
    int  eol;

    eol = eol_n(*str);
    printf("eol value: %d\n", eol);
    line = NULL;
    if (*str)
    {
        if (eol >= 0)
        {
//            printf("lalala");
            line = ft_strndup(*str, eol);
            tmp = ft_strndup((*str) + eol + 1, -1); 
            free(*str);
            *str = tmp;
        }
        if (eol == -1)
        {
          line = ft_strndup(*str, -1);
          free(*str);
          *str = NULL;
        }
    }
    if (line)
        return (line);
    else
        return (NULL);
}
