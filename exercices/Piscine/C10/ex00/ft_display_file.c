/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:43:05 by locagnio          #+#    #+#             */
/*   Updated: 2024/10/04 11:41:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int		fd;
	char	buff[20000];
	int		nb_read;
	int		i;

	i = 0;
	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
		{
			write(2, "Cannot read file\n", 18);
			return (1);
		}
		nb_read = read(fd, buff, sizeof(buff));
		if (nb_read < 0)
		{
			write(2, "Cannot read file\n", 18);
			return (1);
		}
		while (buff[i])
			write(1, &buff[i++], 1);
		close(fd);
	}
	return (0);
}
