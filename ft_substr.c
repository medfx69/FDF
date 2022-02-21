/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:58:20 by mait-aad          #+#    #+#             */
/*   Updated: 2022/02/19 15:26:26 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_substr(char	*str, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (!str)
		return (NULL);
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (str[j])
	{
		if (j >= start && i < len)
		{
				ptr[i] = str[j];
				i++;
		}
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}
