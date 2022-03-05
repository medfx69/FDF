/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:41:58 by mait-aad          #+#    #+#             */
/*   Updated: 2022/03/05 18:06:07 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int	readcolor(char *str)
// {
// 	int	i;
// 	int	j;

// 	i = 0x0;
// 	j = 0;
// 	while (str[j])
// 	{
// 		if (str[j] <= '9' && str[j] >= '0')
// 			i = (i * 10) + (str[j] - 48);
// 		else if (str[j] == 'A')
// 			i = i*10 + 0xA;
// 		else if (str[j] == 'B')
// 			i = i*10 + 0xB;
// 		else if	(str[j] == 'C')
// 			i = i*10 + 0xC;
// 		else if	(str[j] == 'D')
// 			i = i*10 + 0xD;
// 		else if	(str[j] == 'E')
// 			i = i*10 + 0xE;
// 		else if	(str[j] == 'F')
// 			i = i*10 + 0xF;
// 		j++;
// 	}
// 	return (i);
// }

int	ft_atoi(const char	*str)
{
	int	i;
	int	countmi;
	int	num;

	i = 0;
	countmi = 0;
	num = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			countmi++;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	// if (str[i] == ',')
	// 	color = redcoler(str + i + 1)
	if (countmi != 0)
		return (-num);
	else
		return (num);
}
