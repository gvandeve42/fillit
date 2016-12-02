/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:49:17 by gvandeve          #+#    #+#             */
/*   Updated: 2016/12/02 20:02:57 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
		ft_putchar(*str++);
}

size_t	ft_strlen(char *str)
{
	size_t	result;

	result = 0;
	while (*str++ != '\0')
		result++;
	return (result);
}

void	ft_print_map(char **map)
{
	int		i;

	i = 0;
	while (map && map[i])
	{
		ft_putstr(map[i++]);
		ft_putchar('\n');
	}
}
