/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:54:13 by nitadros          #+#    #+#             */
/*   Updated: 2024/09/25 23:59:32 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

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

int	count_line_break(char *buff, t_coords *save)
{
	int		i;
	int		count;
	char	*bckp;

	bckp = ft_strdup(buff);
	i = 0;
	count = 0;
	while (buff[i] != '\n')
		i++;
	count++;
	i++;
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			count++;
		}
		else if (!(buff[i] == save[0].empty || buff[i] == save[0].obstacle))
			return (0);
		i++;
	}
	return (count);
}

char	*read_file(char *filename)
{
	char	*buff;
	int		fd;
	int		buffsize;
	int		i;
	int		k;

	i = 0;
	k = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Can't open file.\n", 17);
		return (0);
	}
	buff = malloc(sizeof(char) * 10000000 + 1);
	while (k < 10000001)
		buff[k++] = 0;
	buffsize = read(fd, buff, 10000000);
	close(fd);
	buff[buffsize] = 0;
	return (buff);
}

int	gen_loop(char *buff, char **tab, int i)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			tab[j++][k] = 0;
			i++;
			k = 0;
		}
		if (k == 0 && ft_countlen(buff) >= 0)
			tab[j] = malloc(sizeof(char) * (ft_countlen(buff) + 1));
		tab[j][k++] = buff[i++];
	}
	return (j);
}

char	**gen_tab_of_tab(char *buff, char **tab, t_coords *save, int c)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (!count_line_break2(buff))
		return (0);
	tab = malloc(sizeof(char *) * (count_line_break(buff, save) + 1));
	while (buff[i - 1] != '\n')
		buff++;
	j = gen_loop(buff, tab, i);
	free(tab[j + c]);
	tab[j + c] = 0;
	return (tab);
}
