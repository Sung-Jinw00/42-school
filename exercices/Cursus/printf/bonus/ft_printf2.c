/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:22:27 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/15 22:39:51 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

/* ecris la reponse en conftion des flags */
void	ft_write_answer(int i, int *count, t_struct v, va_list args)
{
	int j;
	int len_field;

	j = 0;
	v = assign_val(i, v, args);//j'assigne la valeur de ma conditions standard a v.arg
	len_field = ft_len_field(i, v);//je prends la longueur du champ en comparant avec la len de ma valeur
	if (v.str[i] == '%' || (v.str[i] == 'c' && ft_strchr(v.flag_order, '.')))//si j'ai un charactere
	{
		write(1, &*(char *)v.arg, 1);
		*count += 1;
		return ;
	}
	else
	{
		*count += len_field;//j'ajoute la len du champ a count
		ft_write_answer2(i, len_field, v);
	}
}

void	flag_filter(int i, t_struct v)
{
	if (ft_strchr(v.flag_order, '-') && (v.str[i] == 's'))//erase '-'
		erase_flag('-', v);
	if (ft_strchr(v.flag_order, '0') && (v.str[i] == 's'))//erase '0'
		erase_flag('0', v);
	keep_prior_flag('0', '-', v);//erase '0' if '-'
	if (ft_strchr(v.flag_order, '+') && (v.str[i] == 's'
		|| v.str[i] == 'p' || v.str[i] == 'x' || v.str[i] == 'X'))//erase '+'
		erase_flag('+', v);
	if (ft_strchr(v.flag_order, ' ') && (v.str[i] == 's'
		|| v.str[i] == 'x' || v.str[i] == 'X'))//erase ' '
		erase_flag(' ', v);
	keep_prior_flag(' ', '+', v);//erase ' ' if '+'
	if (ft_strchr(v.flag_order, '.') && (v.nb2 == 0 || v.str[i] == 'p'
		|| v.str[i] == 'x' || v.str[i] == 'X'))//erase '.'
		erase_flag('.', v);
	if (ft_strchr(v.flag_order, '#')
		&& !(v.str[i] == 'x' || v.str[i] == 'X'))//erase '#'
		erase_flag('#', v);
}
#include <stdio.h>
/* je remplis mon tableau avec tous les flags que j'ai trouve dans l'ordre et les filtre */
int	parseur(int i, int *count, t_struct v, va_list args)
{
	while(!((v.str[i] >= '1' && v.str[i] <= '9') || standard_conds(v, i)))//tant que je croise pas de chiffres ou de condition standard
	{
		v = fill_parser(bonus_flag_finder(i, v), v);//je rempli le parseur
		i += 1;
	}
	if (v.str[i] >= '1' && v.str[i] <= '9')
		v.nb1 = ft_atoi((const char *)v.str + i);//je prends la longueur du champ
	while (v.str[i] >= '0' && v.str[i] <= '9')
		i += 1;
	if (v.str[i] == '.')//si j'ai un point
	{
		v = fill_parser(bonus_flag_finder(i++, v), v);//je rempli le parseur
		v.nb2 = ft_atoi((const char *)v.str + i);//je prends la precision que donne le point
		while (v.str[i] >= '0' && v.str[i] <= '9')
			i += 1;
	}
	flag_filter(i, v);//je filtre les flags
	ft_write_answer(i, count, v, args);
	return (i);
}

/* je choisis si j'affiche avec les conditions standards ou avec les bonus */
int	print_this_bs(va_list args, t_struct v)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (v.str[i])
	{
		if (v.str[i] == '%' && standard_conds(v, i + 1))//conditions standards
			ft_redpill(++i, &count, v, args);
		else if (v.str[i] == '%' && bonus_conds(v, i + 1))//conditions bonus
			i = parseur(i + 1, &count, v, args);
		else//sinon je print normalement
		{
			write(1, &v.str[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}
