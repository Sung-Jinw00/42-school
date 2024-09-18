/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:58:42 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/16 14:49:06 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strclen(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (i);
		i ++;
	}
	return (i);
}

int	ft_error(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (ft_strclen(0, base) <= 1)
		return (0);
	while (i <= ft_strclen(0, base))
	{
		while (j <= ft_strclen(0, base))
		{
			if (base[i] == base[j] || base[i] == ' ' || base[i] == '-'
				|| base[i] == '+' || (base[i] >= 9 && base[i] <= 13))
				return (0);
			if (base[j] == ' ' || base[j] == '-' || base[j] == '+'
				|| (base[j] >= 9 && base[j] <= 13))
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int	ft_check(char str_mark, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (str_mark == base[i])
			return (1);
		i ++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	if (!ft_error(base))
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_check(str[i], base))
	{
		result = result * ft_strclen(0, base) + ft_strclen(str[i], base);
		i++;
	}
	if (result * sign > 2147483647 || result * sign < -2147483648)
		return (0);
	return (result * sign);
}
