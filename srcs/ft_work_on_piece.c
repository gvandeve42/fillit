/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_on_piece.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:14:47 by cchampou          #+#    #+#             */
/*   Updated: 2016/11/30 19:02:06 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*void	ft_work_on_piece(t_piece **list, t_bool end)
{

}*/

void	ft_reset_piece(t_piece **elem)
{
	int		i;
	int		min;

	i = 0;
	min = 3;
	while (i < 4)
	{
		if (min > (*elem)->i[i])
			min = (*elem)->i[i];
		i++;
	}
	printf("Min i = %d\n", min);
	while (i >= 0)
		(*elem)->i[i--] -= min;
	i = 0;
	min = 3;
	while (i < 4)
	{
		if (min > (*elem)->j[i])
			min = (*elem)->j[i];
		i++;
	}
	printf("Min j = %d\n", min);
	while (i >= 0)
		(*elem)->j[i--] -= min;
}

/*void	ft_ballade_du_dimanche_matin(t_piece *elem)
{
	elem->
	}*/

 /*void	ft_init_map(char **map, size_t size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	}*/
