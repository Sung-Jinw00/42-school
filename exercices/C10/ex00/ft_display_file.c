/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:43:05 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/20 11:43:10 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int fd;
	char buf[13];
	int nb_read;
	int count;
	
	if(ac > 1)
	{
		fd = open(av[1], O_WRONLY | O_CREAT);
		if (fd == -1)
			return (1);
		write(fd, "Hello World\n", 13);
		nb_read = -1;
		count = 0;
		while (nb_read != 0)
		{
			nb_read = read(fd, buf, 13);
			if (nb_read == -1)
			{
				write(2, "Cannot read file\n", 18);
				return (1);
			}
			buf[nb_read] = 0;
			count++;
		}
		write(1, &count + 48, count / 10);
		close(fd);
	}
	return (0);
}