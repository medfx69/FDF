/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:40:35 by mait-aad          #+#    #+#             */
/*   Updated: 2022/03/05 18:17:41 by mait-aad         ###   ########.fr       */
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
	if (key == 53)
	{
		free(data->mlx_win);
		free(data->mlx_img.img);
		mlx_destroy_image(data->mlx, data->mlx_img.img);
		mlx_clear_window(data->mlx, data->mlx_win);
		mlx_destroy_window(data->mlx, data->mlx_win);
	}
	return (0);
}

int	main(int ac, char	**av)
{
	t_data	data;
	int		i;

	if (ac != 2)
	{
		return (0);
	}
	data.map.map = av[1];
	data.map.z = split_data(&data.map);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "fdf");
	data.mlx_img.img = mlx_new_image(data.mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	data.mlx_img.addr = mlx_get_data_addr(data.mlx_img.img,
			&data.mlx_img.bpp, &data.mlx_img.line_len, &data.mlx_img.endian);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_key_hook(data.mlx_win, &handle_keypress, &data);
	mlx_loop(data.mlx);
	i = 0;
	while (i < data.map.y - 1)
		free(data.map.z[i++]);
	free(data.map.z);
	free(data.mlx);
}
