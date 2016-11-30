/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_on_piece.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:14:47 by cchampou          #+#    #+#             */
/*   Updated: 2016/12/01 00:02:20 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

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
	i = 0;
	while (i < 4)
		(*elem)->i[i++] -= min;
	i = 0;
	min = 3;
	while (i < 4)
	{
		if (min > (*elem)->j[i])
			min = (*elem)->j[i];
		i++;
	}
	i = 0;
	while (i < 4)
		(*elem)->j[i++] -= min;
}

char	**ft_init_map(char **map, size_t size)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (map && map[i])
		free(map[i++]);
	if (map)
		free(map);
	map = (char**)malloc((size + 1) * sizeof(char*));
	while (i < size)
	{
		map[i] = (char*)malloc((size + 1) * sizeof(char));
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		j = 0;
		i++;
	}
	map[i] = 0;
	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	return (map);
}

/*void	ft_work_on_piece(t_piece **list, t_bool end)
{

}*/
