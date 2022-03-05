/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:34:33 by mait-aad          #+#    #+#             */
/*   Updated: 2022/03/05 18:06:53 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_bresenham(t_data *fdf, t_pixel *pixelx,
 t_pixel	*pixely)
{
	fdf->dx = (abs(pixelx->to - pixelx->from));
	fdf->sx = (pixelx->from < pixelx->to ? 1 : -1);
	fdf->dy = (abs(pixely->to - pixely->from));
	fdf->sy = (pixely->from < pixely->to ? 1 : -1);
	fdf->err = (fdf->dx > fdf->dy ? fdf->dx : -fdf->dy) / 2;
	while (1)
	{
		img_pix_put(&fdf->mlx_img, pixelx->from + 400, pixely->from + 300, WHITE_PIXEL);
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