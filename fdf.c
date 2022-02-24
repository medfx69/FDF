/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:40:35 by mait-aad          #+#    #+#             */
/*   Updated: 2022/02/24 20:14:35 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = img->bpp - 8;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

// static void iso(int *x, int *y, int z)
// {
//     int previous_x;
//     int previous_y;

//     previous_x = *x;
//     previous_y = *y;
//     *x = (previous_x - previous_y) * cos(0.523599);
//     *y = -z + (previous_x + previous_y) * sin(0.523599);
// }
static void iso(int *x, int *y, int z)
{
    int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void plot_line(int	x0,int	x1, int	y0, int	y1, t_data *data)
{
	int	dx;
	int	s[2];
	int	dy;
	int	err[2];

	dx = abs(x1 - x0);
	s[0] = -1;
	if (x0 < x1)
		s[0] = 1;
	dy = -abs(y1 - y0);
	err[0] = dx + dy; 
	s[1] = -1;
	if (y0 < y1)
		s[1] = 1;
	//render_background(&data->mlx_img, WHITE_PIXEL);
	while (x0)
	{
		printf("<%d><%d>\n", x0, y0);
		mlx_pixel_put(data->mlx, data->mlx_img.img, x0, y0, RED_PIXEL);
		if (x0 == x1 && y0 == y1)
			break ;
		err[1] = 2 * err[0];
		if (err[1] >= dy)
		{
			err[0] += dy;
			x0 += s[0];
		}
		if (err[1] <= dx)
		{
			err[0] += dx;
			y0 += s[1];
		}
	}
}

int	render_rect(t_img	*img, t_rect rect ,t_data	*data)
{
	int	x[2];
	int	y[2];
	int **cords;

	x[0] = 0;
	y[0] = 0;
	cords = malloc(sizeof(int) * 2);
	cords[0] = malloc(sizeof(int) * data->map.x);
	cords[1] = malloc(sizeof(int) * data->map.y);
	while (x[0] < data->map.x - 1 && y[0] < data->map.y - 1)
	{	
		x[1] = x[0];
		y[1] = y[0];
		x[1] = ((WINDOW_WIDTH - 60) * x[1])/ (data->map.x);
		y[1] = ((WINDOW_HEIGHT - 60) * y[1])/ (data->map.y);
		iso(&x[1], &y[1], data->map.z[y[0]][x[0]]);
		cords[0][y[0]] = x[1];
		cords[1][y[0]] = y[1];
		//img_pix_put(img, x[1], -y[1], rect.color);
		if (y[0] > 0 && x[0] > 0)
			plot_line(cords[0][y[0]-1], cords[0][y[0]], cords[1][y[0]-1], cords[0][y[0]] , data);
		y[0]++;
		x[0]++;
	}
	return (0);
}

void render_background(t_img *img, int	color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while(j < WINDOW_WIDTH)
			img_pix_put(img, j++, i, color);
		++i;
	}
}

int	render(t_data *data)
{
	//render_background(&data->mlx_img, WHITE_PIXEL);
	// render_rect(&data->mlx_img, (t_rect){WINDOW_WIDTH, WINDOW_HEIGHT, 100, 100, GREEN_PIXEL});
	render_rect(&data->mlx_img, (t_rect){0, 0, 100, 100, RED_PIXEL}, data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img.img, 0, 0);
	return (0);
}

int handle_keypress(int key, t_data	*data)
{
	if(key == 53)
	{
		mlx_destroy_window(data->mlx,data->mlx_win);
		data->mlx_win = NULL;
	}
	return (0);
}


int	main(int	ac, char	**av)
{
	t_data	data;

	if (ac > 1)
	{
		data.map.map = av[1];
		data.map.z = split_data(&data.map);
		data.mlx = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
		data.mlx_img.img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
		data.mlx_img.addr = mlx_get_data_addr(data.mlx_img.img, &data.mlx_img.bpp, 
		&data.mlx_img.line_len, &data.mlx_img.endian);
		mlx_loop_hook(data.mlx, &render, &data);
		mlx_key_hook(data.mlx_win, &handle_keypress, &data);
	
		mlx_loop(data.mlx);
		free(data.mlx);
	}
}
