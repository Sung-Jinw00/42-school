/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:54:13 by nitadros          #+#    #+#             */
/*   Updated: 2024/09/24 22:05:54 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

int	ft_countlen(char *buff)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (buff[i - 1] != '\n')
		i++;
	while (buff[i] != '\n')
	{
		c++;
		i++;
	}
	return (c);
}

int	count_line_break(char *buff)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			count++;
		i++;
	}
	return (count - 1);
}

char	*read_file(char *filename)
{
	char	*buff;
	int		fd;
	int		buffsize;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Can't open file.\n", 17);
		return (0);
	}
	buff = malloc(sizeof(char) * 10000000000 + 1);
	buffsize = read(fd, buff, 10000000000);
	buff[buffsize] = 0;
	return (buff);
}

char	**gen_tab_of_tab(char *buff)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	j = 0;
	k = 0;
	tab = malloc(sizeof(char *) * count_line_break(buff) + 1);
	while(buff[i - 1] != '\n')
		buff++;
	while(buff[i])
	{
		if (buff[i] == '\n')
		{
			tab[j++][k] = 0;
			i++;
			k = 0;
		}
		if (k == 0 && ft_countlen(buff) >= 0)
			tab[j] = malloc(sizeof(char) * ft_countlen(buff) + 1);
		tab[j][k++] = buff[i++];
	}
	tab[j + 1] = 0;
	return (tab);
}
