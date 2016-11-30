/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:16:40 by gvandeve          #+#    #+#             */
/*   Updated: 2016/11/30 17:22:25 by gvandeve         ###   ########.fr       */
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
	t_piece	*lst_piece;

	lst_piece = NULL;
	end = FALSE;
	if (ac > 2)
		return (0);
	fd = (ac == 1) ? 0 : open(av[1], O_RDONLY);
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
		lst_piece = ft_build_lst_piece(&lst_piece, buff);
	}
	if (lst_piece != NULL)
		while (lst_piece != NULL)
		{
			printf("Piece trouvee\n");
			printf("Coor || i[0] = %d || j[0] = %d ||\n", lst_piece->i[0], lst_piece->j[0]);
			printf("Coor || i[1] = %d || j[1] = %d ||\n", lst_piece->i[1], lst_piece->j[1]);
			printf("Coor || i[2] = %d || j[2] = %d ||\n", lst_piece->i[2], lst_piece->j[2]);
			printf("Coor || i[3] = %d || j[3] = %d ||\n", lst_piece->i[3], lst_piece->j[3]);
			printf("Char || elem->symb = %c ||\n\n", lst_piece->symbol);
			lst_piece = lst_piece->next;
		}
	//ft_work_on_piece(&lst_piece, end)*/
	return (ft_valid_end(end));
}
