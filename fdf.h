/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:15:16 by mait-aad          #+#    #+#             */
/*   Updated: 2022/03/12 19:46:54 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 1000
# define BUFFER_SIZE 100
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		w;
	int		h;
}	t_img;

typedef struct s_pixel
{
	int	from;
	int	to;
}t_pixel;

typedef struct s_coordinates
{
	char	*map;
	int		x;
	int		y;
	int		**z;
}	t_cdts;

typedef struct s_demo
{
	int	w;
	int	h;
	int	a_w;
	int	a_h;
	int	a_z;
}	t_demo;

typedef struct s_data
{
	void	*mlx;
	int		dx;
	int		sx;
	int		dy;
	int		sy;
	int		err;
	int		e2;
	void	*mlx_win;
	t_img	mlx_img;
	t_cdts	map;
	t_demo	dm;
}	t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

char	*ft_strjoin(char	*s1, char	*s2);
char	*get_next_line(int fd);
char	**ft_split(char	*s, char c);
char	*ft_strchr(const char	*str, int c);
size_t	ft_strlen(const char *str);
void	ft_strncpy(char *dest, char *src, int size);
int		ft_atoi(const char	*str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*get_data(char	*map);
int		**split_data(t_cdts *data);
void	ft_bresenham(t_data *fdf, t_pixel *pixelx, t_pixel	*pixely);
void	ft_draw_cloms(t_data	*data, t_pixel	coz);
void	ft_draw_lines(t_data	*data, t_pixel	coz);
void	img_pix_put(t_img img, int x, int y, int color);
int		get_win_w(t_data	*data);
int		get_win_h(t_data	*data);
int		check2(char	*s, char c);

#endif
