/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:43:52 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/25 23:48:38 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	check_res(char **res, int limit)
{
	int	i;

	i = 0;
	while (res[i])
		i++;
	if (i != limit)
		return (0);
	return (1);
}

int	print_final(char **res, char *x)
{
	int	j;
	int	limit;

	j = 0;
	limit = catch_param2(x);
	if (!check_res(res, limit))
		return (0);
	while (res[j])
	{
		write(1, &res[j][0], ft_strlen(res[j]));
		if (j < limit)
			write(1, "\n", 1);
		free(res[j++]);
	}
	free(res[j]);
	free(res);
	return (1);
}
