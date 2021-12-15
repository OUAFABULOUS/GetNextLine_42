/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:43:21 by omoudni           #+#    #+#             */
/*   Updated: 2021/12/08 22:08:30 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*b_buff[1024];
	int			r_read;

	if (fd < 0)
		return (NULL);
	*buff = '\0';
	while (get_index(b_buff[fd], '\n') == -1)
	{
		r_read = read(fd, buff, BUFFER_SIZE);
		if (r_read < 0)
			return (NULL);
		buff[r_read] = '\0';
		if (r_read > 0)
		{
			if (!b_buff[fd])
				b_buff[fd] = ft_strndup(buff, get_index(buff, '\0'));
			else
				b_buff[fd] = ft_strjoin(b_buff[fd], buff);
		}
		else
			break ;
	}
	return (b_buff_to_line(&b_buff[fd]));
}
