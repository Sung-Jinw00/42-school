/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:14:22 by locagnio          #+#    #+#             */
/*   Updated: 2024/12/16 19:48:05 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid_son;

	pid_son = 0;
	if (ac == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid_son = fork();
		
	}
	else
	{
		ft_putstr_fd(RED BOLD"Error : Invalid arguments !\n\n"RESET, 2);
		ft_printf(GREEN BOLD"Please, enter valid arguments like so :\n"RESET);
		ft_printf(CYAN"	./pipex file1 \"cmd1\" \"cmd2\" file2\n"RESET);
	}
	av = NULL;
	return (0);
}
