/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:16:40 by gvandeve          #+#    #+#             */
/*   Updated: 2016/12/06 15:46:32 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_bool		ft_backtrack(t_piece *piece, char **map)
{
	if (piece == NULL)
		return (FALSE);
	if (piece->next == NULL &&
		ft_drop_piece(map, piece))
		return (TRUE);
	if (ft_drop_piece(map, piece))
	{
		ft_reset_piece(&(piece->next));
		if (ft_backtrack(piece->next, map) == TRUE)
			return (TRUE);
	}
	ft_pick_piece(map, piece);
	if (ft_backtrack(ft_move_piece(piece, map), map) == TRUE)
		return (TRUE);
	return (FALSE);
}

void		ft_bruteforce(t_piece *lst_piece, int nb_piece)
{
	char	**map;
	int		size;

	map = NULL;
	size = ft_isqrt((nb_piece * 4));
	map = ft_init_map(map, size);
	while (ft_backtrack(lst_piece, map) == FALSE)
	{
		ft_reset_piece(&lst_piece);
		size++;
		map = ft_init_map(map, size);
	}
	ft_print_map(map);
}

int			main(int ac, char **av)
{
	int		fd;
	int		is_read;
        int		nb_piece;
	char	buff[BUFF_SIZE + 1];
	t_bool	end;
	t_piece	*lst_piece;

        nb_piece = 0;
	lst_piece = NULL;
	end = FALSE;
	if (ac != 2 && write(1, "usage: ./fillit [file_path]\n", 28))
		return (1);
	fd = open(av[1], O_RDONLY);
	while ((is_read = read(fd, buff, BUFF_SIZE)) != 0)
	{
          nb_piece++;
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
	return (ft_valid_end(end, lst_piece, nb_piece));
}
