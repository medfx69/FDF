# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 17:45:35 by mait-aad          #+#    #+#              #
#    Updated: 2022/03/09 17:47:58 by mait-aad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf.a
CC=gcc
FLAGS=-Wall -Wextra -Werror
FLAGS2=-Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit
RM=rm -f
SRC = fdf.c\
	get_next_line.c\
	utils.c\
	ft_split.c\
	ft_substr.c\
	ft_atoi.c\
	maps_to_data.c\
	put_pixel.c\
	draw.c\
	bresenham.c\
	ft_get_demos.c

OBJ = fdf.o\
	get_next_line.o\
	utils.o\
	ft_split.o\
	ft_substr.o\
	ft_atoi.o\
	maps_to_data.o\
	put_pixel.o\
	draw.o\
	bresenham.o\
	ft_get_demos.o
all : $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	ar -rc $(NAME) $(OBJ)
	$(CC) $(FLAGS2)	$(NAME)
	rm -f $(OBJ) $(NAME)

fclean: clean
	rm -f $(NAME) a.out

clean:
	rm -f *.o

re: fclean all
.PHONY: fclean clean re all
