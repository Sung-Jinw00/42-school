/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:12:21 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/22 23:14:40 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_reallocstr(char *ptr, size_t size)
{
	char	*resized;
	int		i;

	if (!ptr)
		return (malloc(size));
	resized = malloc(size);
	i = 0;
	while (ptr[i])
	{
		resized[i] = ptr[i];
		i++;
	}
	resized[i] = '\0';
	free(ptr);
	return (resized);
}

int	ft_readfile(char *filename, char **buffer)
{
	int		fd;
	int		len;
	int		i;

	*buffer = malloc(BUFFER_SIZE + 1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	len = read(fd, *buffer, BUFFER_SIZE);
	*(*buffer + BUFFER_SIZE) = '\0';
	i = 1;
	while (len == BUFFER_SIZE)
	{
		*buffer = ft_reallocstr(*buffer, BUFFER_SIZE * i + len + 1);
		len = read(fd, *buffer + BUFFER_SIZE * (i - 1) + len, BUFFER_SIZE);
		*(*buffer + BUFFER_SIZE * i++ + len) = '\0';
	}
	close(fd);
	if (len == -1)
		return (0);
	return (1);
}

int	ft_atoa(char *str)
{
	int	i;
	int	j;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (free(str), 1);
		i++;
	}
	j = 0;
	while (str[i] >= '0' && str[i] <= '9')
		str[j++] = str[i++];
	if (!j)
		return (free(str), 0);
	str[j] = '\0';
	return (1);
}

char	*ft_trim(char *str)
{
	int	i;
	int	j;
	int	k;
	int	pos;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] && str[i] == 32)
		i++;
	while (str[i] && str[i] != 32)
		str[j++] = str[i++];
	pos = i - 1;
	k = i;
	while (str[i])
	{
		if (str[i] != 32)
			pos = i;
		i++;
	}
	while (k <= pos)
		str[j++] = str[k++];
	str[j] = '\0';
	return (str);
}

int	parse_dict(char *dict_name, char **parsed)
{
	char	*dict;
	char	**lines;
	char	**tmp;
	int		i;

	ft_readfile(dict_name, &dict);
	lines = ft_split(dict, "\n");
	free(dict);
	i = 0;
	while (lines[i / 2])
	{
		tmp = ft_split_once(lines[i / 2], ":");
		free(lines[i / 2]);
		if (!ft_atoa(tmp[0]) || !ft_str_is_printable(ft_trim(tmp[1])))
			return (free(lines), parsed[i] = 0, 0);
		parsed[i] = tmp[0];
		parsed[i + 1] = tmp[1];
		i += 2;
		free(tmp);
	}
	parsed[i] = 0;
	free(lines);
	return (1);
}
