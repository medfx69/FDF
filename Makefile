# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 17:45:35 by mait-aad          #+#    #+#              #
#    Updated: 2022/03/09 19:05:56 by mait-aad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf.a
NAMEB=fdf_bonus.a
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
	bresen.c\
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
	bresen.o\
	ft_get_demos.o
SRCB =  fdf_bonus.c\
	get_next_line.c\
	utils.c\
	ft_split.c\
	ft_substr.c\
	ft_atoi.c\
	maps_to_data.c\
	put_pixel.c\
	draw.c\
	bresen.c\
	ft_get_demos.c
OBJB =fdf_bonus.o\
	get_next_line.o\
	utils.o\
	ft_split.o\
	ft_substr.o\
	ft_atoi.o\
	maps_to_data.o\
	put_pixel.o\
	draw.o\
	bresen.o\
	ft_get_demos.o
all : $(NAME)

bonus : $(NAMEB) 

$(NAMEB):
	$(CC) $(FLAGS) -c $(SRCB)
	ar -rc $(NAMEB) $(OBJB)
	$(CC) $(FLAGS2)	$(OBJB)
	rm -f $(OBJB)
$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	ar -rc $(NAME) $(OBJ)
	$(CC) $(FLAGS2)	$(NAME)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(NAMEB) a.out

clean:
	rm -f *.o

re: fclean all
.PHONY: fclean clean re all
