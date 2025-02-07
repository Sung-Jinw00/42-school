/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:15:45 by locagnio          #+#    #+#             */
/*   Updated: 2025/02/07 01:01:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	valid_quotes(char *line, bool single_quote, bool double_quote)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (!single_quote && !double_quote)
		{
			if (line[i] == '\'')
				single_quote = 1;
			else if (line[i] == '"')
				double_quote = 1;
		}
		else if (single_quote || double_quote)
		{
			if (single_quote && !double_quote)
				single_quote = 0;
			else if (!single_quote && double_quote)
				double_quote = 0;
		} 
	}
	if (!single_quote && !double_quote)
		return (0);
	return (1);
}

char	**filter_quotes(char **tokens, int i)
{
	char	*line;
	char	*tmp;

	tmp = NULL;
	line = ft_strdup(tokens[i++]);
	while (tokens[i])
	{
		tmp = ft_strjoin(line, " ");
		free(line);
		line = tmp;
		tmp = ft_strjoin(line, tokens[i++]);
		free(line);
		line = tmp;
	}
	if (valid_quotes(line, 0, 0))
	{	
		ft_fprintf(2, RED"Error : quotes aren't closed\n"RESET);
		return (free_dbl_tab(tokens), free(line), exit(0), NULL);
	}
	tmp = ft_remove_from_string(line, "'\"");
	free(line);
	free(tokens);
	tokens = ft_split(tmp, " ");
	free(tmp);
	return (tokens);
}

void	echo(char *line)
{
	int		i;
	bool	slash_n;

	i = 4;
	slash_n = 1;
	while (line[i] == ' ')
		i++;
	if (!ft_strncmp(line + 5, "-n", 2) && (!line[7] || (line[7] == ' ')))
		slash_n = 0;
	tokens = filter_quotes(tokens, i);
	while (tokens[i])
		ft_putstr(tokens[i++]);
	free_dbl_tab(tokens);
}
