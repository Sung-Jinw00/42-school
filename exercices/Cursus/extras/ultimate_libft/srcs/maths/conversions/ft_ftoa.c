/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:31:07 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"
/* #include <float.h> */
/* i = LDBL_DIG dans frac_calc */
#ifndef FT_LDBL_DIG
# define FT_LDBL_DIG 18
#endif

static long double	remv_int_float(long double nb)
{
	while (nb > (long double)LLONG_MAX
		|| nb < (long double)LLONG_MIN)
	{
		if (nb > (long double)LLONG_MAX)
			nb -= (long double)LLONG_MAX;
		else if (nb < (long double)LLONG_MIN)
			nb -= (long double)LLONG_MIN;
	}
	nb -= (long long)nb;
	return (nb);
}

/* i = LDBL_DIG pour plus de precision mais pas le droit a float.h */
static void	frac_calc(long double nb, uint64_t *dec_digits, int precision)
{
	long double	dec_part;

	dec_part = remv_int_float(nb);
	if (dec_part < 0)
		dec_part = -dec_part;
	if (precision > FT_LDBL_DIG)
		precision = FT_LDBL_DIG;
	while (precision-- > 0)
		dec_part *= 10;
	if ((uint64_t)(dec_part * 10) % 10 >= 5)
		dec_part += 1;
	*dec_digits = (uint64_t)dec_part;
}

static void	init_vals(long double nb, t_ftoa *v)
{
	*v = (t_ftoa){0};
	if (nb < 0)
	{
		nb = -nb;
		v->sign = 1;
	}
	v->int_part = ft_nbdigit(nb, 10) + v->sign;
}

void	write_float(t_ftoa *v, uint64_t base, int nbdigits_ullong_max)
{
	uint64_t	chunk;

	base = 1000000000000000000ULL;
	while (v->int_part > v->sign)
	{
		chunk = (uint64_t)(v->nb - ((uint64_t)(v->nb / base))
				* (long double)base);
		if (chunk == 0 && v->nb > ULLONG_MAX)
		{
			v->nb = (v->nb - (long double)base) / (long double)base;
			nbdigits_ullong_max = 18;
			while (--v->int_part >= v->sign && nbdigits_ullong_max-- > 0)
				v->cpy[v->int_part] = '0';
		}
		else
		{
			v->nb = (v->nb - (long double)chunk) / (long double)base;
			while (v->int_part > v->sign && chunk > 9)
			{
				v->cpy[--v->int_part] = (chunk % 10) + '0';
				chunk /= 10;
			}
			v->cpy[--v->int_part] = (chunk % 10) + '0';
		}
	}
}

/**
 * @brief
 * Transform a float number into a string.
 * 
 * @param n The float value that will be turned into a string.
 * @param precision The number of digits after the coma.*/
/**
 * If precision < 1, no number after the coma will be added,
 * as well as the coma itself. 
 * 
 * @returns
 * - The string version of a float number.
*/
char	*ft_ftoa(long double n, int precision)
{
	t_ftoa		v;

	init_vals(n, &v);
	v.dec_part = precision;
	frac_calc(n, &v.dec_nb, precision);
	v.nb = n - remv_int_float(n);
	if (v.nb < 0)
		v.nb = -v.nb;
	v.cpy = malloc(sizeof(char) * (v.int_part + v.dec_part + 2));
	if (!v.cpy)
		return (NULL);
	ft_memset(v.cpy, '0', v.int_part + v.dec_part + 1);
	if (v.sign == 1)
		v.cpy[0] = '-';
	v.cpy[v.int_part + v.dec_part + 1] = '\0';
	while (v.dec_part > 0)
	{
		v.cpy[v.int_part + v.dec_part--] = (v.dec_nb % 10) + '0';
		v.dec_nb /= 10;
	}
	if (precision > 0)
		v.cpy[v.int_part] = '.';
	write_float(&v, 0, 0);
	return (v.cpy);
}
