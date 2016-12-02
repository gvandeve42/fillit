/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:16:40 by gvandeve          #+#    #+#             */
/*   Updated: 2016/12/02 16:13:05 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static t_bool	ft_backtrack(t_piece *piece, char **map)
{
	printf("Start recur\n");
	if ((piece->symbol == 'A') &&
		!ft_drop_piece(map, piece) &&
		ft_pick_piece(map, piece) &&
		(ft_move_piece(piece, map) == NULL))
		return (FALSE);
	printf("Condition d'arret passe\n");
	ft_pick_piece(map, piece);
	if (!ft_drop_piece(map, piece))
	{
		printf("Pas possible de poser la piece %c\n", piece->symbol);
		ft_pick_piece(map, piece);
		ft_move_piece(piece, map);
		printf("On deplace la piece%c\n", piece->symbol);
		ft_backtrack(piece, map);
	}
	else if (piece->next != NULL)
	{
		printf("Piece posee, on enchaine a la suivante\n");
		ft_backtrack(piece->next, map);
	}
	return (TRUE);
}

static void		ft_bruteforce(t_piece *lst_piece)
{
	char	**map;
	int		size;

	map = NULL;
	size = 5;
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
