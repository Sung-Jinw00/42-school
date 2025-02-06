/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:33:34 by locagnio          #+#    #+#             */
/*   Updated: 2025/02/06 21:00:23 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_cmd(char *line, t_env	*env)
{
	(void)env;
	if (!ft_strcmp(line, "pwd"))
		pwd(env);
	/* if (!ft_strcmp(line, "echo"))
		return (1);
	else if (!ft_strcmp(line, "cd"))
		cd(line);
	else if (!ft_strcmp(line, "export"))
		return (1);
	else if (!ft_strcmp(line, "unset"))
		return (1);*/
	else if (!ft_strcmp(line, "env"))
		ft_env(env);
	else if (!ft_strcmp(line, "exit"))
		return (free(line), exit(0));
	else
	{
		ft_fprintf(2, "bash: ");
		ft_putcstr_fd(line, 2, ' ');
		ft_fprintf(2, ": No such file or directory\n");
	}
	free(line);
}
