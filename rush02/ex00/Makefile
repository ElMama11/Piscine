# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mverger <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/19 21:20:38 by mverger           #+#    #+#              #
#    Updated: 2021/09/19 23:14:57 by pdal-mol         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CMD=gcc
FLAGS=-Wall -Werror -Wextra

NAME=rush-02

SRC=$(wildcard *.c)

OBJ= $(SRC:.c=.o)

%.o: %.c
	$(CMD) -o $(FLAGS) -c $< -o $@

$(NAME) :	$(SRC) $(OBJ) t_dict.h
			$(CMD) $(FLAGS) $(OBJ) -o $(NAME) 
		

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

.PHONY: all clean fclean
