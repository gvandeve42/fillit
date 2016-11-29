/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:16:40 by gvandeve          #+#    #+#             */
/*   Updated: 2016/11/23 16:21:52 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int		fd;
	int		is_read;
	char	buff[BUFF_SIZE + 1];
	t_bool	end;

	end = FALSE;
	if (ac > 2)
		return (0);
	else if (ac == 1)
		fd = 0;
	else
		fd = open(av[1], O_RDONLY);
	while ((is_read = read(fd, buff, BUFF_SIZE)) != 0)
	{
		if (is_read == BUFF_SIZE - 1)
			end = TRUE;
		buff[is_read] = '\0';
		if (ft_is_valid_test(buff, is_read) == FALSE)
		{
			write(1, "error\n", 6);
			return (1);
		}
	}
	return (ft_valid_end(end));
}
