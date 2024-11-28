/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:24:38 by marvin            #+#    #+#             */
/*   Updated: 2024/11/28 14:24:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line_save(char *line_save, int fd, int *bytes_read)
{
	char *buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	while (!(ft_strchr(line_save, '\n') || *bytes_read == 0))
	{
		*bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (*bytes_read == -1)
			return (free(buffer), free(line_save), NULL);
		buffer[*bytes_read] = '\0';
		line_save = ft_strjoin(line_save, buffer);
	}
	free(buffer);
	return (line_save);
}

char	*line_to_print(const char *line_save)
{
	size_t len;
	size_t i;
	char *line;

	i = -1;
	len = ft_strclen(line_save, '\n');
	line = malloc(len + 1);
	while (++i < len && line_save[i])
		line[i] = line_save[i];
	return (line);
}

char	*newline_save(char *line_save, size_t len_line)
{
	size_t i;
	char *newline_saved;

	i = 0;
	if (line_save[len_line] == '\n')
		len_line++;
	newline_saved = malloc((ft_strclen(line_save, '\0') - len_line) + 1);
	while (newline_saved[i] && line_save[i + len_line])
	{
		newline_saved[i] = line_save[i + len_line];
		i++;
	}
	free(line_save);
	return (newline_saved);
}

char	*get_next_line(int fd)
{
	static char *line_save;
	char		*line;
	int			bytes_read;

	bytes_read = 1;
	line = NULL;
	if (!line_save)
		line_save = malloc(1);
	line_save = ft_line_save(line_save, fd, &bytes_read);
	if (!line_save)
		return (NULL);
	line = line_to_print(line_save);
	line_save = newline_save(line_save, ft_strclen(line, '\0'));
	return (line);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	return (0);
}