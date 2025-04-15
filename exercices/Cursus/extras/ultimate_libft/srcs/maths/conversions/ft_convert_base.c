/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:58:28 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

static void	error_msg(char *msg)
{
	ft_putstr_fd(2, msg);
}

static int	ft_error(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if ((int)ft_strlen(base) <= 1)
		return (error_msg(RED"Error : invalid base\n"RESET), 1);
	if (base[i] == ' ' || base[i] == '-' || base[i] == '+'
		|| (base[i] >= 9 && base[i] <= 13))
		return (error_msg(RED"Error : white spaces in base\n"RESET), 1);
	while (i <= (int)ft_strlen(base))
	{
		while (j <= (int)ft_strlen(base))
		{
			if (base[i] == base[j])
				return (error_msg(RED"Error : duplicates in base\n"RESET), 1);
			if (base[j] == ' ' || base[j] == '-' || base[j] == '+'
				|| (base[j] >= 9 && base[j] <= 13))
				return (error_msg(RED"Error : white spaces in base\n"RESET), 1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

/**
 * @brief
 * Transform a string of numbers in a certain base into another string of
 * numbers in another base.
 * 
 * @returns
 * - If the bases are invalid, it returns NULL.*/
/**
 * - Else, it returns the integer version of a string of numbers.
*/
char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (!ft_error(base_from) && !ft_error(base_to))
		return (ft_itoa_base(ft_atoi_base(nbr, base_from), base_to));
	return (NULL);
}

/* #include <stdio.h>

int	main(void)
{
	printf("nombre attendu : 0\n\tretour : %s\n\n", ft_convert_base("0",\
	 "0123456789", "0123456789ABCDEF"));
	printf("nombre attendu : 9\n\tretour : %s\n\n", ft_convert_base("9",\
	 "0123456789", "0123456789ABCDEF"));
	printf("nombre attendu : -9\n\tretour : %s\n\n", ft_convert_base("-9",\
	 "0123456789", "0123456789ABCDEF"));
	printf("nombre attendu : D\n\tretour : %s\n\n", ft_convert_base("13",\
	 "0123456789", "0123456789ABCDEF"));
	printf("nombre attendu : -F\n\tretour : %s\n\n", ft_convert_base("-15",\
	 "0123456789", "0123456789ABCDEF"));
	printf("nombre attendu : 1FBC\n\tretour : %s\n\n", ft_convert_base("8124",\
	 "0123456789", "0123456789ABCDEF"));
	return (0);
} */
