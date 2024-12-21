/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:14:22 by locagnio          #+#    #+#             */
/*   Updated: 2024/12/21 20:17:08 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	son_program(char **argv, char **envp, int *fd)
{
	int	file_desc;

	file_desc = open(argv[1], O_RDONLY, 0777);
	if (file_desc == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(file_desc, STDIN_FILENO);
	close(fd[0]);
	execute(argv[2], envp);
}

void	dad_program(char **argv, char **envp, int *fd)
{
	int	file_desc;

	file_desc = open(argv[4], O_RDONLY | O_CREAT | O_TRUNC, 0777);
	if (file_desc == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(file_desc, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}

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
		if (pid_son == -1)
			error();
		if (pid_son == 0)
			son_program(av, envp, fd);
		waitpid(pid_son, NULL, 0);
		dad_program(av, envp, fd);
	}
	else
	{
		ft_putstr_fd(RED BOLD"Error : Invalid arguments !\n\n"RESET, 2);
		ft_printf(BRIGHT_GREEN BOLD"Please, enter valid arguments like so :\n");
		ft_printf(RESET CYAN"	./pipex file1 \"cmd1\" \"cmd2\" file2\n"RESET);
	}
	av = NULL;
	return (0);
}
