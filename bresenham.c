/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:34:33 by mait-aad          #+#    #+#             */
/*   Updated: 2022/03/09 17:44:04 by mait-aad         ###   ########.fr       */
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

void	ft_bresenham(t_data *fdf, t_pixel *pixelx, t_pixel	*pixely)
{
	fdf->dx = (abs(pixelx->to - pixelx->from));
	fdf->sx = bool2(pixelx->from, pixelx->to);
	fdf->dy = (abs(pixely->to - pixely->from));
	fdf->sy = bool2(pixely->from, pixely->to);
	fdf->err = bool(fdf->dx, fdf->dy) / 2;
	while (1)
	{
		img_pix_put(&fdf->mlx_img, pixelx->from + fdf->dm.a_w,
			pixely->from + fdf->dm.a_h, WHITE_PIXEL);
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
