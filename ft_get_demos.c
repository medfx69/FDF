/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_demos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:42:33 by mait-aad          #+#    #+#             */
/*   Updated: 2022/03/09 17:44:58 by mait-aad         ###   ########.fr       */
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
		return (2000);
	}
	if (2 * i > data->map.y)
	{
		data->dm.a_w = 750;
		return (1400);
	}
	else
	{
		data->dm.a_w = 450;
		return (900);
	}
	return (i * 100);
}

int	get_win_h(t_data *data)
{
	int	i;

	i = data->map.y / 3;
	if (data->map.y > 100)
	{
		data->dm.a_h = 250;
		return (2000);
	}	
	if (2 * i > data->map.x)
	{
		data->dm.a_h = 750;
		return (1400);
	}
	else
	{
		data->dm.a_h = 450;
		return (900);
	}
	return (0);
}
