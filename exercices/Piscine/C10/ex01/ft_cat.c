/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:43:05 by locagnio          #+#    #+#             */
/*   Updated: 2024/10/16 17:39:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_display(int fd)
{
	char buffer;

	buffer = 0;
	while (read(fd, &buffer, 1) > 0)
		write(1, &buffer, 1);
	if (read(fd, &buffer, 1) < 0)
		write(2, "Error while reading file.\n", 26);
}

void	ft_cat(int argc, char **argv)
{
	int i;
	int fd;

	i = 0;
	if (argc < 2)
		ft_display(0);
	else
		while (++i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd < 0)
			{
				write(2, "ft_cat: ", 8);
				while (*(argv[i]))
					write(2, (argv[i])++, 1);
				write(2, ": No such file or directory\n", 28);
			}
			else
				ft_display(fd);
			close(fd);
		}
}

int		main(int argc, char **argv)
{
	ft_cat(argc, argv);
	return 0;
}