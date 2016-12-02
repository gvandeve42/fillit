/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_lst_piece.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:52:56 by gvandeve          #+#    #+#             */
/*   Updated: 2016/12/02 20:09:33 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_piece		*ft_create_elem(t_piece *elem)
{
	int		i;

	i = 0;
	if ((elem = (t_piece*)malloc(sizeof(t_piece))) == NULL)
		return (NULL);
	while (i < 4)
		elem->i[i++] = 0;
	i = 0;
	while (i < 4)
		elem->j[i++] = 0;
	elem->next = NULL;
	elem->symbol = 'A';
	return (elem);
}

static t_piece		*ft_add_elem(t_piece **list)
{
	t_piece		*tmp_list;

	tmp_list = *list;
	if (*list == NULL)
	{
		*list = ft_create_elem(*list);
		tmp_list = *list;
	}
	else
	{
		while ((*list)->next != NULL)
			(*list) = (*list)->next;
		(*list)->next = ft_create_elem((*list));
	}
	return ((tmp_list));
}

static t_piece		*ft_init_piece(t_piece *piece, char **table, int c)
{
	int		i;
	int		j;
	int		iter;

	i = 0;
	j = 0;
	iter = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (table[i][j] == '#')
			{
				piece->i[iter] = i;
				piece->j[iter] = j;
				iter++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	ft_reset_piece(&piece);
	piece->symbol += c;
	return (piece);
}

t_piece				*ft_build_lst_piece(t_piece **list,
		char buff[BUFF_SIZE + 1])
{
	char		**table;
	t_piece		*piece;
	int			i;

	i = 0;
	*list = ft_add_elem(list);
	table = ft_strsplit(buff, '\n');
	piece = *list;
	while (piece->next != NULL)
	{
		piece = piece->next;
		i++;
	}
	piece = ft_init_piece(piece, table, i);
	return (*list);
}
