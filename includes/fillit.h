/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:19:28 by gvandeve          #+#    #+#             */
/*   Updated: 2016/11/23 16:33:14 by gvandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <string.h>

typedef	int	t_bool;

# define TRUE		1
# define FALSE		0
# define BUFF_SIZE	21

void			ft_putchar(char c);
void			ft_putstr(char *str);
char			**ft_strsplit(const char *s, char c);
size_t			ft_strlen(char *str);
t_bool			ft_is_valid_test(char buff[BUFF_SIZE + 1], int is_read);
int				ft_valid_end(t_bool end);

#endif
