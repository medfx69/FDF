/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:40:35 by mait-aad          #+#    #+#             */
/*   Updated: 2022/03/04 18:55:24 by mait-aad         ###   ########.fr       */
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

static void iso(int *x, int *y, int z)
{
    int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.423599);
	*y = -z + (previous_x + previous_y) * sin(0.423599);
}

void	ft_bresenham(t_data *fdf, t_pixel *pixelx, t_pixel	*pixely, t_pixel	*pixelz)
{
	fdf->dx = (abs(pixelx->to - pixelx->from));
	fdf->sx = (pixelx->from < pixelx->to ? 1 : -1);
	fdf->dy = (abs(pixely->to - pixely->from));
	fdf->sy = (pixely->from < pixely->to ? 1 : -1);
	fdf->err = (fdf->dx > fdf->dy ? fdf->dx : -fdf->dy) / 2;
	while (1)
	{
		img_pix_put(&fdf->mlx_img, pixelx->from + 400, pixely->from + 300, RED_PIXEL);
		if (pixelx->from == pixelx->to && pixely->from == pixely->to)
			break ;
		fdf->e2 = fdf->err;
		if (fdf->e2 > -fdf->dx)
		{
			fdf->err -= fdf->dy;
			pixelx->from += fdf->sx;
		}
		if (fdf->e2 < fdf->dy)
		{
			fdf->err += fdf->dx;
			pixely->from += fdf->sy;
		}
	}
}

void	render_rect(t_img	*img,t_data	*data)
{
	t_pixel	cox;
	t_pixel	coy;
	t_pixel coz;
	int		x;
	int		y;

	y = 0;
	while(y < data->map.y - 1)
	{
		x = 0;
		while (x < data->map.x - 1)
		{
			cox.to = (x + 1) * (WINDOW_WIDTH / (data->map.x * 2));
			cox.from = x * (WINDOW_WIDTH / (data->map.x * 2));
			coy.from = y *  (WINDOW_WIDTH / (data->map.y * 2));
			coy.to = y * (WINDOW_WIDTH / (data->map.y * 2));
			coz.from = data->map.z[y][x];
			coz.to = data->map.z[y][x + 1];
			iso(&cox.to, &coy.to, coz.to * 20);
			iso(&cox.from, &coy.from, coz.from * 20);
			ft_bresenham(data, &cox, &coy, &coz);
			x++;	
		}
		y++;
	}
	x = 0;
	while(x < data->map.x - 1)
	{
		y = 0;
		while (y < data->map.y - 2)
		{
			coy.to = (y + 1) * (WINDOW_WIDTH / (data->map.y * 2));
			coy.from = y * (WINDOW_WIDTH / (data->map.y * 2));
			cox.from = x *  (WINDOW_WIDTH / (data->map.x * 2));
			cox.to = x * (WINDOW_WIDTH / (data->map.x * 2));
			coz.from = data->map.z[y][x];
			coz.to = data->map.z[y + 1][x];
			iso(&cox.to, &coy.to, coz.to * 20);
			iso(&cox.from, &coy.from, coz.from * 20);
			ft_bresenham(data, &cox, &coy, &coz);
			y++;	
		}
		x++;
	}
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

int	render(t_data *data)
{
	render_background(&data->mlx_img, WHITE_PIXEL);
	render_rect(&data->mlx_img, data);
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
		data.mlx_win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
		data.mlx_img.img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
		data.mlx_img.addr = mlx_get_data_addr(data.mlx_img.img, &data.mlx_img.bpp, 
		&data.mlx_img.line_len, &data.mlx_img.endian);
		mlx_loop_hook(data.mlx, &render, &data);
		mlx_key_hook(data.mlx_win, &handle_keypress, &data);
	
		mlx_loop(data.mlx);
		free(data.mlx);
	}
}
