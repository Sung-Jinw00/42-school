/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:17:08 by locagnio          #+#    #+#             */
/*   Updated: 2025/02/07 01:21:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	welcome(void)
{
	char	str[] = CYAN ITALIC" Welcome..."RESET CYAN"\n to...\n"BOLD GREEN" MINISHELL !\n\n"RESET;
	int		i;
	int		j;

	i = 0;
	j = 50000000;
	while (str[i])
	{
		write(1, &str[i++], 1);
		/* if (i == 26 || i == 36)
			j *= 10; */
		while (j > 0)
			j--;
		j = 50000000;
	}
}

void	error(void)
{
	perror(RED "Error ");
	exit(EXIT_FAILURE);
}

void	ft_print_dlb_tabs(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		printf("%s\n", tab[i++]);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
