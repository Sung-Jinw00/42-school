/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:03:17 by locagnio          #+#    #+#             */
/*   Updated: 2025/02/02 20:46:38 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//le bash doit fonctionner sur bash, pas zsh

int main(int ac, char **av, char **env)
{
	char *prompt;
	
	(void)ac;
	(void)av;
	(void)env;
	//welcome();
	prompt = readline(YELLOW"minishell> "RESET);
	if (prompt)
	{
			add_history(prompt);
			printf("%s\n", prompt);
			/* if (ft_strcmp(prompt, "exit"))
				break ; */
	}
	free(prompt);
	return (0);
}