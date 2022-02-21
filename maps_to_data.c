/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_to_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:39:30 by mait-aad          #+#    #+#             */
/*   Updated: 2022/02/21 21:54:08 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_y(char **data)
{
	int	i;

	i = 0;
	while (data[i])
		i++;
	return (i);
}

void	free_char_shit(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int	*trsn_char_int(char **s)
{
	int	i;
	int	*cords;

	i = 0;
	cords = (int *)malloc(sizeof(int) * get_y(s));
	while (s[i])
	{
		cords[i] = ft_atoi(s[i]);
		i++;
	}
	return (cords);
}

void	free_int_shit(int **s)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int	**split_data(t_cdts	*data)
{
	char	**splted_data;
	char	**tmp;
	char	*pfree;
	int		i;

	pfree = get_data(data->map);
	splted_data = ft_split(pfree, '\n');
	free(pfree);
	data->y = get_y(splted_data);
	data->z = malloc(sizeof(int *) * data->y);
	if (!data->z)
		return (0);
	i = 0;
	while (i < data->y - 1)
	{
		tmp = ft_split(splted_data[i], 32);
		data->z[i] = trsn_char_int(tmp);
		if (i++ != data->y - 2)
			free_char_shit(tmp);
	}
	data->x = get_y(tmp);
	free_char_shit(splted_data);
	free_char_shit(tmp);
	return (data->z);
}
