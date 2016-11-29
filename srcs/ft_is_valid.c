/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:19:10 by gvandeve          #+#    #+#             */
/*   Updated: 2016/11/28 12:06:13 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_is_piece(char **table, int coor, int iter, char before)
{
	int		i;
	int		j;

	i = coor / 4;
	j = coor % 4;
	while (table[i][j] != '#')
	{
		coor++;
		i = coor / 4;
		j = coor % 4;
	}
	//printf("test de piece || i = %d || j = %d || iter = %d ||\n", i, j, iter);
	if (j < 3 && before != 'r' && iter < 4)
		if (table[i][j + 1] == '#')
			iter = (ft_is_piece(table, coor + 1, iter + 1, 'l'));
	if (i < 3 && before != 'u' && iter < 4)
		if (table[i + 1][j] == '#')
			iter = (ft_is_piece(table, coor + 4, iter + 1, 'd'));
	if (j > 0 && before != 'l' && iter < 4)
		if (table[i][j - 1] == '#')
			iter = (ft_is_piece(table, coor - 1, iter + 1, 'r'));
	if (i > 0 && before != 'd' && iter < 4)
		if (table[i - 1][j] == '#')
			iter = (ft_is_piece(table, coor - 4, iter + 1, 'u'));
	return (iter);
}

static t_bool	ft_is_table_valid(char **table)
{
	int			i;

	i = 0;
	while (table[i] != NULL)
		if (ft_strlen(table[i++]) != 4)
			return (FALSE);
	if (ft_is_piece(table, 0, 1, 'o') == 4)
		return (TRUE);
	return (FALSE);
}

static t_bool	ft_is_valid(char buff[BUFF_SIZE + 1])
{
	int		i;
	int		j;
	char	**table;

	i = 0;
	j = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] != '.' &&
			buff[i] != '#' &&
			buff[i] != '\n')
			return (FALSE);
		if (buff[i] == '#')
			j++;
		i++;
	}
	if (j != 4)
		return (FALSE);
	table = ft_strsplit(buff, '\n');
	if (ft_is_table_valid(table) == FALSE)
		return (FALSE);
	else
		return (TRUE);
}

int				ft_valid_end(t_bool end)
{
	if (end == TRUE)
		return (0);
	else
	{
		write(1, "error\n", 6);
		return (1);
	}
}

t_bool			ft_is_valid_test(char buff[BUFF_SIZE + 1], int is_read)
{
	if (is_read != BUFF_SIZE && is_read != BUFF_SIZE - 1)
		return (FALSE);
	if (is_read == BUFF_SIZE)
		if (buff[BUFF_SIZE - 1] != '\n')
			return (FALSE);
	if (ft_is_valid(buff) == FALSE)
		return (FALSE);
	return (TRUE);
}
