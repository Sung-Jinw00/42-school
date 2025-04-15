/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:31:07 by locagnio          #+#    #+#             */
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

static int	init_vals(long nb, int *sign, char *base)
{
	int	i;
	int	digits;

	i = 0;
	digits = 1;
	if (nb < 0)
	{
		nb = -nb;
		*sign = 1;
	}
	while (nb >= (int)ft_strlen(base))
	{
		nb /= (int)ft_strlen(base);
		digits++;
	}
	i = digits + *sign;
	return (i);
}

/**
 * @brief
 * Transform an integer into a string in a certain base.
 * 
 * @returns
 * - If the base is invalid, it returns NULL.*/
/**
 * - Else, it returns the integer version of a string of numbers.
*/
char	*ft_itoa_base(int n, char *base)
{
	char	*cpy;
	long	nb;
	int		i;
	int		sign;

	if (ft_error(base))
		return (NULL);
	nb = n;
	sign = 0;
	i = init_vals(nb, &sign, base);
	if (nb < 0)
		nb = -nb;
	cpy = malloc(sizeof(char) * i + 1);
	if (!cpy)
		return (NULL);
	if (sign == 1)
		cpy[0] = '-';
	cpy[i--] = '\0';
	while (i >= sign)
	{
		cpy[i--] = base[nb % (int)ft_strlen(base)];
		nb /= (int)ft_strlen(base);
	}
	return (cpy);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("nombre attendu : 0\n\tretour : %s\n\n", ft_itoa_base(0,\
	 "0123456789ABCDEF"));
	printf("nombre attendu : 9\n\tretour : %s\n\n", ft_itoa_base(9,\
	 "0123456789ABCDEF"));
	printf("nombre attendu : -9\n\tretour : %s\n\n", ft_itoa_base(-9,\
	 "0123456789ABCDEF"));
	printf("nombre attendu : D\n\tretour : %s\n\n", ft_itoa_base(13,\
	 "0123456789ABCDEF"));
	printf("nombre attendu : -F\n\tretour : %s\n\n", ft_itoa_base(-15,\
	 "0123456789ABCDEF"));
	printf("nombre attendu : 1FBC\n\tretour : %s\n\n", ft_itoa_base(8124,\
	 "0123456789ABCDEF"));
	return (0);
} */