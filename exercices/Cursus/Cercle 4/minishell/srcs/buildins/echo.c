/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:15:45 by locagnio          #+#    #+#             */
/*   Updated: 2025/02/06 20:03:27 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	echo(char	**args)
{
	if (!ft_strcmp(args[0], "echo") && !args[1])
	{
		ft_fprintf(2, "/usr/bin/echo: /usr/bin/echo: cannot execute binary");
		ft_fprintf(2, " file\n");
	}
	free_dbl_tab(args);
}
