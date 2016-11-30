/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_on_piece.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:14:47 by cchampou          #+#    #+#             */
/*   Updated: 2016/11/30 16:57:13 by cchampou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_work_on_piece(t_piece **list, t_bool end)
{
	char	map[MAP_SIZE][MAP_SIZE];
	t_piece	*elem;

	ft_init_map(map);
	elem = *list;

}

void	ft_init_piece(t_piece *elem)
{
	int		i;
	int		min;

	i = 0;
	while (i < 4)
	{
		if (min > elem->i[i])
			min = elem->i[i];
		i = 0;
	}
	while (i < 4)
	{
		elem->i[i] -= min;
		i--;
	}
}

void	ft_ballade_du_dimanche_matin(t_piece *elem)
{
	elem->
}

void	ft_init_map(char **map)
{
	int		i;
	int		j;

	i = 3;
	j = 3;
	while (i >= 0)
	{
		while (j >= 0)
		{
			map[i][j] = '.';
			j--;
		}
		j = 3;
		i--;
	}
}
