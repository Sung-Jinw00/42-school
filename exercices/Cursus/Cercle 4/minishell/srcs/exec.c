/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:33:34 by locagnio          #+#    #+#             */
/*   Updated: 2025/02/07 01:21:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_cmd(char *line, t_env *env)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	(void)env;
	if (!ft_strcmp(tokens[0], "pwd"))
		pwd(env);
	else if (!ft_strcmp(tokens[0], "echo", 4))
			echo(line);
	/* else if (!ft_strcmp(tokens[0], "cd"))
		cd(tokens[0]);
	else if (!ft_strcmp(tokens[0], "export"))
		return (1);
	else if (!ft_strcmp(tokens[0], "unset"))
		return (1);*/
	else if (!ft_strcmp(tokens[0], "env"))
		ft_env(env);
	else if (!ft_strcmp(tokens[0], "exit"))
		return (free_dbl_tab(tokens), exit(0));
	else
		ft_fprintf(2, "%s: command not found\n", tokens[0]);
	free_dbl_tab(tokens);
	free(line);
}
