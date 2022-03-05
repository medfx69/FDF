# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 16:06:23 by mait-aad          #+#    #+#              #
#    Updated: 2022/03/05 18:22:07 by mait-aad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=fdf.a
CC=gcc
FLAGS=-Wall -Wextra -Werror
FLAGS2=-Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit
RM=rm -f
SRC = fdf.c\
	get_next_line.c\
	get_next_line_utils.c\
	ft_split.c\
	ft_substr.c\
	ft_atoi.c\
	maps_to_data.c\
	put_pixel.c\
	draw.c\
	bresenham.c

OBJ = fdf.o\
	get_next_line.o\
	get_next_line_utils.o\
	ft_split.o\
	ft_substr.o\
	ft_atoi.o\
	maps_to_data.o\
	put_pixel.o\
	draw.o\
	bresenham.o
all : $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	ar -rc $(NAME) $(OBJ)
	$(CC) $(FLAGS2)	$(NAME)

fclean: clean
	rm -f $(NAME) a.out

clean:
	rm -f *.o

re: fclean all
.PHONY: fclean clean re all
