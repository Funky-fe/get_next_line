/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:16:48 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/05/17 18:37:58 by rlima-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		resto[BUFFER_SIZE + 1];
	char			*line;

	if (fd < 0 || FOPEN_MAX < fd)
		return (NULL);
	line = NULL;
	while (resto[0] || read(fd, resto, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, resto);
		if (ft_strlen(resto) == 0)
			return (line);
		if (find_nl(resto) == 1)
			break ;
		if (read(fd, resto, BUFFER_SIZE) < 0)
		{
			free (line);
			return (NULL);
		}
	}
	return (line);
}
