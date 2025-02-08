/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:02:45 by locagnio          #+#    #+#             */
/*   Updated: 2025/02/08 14:54:47 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*cpy;
	int		len_src;
	int		i;

	i = 0;
	len_src = ft_strlen(src);
	cpy = (char *)malloc(sizeof(char) * (len_src + 1));
	if (!cpy)
		return (NULL);
	while (src[i] != '\0')
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

int	count_line_break2(char *buff)
{
	int		i;
	int		count;
	char	*bckp;

	bckp = ft_strdup(buff);
	i = 0;
	count = 0;
	while (buff[i] != '\n')
		i++;
	while (buff[i])
	{
		if (buff[i] == '\n')
			count++;
		i++;
	}
	return (count - 1);
}

char	*read_syscall(void)
{
	int		i;
	int		buffersize;
	char	*buffer;

	i = 0;
	buffer = malloc(sizeof(char) * 10000001);
	while (i < 10000001)
		buffer[i++] = 0;
	buffersize = read(STDIN_FILENO, buffer, i);
	if (buffersize > 0)
		buffer[buffersize - 1] = '\0';
	return (buffer);
}
