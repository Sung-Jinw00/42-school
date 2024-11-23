/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:44:36 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/22 19:04:31 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	line[BUFFER_SIZE];
	int		bytesRead;
	int		i;

	i = 0;
	fd = open();
	if (fd == -1)
		return (NULL);
	while ((bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (bytesRead == -1)
			return (NULL);
	}
	close(fd);
	
}
