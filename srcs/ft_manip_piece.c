/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manip_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 21:26:58 by gvandeve          #+#    #+#             */
/*   Updated: 2016/12/02 20:11:43 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_piece		*ft_retour_ligne(t_piece *elem)
{
	int	i;
	int	min;

	i = 0;
	min = 1000;
	while (i < 4)
	{
		if (min > elem->j[i])
			min = elem->j[i];
		i++;
	}
	i = 0;
	while (i < 4)
		elem->j[i++] -= min;
	return (elem);
}

t_bool				ft_drop_piece(char **table, t_piece *piece)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (table[piece->i[i]] &&
			table[piece->i[i]][piece->j[i]] &&
			table[piece->i[i]][piece->j[i]] == '.')
			table[piece->i[i]][piece->j[i]] = piece->symbol;
		else
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool				ft_pick_piece(char **table, t_piece *piece)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (table[piece->i[i]] &&
			table[piece->i[i]][piece->j[i]] &&
			table[piece->i[i]][piece->j[i]] == piece->symbol)
			table[piece->i[i]][piece->j[i]] = '.';
		i++;
	}
	return (TRUE);
}

t_piece				*ft_move_piece(t_piece *piece, char **map)
{
	int		i;

	i = 0;
	while (map[i] && map[piece->i[i]][piece->j[i] + 1] && i < 4)
		i++;
	if (i == 4)
	{
		i = 0;
		while (i < 4)
			piece->j[i++] += 1;
		return (piece);
	}
	i = 0;
	while (map[i] && map[piece->i[i] + 1] && i < 4)
		i++;
	if (i == 4)
	{
		i = 0;
		while (i < 4)
			piece->i[i++] += 1;
		piece = ft_retour_ligne(piece);
		return (piece);
	}
	return (NULL);
}
