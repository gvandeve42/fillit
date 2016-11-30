/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:16:40 by gvandeve          #+#    #+#             */
/*   Updated: 2016/11/30 23:16:23 by gvandeve         ###   ########.fr       */
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
	char	**map;
	int		i;

	map = NULL;
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
	/*if (lst_piece != NULL)
		while (lst_piece != NULL)
		{
			printf("Piece trouvee\n");
			printf("Coor || i[0] = %d || j[0] = %d ||\n", lst_piece->i[0], lst_piece->j[0]);
			printf("Coor || i[1] = %d || j[1] = %d ||\n", lst_piece->i[1], lst_piece->j[1]);
			printf("Coor || i[2] = %d || j[2] = %d ||\n", lst_piece->i[2], lst_piece->j[2]);
			printf("Coor || i[3] = %d || j[3] = %d ||\n", lst_piece->i[3], lst_piece->j[3]);
			printf("Char || elem->symb = %c ||\n\n", lst_piece->symbol);
			lst_piece = lst_piece->next;
			}*/
	printf("Test init map\n");
	map = ft_init_map(map, 6);
	printf("Test drop piece\n");
	ft_drop_piece(map, lst_piece);
	printf("Piece dropped\n");
	i = 0;
	printf("Print map\n");
	while(map && map[i])
		printf("%s\n", map[i++]);
	printf("Test pick piece\n");
	ft_pick_piece(map, lst_piece);
	printf("Test move piece\n");
	lst_piece = ft_move_piece(lst_piece, map);
	printf("Second drop piece");
	ft_drop_piece(map, lst_piece);
	printf("Piece dropped\n");
	i = 0;
	printf("Print map\n");
	while(map && map[i])
		printf("%s\n", map[i++]);
	return (ft_valid_end(end));
}
