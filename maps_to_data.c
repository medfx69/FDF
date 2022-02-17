/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_to_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:39:30 by mait-aad          #+#    #+#             */
/*   Updated: 2022/02/17 18:48:56 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_y(cahr **data)
{
	int i;
	while(*data[i])
	{
		i++;
	}
	return (i);
}
char	*get_data(char	*map)
{
	int		i;
	char	*data;
	char	*tmp = "HELLO";

	i = open(map,O_RDONLY);
	while (tmp != NULL)
	{
		tmp = get_next_line(i);
		ft_strjoin(data, tmp);
	}
	free(tmp);
	return (data);
}

int	*trsn_char_int(char **s)
{
	int	i[2];
	int	*cords;

	i[0] = 0;
	i[1] = 0;
	cords = (int)malloc(sizeof(int) * get_y(s));
	while(*s[i[0]])
	{
		cords[i[1]] = ft_atoi(s[i[0]]);
		i[0]++;
		i[1]++;
	}
	return (cords);
}

char	**split_data(char	*data)
{
	char	**splted_data;
	char	**tmp;
	int		**cords;
	int		i;

	split_data = ft_split(data, '\n');
	cords = (int *)malloc(sizeof(int) * get_y(split_data));
	while(*split_data[i])
	{
		tmp = ft_split(split_data[i]," ");
		cords[i] = trsn_char_int(tmp);
		i++;
	}
	return (cords);
}