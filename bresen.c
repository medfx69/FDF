/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:34:33 by mait-aad          #+#    #+#             */
/*   Updated: 2022/03/09 18:04:56 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	bool(int a, int b)
{
	if (a > b)
		return (a);
	return (-b);
}

int	bool2(int a, int b)
{
	if (a < b)
		return (1);
	return (-1);
}

void	ft_bresenham(t_data *data, t_pixel *pixelx, t_pixel	*pixely)
{
	data->dx = (abs(pixelx->to - pixelx->from));
	data->sx = bool2(pixelx->from, pixelx->to);
	data->dy = (abs(pixely->to - pixely->from));
	data->sy = bool2(pixely->from, pixely->to);
	data->err = bool(data->dx, data->dy) / 2;
	while (1)
	{
		img_pix_put(&data->mlx_img, pixelx->from + data->dm.a_w,
			pixely->from + data->dm.a_h, WHITE_PIXEL);
		if (pixelx->from == pixelx->to && pixely->from == pixely->to)
			break ;
		data->e2 = data->err;
		if (data->e2 > -data->dx)
		{
			data->err -= data->dy;
			pixelx->from += data->sx;
		}
		if (data->e2 < data->dy)
		{
			data->err += data->dx;
			pixely->from += data->sy;
		}
	}
}
