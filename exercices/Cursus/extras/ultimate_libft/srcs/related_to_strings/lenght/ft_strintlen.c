/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strintlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:33:59 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/18 10:34:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @return
 * The len of str_char that will be turned in a string of int.
*/
int	ft_arrintlen(char *str_char)
{
	int	i;
	int	len;
	int	trigger;

	if (!str_char)
		return (0);
	i = 0;
	len = 0;
	trigger = 0;
	while (str_char[i])
	{
		if (ft_isnum(str_char[i]) && !trigger)
		{
			len++;
			trigger = 1;
		}
		else if (!ft_isnum(str_char[i]) && trigger)
			trigger = 0;
		i++;
	}
	return (len);
}

/* #include <stdio.h>

int	main(void)
{
	char str[] = "Yeppi";

	printf("%zu\n", ft_strlen(str));
	return(0);
} */
