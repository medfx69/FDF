/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:40:35 by mait-aad          #+#    #+#             */
/*   Updated: 2022/03/12 15:08:07 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_rect(t_data	*data)
{
	t_pixel	coz;

	coz.to = 0;
	ft_draw_cloms(data, coz);
	ft_draw_lines(data, coz);
}

int	render(t_data *data)
{
	render_rect(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img.img, 0, 0);
	return (0);
}

int	handle_keypress(int key, t_data	*data)
{
	if (key == 53 || key == 17)
	{
		mlx_destroy_image(data->mlx, data->mlx_img.img);
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(1);
	}
	return (0);
}

int	ft_exit(t_data	*data)
{
	mlx_destroy_image(data->mlx, data->mlx_img.img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(1);
	return (0);
}

int	main(int ac, char	**av)
{
	t_data	data;

	if (ac != 2)
	{
		write (1, "pleas enter a map\n", 18);
		return (0);
	}
	data.map.map = av[1];
	data.map.z = split_data(&data.map);
	if (!data.map.z || data.map.x == 0 || data.map.y == 0)
	{
		write(1, "pleas check to enter a valid map\n", 34);
		return (0);
	}
	data.mlx = mlx_init();
	data.dm.w = get_win_w(&data);
	data.dm.h = get_win_h(&data);
	data.mlx_win = mlx_new_window(data.mlx, data.dm.w, data.dm.h, "fdf");
	data.mlx_img.img = mlx_new_image(data.mlx, data.dm.w, data.dm.h);
	data.mlx_img.addr = mlx_get_data_addr(data.mlx_img.img,
			&data.mlx_img.bpp, &data.mlx_img.line_len, &data.mlx_img.endian);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_key_hook(data.mlx_win, &handle_keypress, &data);
	mlx_hook(data.mlx_win, 17, 0, &ft_exit, &data);
	mlx_loop(data.mlx);
}
