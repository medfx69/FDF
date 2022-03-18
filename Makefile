# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 17:45:35 by mait-aad          #+#    #+#              #
#    Updated: 2022/03/18 13:00:22 by mait-aad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
NAMEB=fdf_bonus
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
all : $(NAME)
$(NAME):
	$(CC) $(FLAGS2) $(SRC) -o $(NAME)

bonus : $(NAMEB) 
$(NAMEB):
	$(CC) $(FLAGS2) $(SRCB) -o $(NAMEB)


fclean: clean
	rm -f $(NAME) $(NAMEB)

clean:
	rm -f *.o

re: fclean all
.PHONY: fclean clean re all
