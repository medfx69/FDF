/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_to_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:39:30 by mait-aad          #+#    #+#             */
/*   Updated: 2022/03/09 17:42:31 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_y(char **data)
{
	int	i;

	i = 0;
	if (data == NULL)
		return (0);
	while (data[i])
		i++;
	return (i);
}

int	free_char_shit(char **s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (0);
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

int	check(char **s)
{
	int		i;
	int		j;
	int		c;

	i = 0;
	while (s[i])
	{
		j = 0;
		c = 0;
		while (s[i][j])
		{
			if (check2("-0123456789ABCDEFabcdefx,", s[i][j]) == 1)
				c++;
			j++;
		}
		if (j != c)
			return (0);
		i++;
	}
	return (1);
}

int	**split_data(t_cdts	*data)
{
	char	**splted_data;
	char	**tmp;
	int		i;

	splted_data = ft_split(get_data(data->map), '\n');
	data->y = get_y(splted_data) + 1;
	data->z = malloc(sizeof(int *) * data->y);
	if (!data->z)
		return (0);
	i = 0;
	tmp = NULL;
	while (i < data->y - 1)
	{	
		tmp = ft_split(splted_data[i], 32);
		if (check(tmp) == 0)
			return (0);
		data->z[i] = trsn_char_int(tmp);
		if (i++ != data->y - 2)
			free_char_shit(tmp);
	}
	data->x = get_y(tmp);
	free_char_shit(splted_data);
	free_char_shit(tmp);
	return (data->z);
}
