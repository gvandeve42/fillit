/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:19:28 by gvandeve          #+#    #+#             */
/*   Updated: 2016/11/30 16:39:42 by cchampou         ###   ########.fr       */
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

typedef	int			t_bool;

typedef struct		s_piece
{
	int				i[4];
	int				j[4];
  	char				symbol;
	struct s_piece	*next;
}					t_piece;

# define TRUE		1
# define FALSE		0
# define BUFF_SIZE	21
# define MAP_SIZE	104

void			ft_putchar(char c);
void			ft_putstr(char *str);
char			**ft_strsplit(const char *s, char c);
size_t			ft_strlen(char *str);
t_bool			ft_is_valid_test(char buff[BUFF_SIZE + 1], int is_read);
int				ft_valid_end(t_bool end);
t_piece			*ft_build_lst_piece(t_piece **list, char buff[BUFF_SIZE + 1]);

#endif







