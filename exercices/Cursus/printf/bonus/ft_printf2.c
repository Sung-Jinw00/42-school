/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:22:27 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/15 02:28:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bonus_solving(int i, int *count, t_struct v, va_list args);

void	ft_bonus_space(int i, int *count, t_struct v, va_list args)
{
	write (1, " ", 1);
	*count += 1;
	while (v.str[i] == ' ')
		i++;
	if (standard_conds(v, i + 1))
		ft_redpill(++i, &count, v, args);
	else if (bonus_conds(v, i + 1))
		ft_bonus_solving(i, count, v, args);
}

t_struct fill_parser(char c, t_struct v)
{
	int i;

	i = 0;
	if (!c)
		return (v);
	while (i < 6)
	{
		if (c == v.flag_order[i])
			break ;
		else if (v.flag_order[i] == 0)
		{
			v.flag_order[i] = c;
			break ;
		}
		i++;
	}
	return (v);
}

void	keep_prior_flag(char erased, char prior, t_struct v)
{
	int j;
	int save;

	j = 0;
	save = 0;
	while (v.flag_order[j])
	{
		if (v.flag_order[j] == erased || v.flag_order[j] == prior)
			save = j++;
		if (v.flag_order[j] == erased || v.flag_order[j] == prior)
		{
			if (v.flag_order[save] == erased)
				j = save;
			while (v.flag_order[j] != '\0')
			{
				v.flag_order[j] = v.flag_order[j + 1];
				j++;
			}
			break ;
		}
		j++;
	}
}

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	erase_flag(char erased, t_struct v)
{
	int j;
	int save;

	j = 0;
	save = 0;
	while (v.flag_order[j])
	{
		if (v.flag_order[j] == erased)
		{
			while (v.flag_order[j] != '\0')
			{
				v.flag_order[j] = v.flag_order[j + 1];
				j++;
			}
			break ;
		}
		j++;
	}
}

void	ft_write_answer(int i, int *count, t_struct v, va_list args)
{
	int j;
	char *str;

	j = 0;
	str = 0;
}

void	flag_filter(int i, t_struct v)
{
	if (ft_strchr(v.flag_order, '-') && (v.str[i] == 's'))//erase '-'
		erase_flag('-', v);
	if (ft_strchr(v.flag_order, '0') && (v.str[i] == 's'))//erase '0'
		erase_flag('0', v);
	keep_prior_flag('0', '-', v);//erase '0' if '-'
	if (ft_strchr(v.flag_order, '+') && (v.nb < 0 || v.str[i] == 's'
		|| v.str[i] == 'p' || v.str[i] == 'x' || v.str[i] == 'X'))//erase '+'
		erase_flag('+', v);
	if (ft_strchr(v.flag_order, ' ') && (v.nb < 0 || v.str[i] == 's'
		|| v.str[i] == 'd' || v.str[i] == 'i' || v.str[i] == 'x'
		|| v.str[i] == 'X'))//erase ' '
		erase_flag(' ', v);
	keep_prior_flag(' ', '+', v);//erase ' ' if '+'
	if (ft_strchr(v.flag_order, '.') && v.nb == 0)//erase '.'
		erase_flag('.', v);
	if (ft_strchr(v.flag_order, '#')
		&& !(v.str[i] == 'x' || v.str[i] == 'X'))//erase '#'
		erase_flag('#', v);
}

void	parseur(int i, int *count, t_struct v, va_list args)
{
	while(!((v.str[i] >= '1' || v.str[i] <= '9') || standard_conds(v, i)))
	{
		v = fill_parser(bonus_flag_finder(i, v), v);
		i++;
	}
	if (v.str[i] >= '1' || v.str[i] <= '9')
		v.nb = ft_atoi((const char *)v.str + i);
	while (v.str[i] >= '1' || v.str[i] <= '9')
		i++;
	flag_filter(i, v);
	ft_write_answer(i, count, v, args);
}

int	print_this_bs(va_list args, t_struct v)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (v.str[i])
	{
		if (v.str[i] == '%' && standard_conds(v, i + 1))
			ft_redpill(++i, &count, v, args);
		else if (v.str[i] == '%' && bonus_conds(v, i + 1))
			ft_bonus_solving(++i, &count, v, args);
		else
		{
			write(1, &v.str[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}
