/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:33:34 by locagnio          #+#    #+#             */
/*   Updated: 2025/02/07 17:32:22 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_cmd(char *line, t_minishell *mini)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (!ft_strcmp(tokens[0], "pwd"))
		pwd(mini->env);
	else if (!ft_strncmp(tokens[0], "echo", 4))
			echo(tokens);
	/* else if (!ft_strcmp(tokens[0], "cd"))
		cd(tokens[0]);
	else if (!ft_strcmp(tokens[0], "export"))
		return (1);
	else if (!ft_strcmp(tokens[0], "unset"))
		return (1);*/
	else if (!ft_strcmp(tokens[0], "env"))
		ft_env(mini->env);
	else if (!ft_strcmp(tokens[0], "exit"))
		return (free_dbl_tab(tokens), exit(0));
	else
		ft_fprintf(2, "%s: command not found\n", tokens[0]);
	free_dbl_tab(tokens);
	free(line);
}
