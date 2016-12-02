/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:16:40 by gvandeve          #+#    #+#             */
/*   Updated: 2016/12/02 20:37:01 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_bool	ft_backtrack(t_piece *piece, char **map)
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
	else
		return (FALSE);
}

void		ft_bruteforce(t_piece *lst_piece)
{
	char	**map;
	int		size;
	t_piece	*tmp_piece;

	map = NULL;
	size = 2;
	map = ft_init_map(map, size);
	tmp_piece = lst_piece;
	while (ft_backtrack(tmp_piece, map) == FALSE)
	{
		tmp_piece = lst_piece;
		while (tmp_piece != NULL)
		{
			ft_reset_piece(&tmp_piece);
			tmp_piece = tmp_piece->next;
		}
		tmp_piece = lst_piece;
		size++;
		map = ft_init_map(map, size);
	}
	ft_print_map(map);
}

int				main(int ac, char **av)
{
	int		fd;
	int		is_read;
	char	buff[BUFF_SIZE + 1];
	t_bool	end;
	t_piece	*lst_piece;

	lst_piece = NULL;
	end = FALSE;
	if ((ac > 2 && write(1, "error\n", 6)) ||
		(ac == 1 && write(1, "error: usage: feelit [file_path]\n", 33)))
		return (1);
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
		lst_piece = ft_build_lst_piece(&lst_piece, buff);
	}
	return (ft_valid_end(end, lst_piece));
}
