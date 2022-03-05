/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:38:04 by mait-aad          #+#    #+#             */
/*   Updated: 2022/03/05 18:07:15 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
static void iso(int *x, int *y, int z)
{
    int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void	ft_draw_cloms(t_data	*data, t_pixel	coz)
{
	t_pixel	cox;
	t_pixel	coy;
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
			ft_bresenham(data, &cox, &coy);
			x++;	
		}
		y++;
	}
}

void	ft_draw_lines(t_data	*data, t_pixel	coz)
{
	t_pixel	cox;
	t_pixel	coy;
	int		x;
	int		y;

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
			ft_bresenham(data, &cox, &coy);
			y++;	
		}
		x++;
	}
}