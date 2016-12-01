/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:16:40 by gvandeve          #+#    #+#             */
/*   Updated: 2016/12/01 04:00:06 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static t_bool	ft_backtrack(t_piece *piece, char **map)
{
	if (ft_drop_piece(map, piece))
		if (piece->next == NULL || ft_backtrack(piece->next, map))
			return (TRUE);
	ft_pick_piece(map, piece);
	if (ft_move_piece(piece, map) != NULL)
		if (ft_backtrack(piece, map))
			return (TRUE);
	return (FALSE);
}

static void		ft_bruteforce(t_piece *lst_piece)
{
	char	**map;
	int		size;

	map = NULL;
	size = 6;
	map = ft_init_map(map, size);
	while (ft_backtrack(lst_piece, map) == FALSE)
		map = ft_init_map(map, ++size);
	ft_print_map(map);
}

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
	ft_bruteforce(lst_piece);
	return (ft_valid_end(end));
}
