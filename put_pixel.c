/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:51:50 by mait-aad          #+#    #+#             */
/*   Updated: 2022/03/12 19:48:01 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_pix_put(t_img img, int x, int y, int color)
{
	if (x >= 0 && x < img.w && y >= 0 && y < img.h)
	{
		img.addr = (int *)mlx_get_data_addr(img.img, &img.bpp,
				&img.line_len, &img.endian);
		img.addr[x + y * img.line_len / 4] = color;
	}
}
