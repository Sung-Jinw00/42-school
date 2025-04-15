/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:32:27 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

static int	is_valid_double(double result)
{
	if (result != result)
		return (ft_write(2, "ft_atod : number is NaN (Not a Number)\n"), 0);
	else if (result == INFINITY)
		return (ft_write(2, "ft_atod : number is infinity\n"), 0);
	else if (result == -INFINITY)
		return (ft_write(2, "ft_atod : number is -infinity\n"), 0);
	else if (result > FT_DBL_MAX || result < -FT_DBL_MAX)
	{
		ft_write(2, "ft_atod : number is above the limits of a double\n");
		return (0);
	}
	else if (result != 0.0 && result < FT_DBL_MIN && result > -FT_DBL_MIN)
	{
		ft_write(2, "ft_atod : number is below the limits of a double ");
		ft_write(2, "(subnormal)\n");
		return (0);
	}
	return (1);
}

static int	decimal(double *result, char *nptr)
{
	int		i;
	int		divizor;
	double	decimal;

	i = 0;
	divizor = 10;
	decimal = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		decimal = decimal + (double)(nptr[i++] - '0') / divizor;
		divizor *= 10;
	}
	*result += decimal;
	if (!is_valid_double(*result))
		return (1);
	return (0);
}

/**
 * @brief
 * Transform a number in a string into a double.
 * 
 * @returns
 * - If nptr = NULL, or if the casual requirements of
 * atoi aren't respected, the function returns 0.*/
/**
 * - Else, it returns the double version of a string of numbers.
*/
double	ft_atod(char *nptr)
{
	int		i;
	int		sign;
	double	result;

	if (!nptr)
		return (0);
	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign = -sign;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + nptr[i++] - '0';
	if ((nptr[i] == '.' || nptr[i] == ',') && decimal(&result, nptr + i + 1))
		return (0);
	return (result * sign);
}

/* #include <stdio.h>

int	main(void)
{
	const char nptr[] = "   +1234ab567";

	printf("%d\n", ft_atoi(nptr));
	return(0);

} */