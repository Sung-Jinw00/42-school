/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:14:22 by locagnio          #+#    #+#             */
/*   Updated: 2024/12/28 20:27:15 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	usage(void)
{
	ft_putstr_fd(RED BOLD"Error : Invalid arguments !\n\n"RESET, 2);
	ft_printf(BRIGHT_GREEN BOLD"Please, enter valid arguments like so :\n");
	ft_printf(RESET CYAN"	./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2\n");
	ft_printf("	or\n");
	ft_printf("	./pipex here_doc LIMITER cmd cmd1 file\n"RESET);
}

static void	son_program(char *av, char **env, pid_t pid_son)
{
	int		fd[2];

	if (pipe(fd) == -1)
	{
		perror(RED"Error -> issue creating pipe\n"RESET);
		exit(EXIT_FAILURE);
	}
	pid_son = fork();
	if (pid_son == -1)
	{
		perror(RED"Error -> pid failure\n"RESET);
		exit(EXIT_FAILURE);
	}
	if (pid_son == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(av, env);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid_son, NULL, 0);
	}
}

static int	get_file(char *av, int i)
{
	int	file;

	if (i == 0)
		file = open(av, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		file = open(av, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else
		file = open(av, O_RDONLY);
	if (file == -1)
	{
		perror(RED"Error -> cannot open file\n"RESET);
		exit(EXIT_FAILURE);
	}
	return (file);
}

static void	here_doc(char *limiter, int ac)
{
	pid_t	reader;
	int		fd[2];

	if (ac < 6)
		usage();
	if (pipe(fd) == -1)
	{
		perror(RED"Error -> issue creating pipe\n"RESET);
		exit(EXIT_FAILURE);
	}
	reader = fork();
	if (reader == -1)
	{
		perror(RED"Error -> pid failure\n"RESET);
		exit(EXIT_FAILURE);
	}
	if (reader == 0)
		read_stdin(fd, limiter);
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

void	pipex(int ac, char **av, char **env)
{
	int	i;
	int	filein;
	int	fileout;

	if (ac >= 5)
	{
		if (ft_strncmp(av[1], "here_doc", 8) == 0)
		{
			i = 3;
			fileout = get_file(av[ac - 1], 0);
			here_doc(av[2], ac);
		}
		else
		{
			i = 2;
			fileout = get_file(av[ac - 1], 1);
			filein = get_file(av[1], 2);
			dup2(filein, STDIN_FILENO);
		}
		while (i < ac - 2)
			son_program(av[i++], env, 0);
		dup2(fileout, STDOUT_FILENO);
		execute(av[ac - 2], env);
	}
	usage();
}
