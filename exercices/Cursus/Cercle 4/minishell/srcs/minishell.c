/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:03:17 by locagnio          #+#    #+#             */
/*   Updated: 2025/02/06 20:58:37 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//le bash doit fonctionner sur bash, pas zsh

t_env	*create_cell(char *data)
{
	t_env	*cell;

	cell = malloc(sizeof(t_env));
	if (!cell)
		return (NULL);
	cell->data = data;
	cell->next = NULL;
	return (cell);
}

void	init_env(t_env	**my_env, char **env)
{
	t_env	*tmp;
	int		i;

	i = 0;
	tmp = *my_env;
	while (env[++i])
	{
		tmp->next = create_cell(ft_strdup(env[i]));
		tmp = tmp->next;
		if (!ft_strncmp("SHLVL=", env[i], 6))
		{
			free(tmp->data);
			tmp->data = ft_strjoin("SHLVL=", ft_itoa(ft_atoi(env[i] + 6) + 1));
		}
	}
}

int main(int ac, char **av, char **env)
{
	char *line;
	t_env	*my_env;
	
	(void)ac;
	(void)av;
	//welcome();
	my_env = create_cell(env[0]);
	init_env(&my_env, env);
	while (1)
	{
		line = readline(YELLOW"minishell> "RESET);
		if (!ft_strcmp(line, ""))
			continue ;
		exec_cmd(line, my_env);
	}
	free(line);
	return (0);
}
