#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/22 10:52:01 by gvandeve          #+#    #+#              #
#    Updated: 2016/12/03 17:19:42 by gvandeve         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	fillit
DIRSRC		=	./srcs/
DIROBJ		=	./obj/
INCLUDE		=	./includes

SRC			=	$(DIRSRC)fillit.c \
				$(DIRSRC)ft_build_lst_piece.c \
				$(DIRSRC)ft_is_valid.c \
				$(DIRSRC)ft_manip_piece.c \
				$(DIRSRC)ft_strsplit.c \
				$(DIRSRC)ft_utils.c \
				$(DIRSRC)ft_work_on_piece.c

OBJ			=	fillit.o \
				ft_build_lst_piece.o \
				ft_is_valid.o \
				ft_manip_piece.o \
				ft_strsplit.o \
				ft_utils.o \
				ft_work_on_piece.o

COMP		=	gcc
FLAGS		=	-Wall -Wextra -Werror


all: $(NAME)

$(NAME):
	$(COMP) -c $(FLAGS) $(SRC) -I $(INCLUDE)
	$(COMP) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

