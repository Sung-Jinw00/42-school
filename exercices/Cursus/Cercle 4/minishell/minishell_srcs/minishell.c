/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:03:17 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/07 17:29:06 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

sig_atomic_t	g_signal = 0;

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

int	init_env(t_env	**my_env, char **env)
{
	t_env	*tmp;
	int		i;
	char	*shlvl;

	i = 0;
	*my_env = create_cell(ft_strdup(env[i]));
	tmp = *my_env;
	shlvl = NULL;
	while (env[++i])
	{
		tmp->next = create_cell(ft_strdup(env[i]));
		if (!tmp->next)
			return (ft_list_clear(*my_env), 1);
		tmp = tmp->next;
		if (!ft_strncmp("SHLVL=", env[i], 6))
		{
			free(tmp->data);
			shlvl = ft_itoa(ft_atoi(env[i] + 6) + 1);
			tmp->data = ft_strjoin_n_free("SHLVL=", shlvl, 2);
			if (!tmp->data || !tmp->data[6])
				return (ft_list_clear(*my_env), 1);
		}
	}
	return (0);
}

t_minishell	*init_vals(char **env)
{
	t_minishell	*mini;

	mini = ft_calloc(1, sizeof(t_minishell));
	if (!mini)
		return (ft_fprintf(2, "Error : fail init struct\n"), exit(1), NULL);
	if (!env || !ft_strncmp(env[0], "_=", 2))
	{
		sig_init();
		mini->cur_loc = getcwd(NULL, 0);
		init_user(mini);
		return (mini);
	}
	if (init_env(&(mini->env), env))
		return (ft_fprintf(2, "Error : fail copying env\n"), exit(1), NULL);
	mini->env_export = ft_envdup(mini->env);
	ft_env_sort((&mini->env_export));
	sig_init();
	mini->cur_loc = replace_by_tilde(mini->env_export, mini->cur_loc, 0);
	init_user(mini);
	return (mini);
}

char	*toprint(t_minishell *mini, char *cur_loc)
{
	char	*str;

	str = ft_strdup(BOLD GREEN);
	if (mini->user.final)
		str = ft_strjoin_n_free(str, mini->user.final, 1);
	str = multi_join_n_free("0", str, cur_loc, "$ ", RESET, NULL);
	return (str);
}

int	main(int ac, char **av, char **env)
{
	char		*str;
	char		*print;
	t_minishell	*mini;

	print_welcome();
	str = NULL;
	mini = init_vals(env);
	((void)av, signal(SIGQUIT, SIG_IGN));
	while (1)
	{
		print = toprint(mini, mini->cur_loc);
		str = readline(print);
		free(print);
		if (check_quotes(str))
			continue ;
		str = replace_var(mini, str);
		optimised_line(str, &mini);
		if (is_symbols(mini->pipes_redirs, 0)
			|| syntax_error_redir(mini->tokens, mini->pipes_redirs))
			free_all(mini, "tabs");
		if (!mini->tokens || !mini->tokens[0] || mini->tokens[0][0] == 0)
			continue ;
		exec_cmd(mini);
	}
	return (ac * 0);
}
