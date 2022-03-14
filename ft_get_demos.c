/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_demos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:42:33 by mait-aad          #+#    #+#             */
/*   Updated: 2022/03/12 19:39:10 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_win_w(t_data *data)
{
	int	i;

	i = data->map.x / 3;
	if (data->map.x > 100)
	{
		data->dm.a_w = 1000;
		data->mlx_img.w = 2000;
		return (2000);
	}
	if (2 * i > data->map.y)
	{
		data->dm.a_w = 750;
		data->mlx_img.w = 1400;
		return (1400);
	}
	else
	{
		data->dm.a_w = 450;
		data->mlx_img.w = 900;
		return (900);
	}
	return (i * 100);
}

int	get_win_h(t_data *data)
{
	int	i;

	i = data->map.y / 3;
	data->dm.a_z = 20;
	if (data->map.y > 100)
	{
		data->dm.a_z = 1;
		data->dm.a_h = 250;
		data->mlx_img.h = 2000;
		return (2000);
	}	
	if (2 * i > data->map.x)
	{
		data->dm.a_h = 750;
		data->mlx_img.h = 1400;
		return (1400);
	}
	else
	{
		data->dm.a_h = 450;
		data->mlx_img.h = 900;
		return (900);
	}
	return (0);
}
