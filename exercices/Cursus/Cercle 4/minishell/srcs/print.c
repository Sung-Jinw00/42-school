/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:17:08 by locagnio          #+#    #+#             */
/*   Updated: 2025/02/02 20:32:48 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	welcome(void)
{
	char	str[] = CYAN ITALIC" Welcome..."RESET CYAN"\n to...\n"BOLD GREEN" MINISHELL !\n\n"RESET;
	int		i;
	int		j;

	i = 0;
	j = 50000000;
	while (str[i])
	{
		write(1, &str[i++], 1);
		if (i == 26 || i == 36)
			j *= 10;
		while (j > 0)
			j--;
		j = 50000000;
	}
}
