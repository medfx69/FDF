/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:40:10 by mait-aad          #+#    #+#             */
/*   Updated: 2022/02/17 14:40:13 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

char	*ft_strchr(const char	*str, int c)
{
	char	*s;

	s = (char *)str;
	if (!s)
		return (0);
	while (*s != (char) c)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return (s);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

static char	*ft_strcpy(char	*dest, char	*src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(char	*s1)
{
	int		i;
	char	*str;
	char	*ptr;

	str = (char *)s1;
	i = 0;
	while (str[i])
		i++;
	ptr = malloc(i + 1);
	if (!ptr)
		return (0);
	ft_strcpy(ptr, str);
	ptr [i] = 0;
	return (ptr);
}

char	*ft_strjoin(char	*s1, char	*s2)
{
	char	*ptr;
	int		j;
	int		k;
	int		i;

	if (!s1 || !s2)
		return (ft_strdup(s2));
	k = ft_strlen(s1);
	j = ft_strlen(s2);
	ptr = malloc(k + j + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		ptr[i++] = s1[j++];
	j = 0;
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = 0;
	free(s1);
	return (ptr);
}
