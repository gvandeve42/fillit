#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvandeve <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/22 10:52:01 by gvandeve          #+#    #+#              #
#    Updated: 2016/11/23 17:52:24 by gvandeve         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	fillit
DIRSRC		=	./srcs/
DIROBJ		=	./obj/
INCLUDE		=	./includes
SRC			=	*.c

OBJ			=	$(SRC:.c=.o)

COMP		=	gcc
FLAGS		=	-Wall -Wextra -Werror


all: $(NAME)

$(NAME):
	$(COMP) -c $(FLAGS) $(DIRSRC)$(SRC) -I $(INCLUDE)
	$(COMP) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all