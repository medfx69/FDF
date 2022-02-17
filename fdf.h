/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:15:16 by mait-aad          #+#    #+#             */
/*   Updated: 2022/02/17 17:57:15 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <mlx.h>
# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300
# define BUFFER_SIZE 100
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF

typedef struct s_img
{
	void	*img;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct	s_data
{
	void	*mlx;
	void	*mlx_win;
	t_img	mlx_img;
}	t_data;

typedef struct	s_rect
{
	int	x;
	int	y;
	int	width;
	int height;
	int color;
}	t_rect;

typedef struct	s_coordinates
{
	void	*map;
	int		*x;
	int		*y;
	int		**z;
} t_cdts;


char	*ft_strjoin(char	*s1, char	*s2);
char	*get_next_line(int fd);
char	**ft_split(char	*s, char c)
char	*ft_strchr(const char	*str, int c);
size_t	ft_strlen(const char *str);
void	ft_strncpy(char *dest, char *src, int size);
int		ft_atoi(const char	*str)

#endif
