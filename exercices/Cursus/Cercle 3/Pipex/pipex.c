/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:14:22 by locagnio          #+#    #+#             */
/*   Updated: 2024/12/26 18:38:05 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	son_program(char **av, char **env, int *fd)
{
	int	fd_son;

	fd_son = open(av[1], O_RDONLY);
	if (!fd_son)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(fd_son, STDIN_FILENO);
	close(fd[0]);
	execute(av[2], env);
	close(fd_son);
}

void	dad_program(char **av, char **env, int *fd)
{
	int	fd_dad;

	fd_dad = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (!fd_dad)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(fd_dad, STDOUT_FILENO);
	close(fd[1]);
	execute(av[3], env);
	close(fd_dad);
}

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	pid_son;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid_son = fork();
		if (pid_son == -1)
			error();
		if (pid_son == 0)
			son_program(av, env, fd);
		else
		{
			waitpid(pid_son, NULL, 0);
			dad_program(av, env, fd);
		}
	}
	else
	{
		ft_putstr_fd(RED BOLD "Error : Invalid arguments !\n\n" RESET, 2);
		ft_printf(BRIGHT_GREEN BOLD "Please,
			enter valid arguments like so :\n");
		ft_printf(RESET CYAN "	./pipex file1 \"cmd1\" \"cmd2\" file2\n" RESET);
	}
	return (0);
}
