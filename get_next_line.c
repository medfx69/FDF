/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-aad <mait-aad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:40:22 by mait-aad          #+#    #+#             */
/*   Updated: 2022/03/09 17:45:22 by mait-aad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*read_and_save(int fd, char *save)
{
	char	*buff;
	int		bytes;

	buff = malloc(1000000 + 1 * sizeof(char));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (bytes != 0)
	{
		bytes = read(fd, buff, 1000000);
		if (bytes <= -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = read_and_save(fd, save);
	if (!save)
		return (NULL);
	return (save);
}

char	*get_data(char	*map)
{
	int		i;
	char	*tmp;

	i = open(map, O_RDONLY);
	tmp = get_next_line(i);
	close(i);
	return (tmp);
}
