/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:19:28 by gvandeve          #+#    #+#             */
/*   Updated: 2016/12/01 01:09:13 by gvandeve         ###   ########.fr       */
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

void			ft_putchar(char c);
void			ft_putstr(char *str);
char			**ft_strsplit(const char *s, char c);
size_t			ft_strlen(char *str);
t_bool			ft_is_valid_test(char buff[BUFF_SIZE + 1], int is_read);
int				ft_valid_end(t_bool end);
t_piece			*ft_build_lst_piece(t_piece **list, char buff[BUFF_SIZE + 1]);
void			ft_reset_piece(t_piece **elem);
char			**ft_init_map(char **map, size_t size);
t_bool			ft_drop_piece(char **table, t_piece *piece);
void			ft_pick_piece(char **table, t_piece *piece);
t_piece			*ft_move_piece(t_piece *piece, char **map);
void			ft_print_map(char **map);

#endif
