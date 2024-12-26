/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:11:55 by locagnio          #+#    #+#             */
/*   Updated: 2024/12/26 18:40:12 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	read_stdin(int *fd, char *limiter)
{
	char	*line;

	close(fd[0]);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& line[ft_strlen(limiter)] == '\n')
			exit(EXIT_SUCCESS);
		write(fd[1], line, ft_strlen(line));
		line = get_next_line(STDIN_FILENO);
	}
}

void	free_dbl_tab(char **str)
{
	int	j;

	j = 0;
	while (str[j])
		free(str[j++]);
	free(str);
}

int	ft_strnchr(const char *s, const char *to_find, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] && i < len)
	{
		while (s[i + j] == to_find[j] && i + j < len)
		{
			j++;
			if (to_find[j] == 0)
				return (1);
		}
		i++;
		j = 0;
	}
	return (0);
}

char	*find_path(char *cmd, char **env)
{
	int		i;
	char	**paths;
	char	*possible_path;
	char	*path;

	i = 0;
	while (env[i] && ft_strnchr(env[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(env[i] + 5, ':');
	if (!paths)
		perror(RED"Error -> invalid path\n"RESET);
	i = 0;
	while (paths[i])
	{
		possible_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(possible_path, cmd);
		free(possible_path);
		if (access(path, F_OK) == 0 || access(path, X_OK) == 0)
			return (free_dbl_tab(paths), path);
		free(path);
		i++;
	}
	free_dbl_tab(paths);
	return (0);
}

void	execute(char *av, char **env)
{
	char	*path;
	char	**cmd;

	cmd = ft_split(av, ' ');
	if (!cmd)
	{
		perror(RED"Error -> issue spliting command\n"RESET);
		exit(EXIT_FAILURE);
	}
	path = find_path(cmd[0], env);
	if (!path)
	{
		free_dbl_tab(cmd);
		perror(RED"Error -> issue finding path\n"RESET);
		exit(EXIT_FAILURE);
	}
	if (execve(path, cmd, env) == -1)
	{
		free(path);
		free_dbl_tab(cmd);
		perror(RED"Error -> execution failure\n"RESET);
		exit(EXIT_FAILURE);
	}
	free(path);
	free_dbl_tab(cmd);
}
