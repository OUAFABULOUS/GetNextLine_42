/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:14:51 by omoudni           #+#    #+#             */
/*   Updated: 2022/04/28 23:55:37 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char *get_next_line(int fd)
{
    char buff[BUFFER_SIZE];
    int r_read;
    static char *b_buff;

//    printf("I entered here\n");
    if (fd < 0)
    {
//      printf("Error\n");
        return (NULL);
    }
    *buff = '\0';
//    printf("Entered here\n");
    while (eol_n(b_buff) < -1)
    {
    printf("Entered here\n");
        r_read = read(fd, buff, BUFFER_SIZE - 1);
        printf("buff est: %s\n", buff);
        buff[r_read] = '\0';
        printf("This is r_read: %d\n", r_read);
        printf("buff est: %s\n", buff);
        if (r_read < 0)
        {
            return (NULL);
        }
        if (r_read > 0)
        {
            if (!b_buff)
            {
//                printf("entered here!\n");
                b_buff = ft_strndup(&buff[0], -1);
//                printf("lalaalalala\n");
//                printf("%s\b", b_buff);
            }
            else
                b_buff = ft_strjoin(b_buff, buff);
        }
        else
            break;
    }
    return (b_buff_to_line(&b_buff));
}
/**
int main(int argc, char const *argv[])
{
    int fd;
    char    *line;

    fd = open(argv[1], O_RDONLY);
//    printf("The fd is: %d\n", fd);
    if (fd < 0)
        exit (1);
    line = get_next_line(fd);
    if (!line)
        printf("NULL babe\n");
    while (line)
    {
//        printf("\n\n\n***iiiii***\n\n\n");
        printf("%s\n", line);
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    return 0;
}
**/