/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:40:35 by mait-aad          #+#    #+#             */
/*   Updated: 2022/03/02 21:58:11 by mait-aad         ###   ########.fr       */
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
    *x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void plot_line(x0, x1, y0, y1, t_data *data)
{
	    int dx, dy, dz,p, x, y,tmp1,tmp2,sing;
 
	dx=x1-x0;
	dy=y1-y0;
	dz = data->map.z[x1][y1] - data->map.z[x0][y0];
	sing = 1;
	if (dz < 0)
		sing = -1;
	x=x0;
	y=y0;
 
	p=2*dy-dx;
 
	while(x<x1)
	{
		if(p>=0)
		{
			tmp1 = x;
			tmp2 = y;
			iso(tmp1,tmp2,data->map.z[x0][y0]);
			if (dz != 0)
				data->map.z += sing;
			img_pix_put(data->mlx_img.img, tmp1, tmp2, 0xFFFFFF);
			y=y+1;
			p=p+2*dy-2*dx;
		}
		else
		{
			tmp1 = x;
			tmp2 = y;
			iso(tmp1,tmp2,data->map.z[x0][y0]);
			if (dz != 0)
				data->map.z += sing;
			img_pix_put(data->mlx_img.img, tmp1, tmp2, 0xFFFFFF);
			p=p+2*dy;
		}
		x=x+1;
	}
}

int	render_rect(t_img	*img, t_rect rect ,t_data	*data)
{
	t_pixel	cox;
	t_pixel	coy;
	int		x;
	int		y;
	// img_pix_put(img, j++, i, 0xFFFFFF);
	x = 0;
	y = 0;

	while(x < data->map.x && y < data->map.y)
	{
		cox.from = x;
		cox.to = x + 1;
		coy.from = y;
		coy.to = y + 1;
		plot_line(cox.from,cox.to,coy.from,coy.from,data);
		plot_line(cox.from,cox.from,coy.from,coy.to,data);
	}
}

int	render(t_data *data)
{
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
