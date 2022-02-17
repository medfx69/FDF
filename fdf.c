/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:40:35 by mait-aad          #+#    #+#             */
/*   Updated: 2022/02/17 14:43:27 by mait-aad         ###   ########.fr       */
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
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	render_rect(t_img	*img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j= rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
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
	render_background(&data->mlx_img, WHITE_PIXEL);
	render_rect(&data->mlx_img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT -100, 100, 100, GREEN_PIXEL});
	render_rect(&data->mlx_img, (t_rect){0, 0, 100, 100, RED_PIXEL});
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


int	main(void)
{
	t_data	data;
	int		i = 50;
	int		j = 50;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	data.mlx_img.img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.mlx_img.addr = mlx_get_data_addr(data.mlx_img.img, &data.mlx_img.bpp, &data.mlx_img.line_len, &data.mlx_img.endian);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_key_hook(data.mlx_win, &handle_keypress, &data);
	
	mlx_loop(data.mlx);
	free(data.mlx);
}
