/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 22:51:39 by omoudni           #+#    #+#             */
/*   Updated: 2021/12/08 12:56:00 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

int		get_index(char *str, char c);
char	*ft_strndup(char *str, int len);
char	*ft_strjoin(char *str1, char *str2);
char	*b_buff_to_line(char **b_buff);
char	*get_next_line(int fd);

#endif
