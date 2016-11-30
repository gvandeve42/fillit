/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manip_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 21:26:58 by gvandeve          #+#    #+#             */
/*   Updated: 2016/11/30 23:22:20 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_bool		ft_drop_piece(char **table, t_piece *piece)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (table[piece->i[i]][piece->j[i]] &&
			table[piece->i[i]][piece->j[i]] == '.')
			table[piece->i[i]][piece->j[i]] = piece->symbol;
		else
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void		ft_pick_piece(char **table, t_piece *piece)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (table[piece->i[i]][piece->j[i]] == piece->symbol)
			table[piece->i[i]][piece->j[i]] = '.';
		i++;
	}
}

t_piece		*ft_move_piece(t_piece *piece, char **map)
{
	int		i;
	int		min;

	min = 3;
	i = 0;
	printf("Test si decallage droite possible\n");
	while (map[piece->i[i]][piece->j[i] + 1] && i < 4)
		i++;
	printf("i = %d\n", i);
	if (--i == 3)
	{
		i = 0;
		while (i < 4)
			piece->j[i++] += 1;
		printf("i = %d\n", i);
		return (piece);
	}
	i = 0;
	while (map[piece->i[i] + 1][piece->j[i]] && i < 4)
		i++;
	if (i == 3)
	{
		i = 0;
		while (i < 4)
			piece->i[i++] += 1;
		return (piece);
	}
	return (NULL);
}




















