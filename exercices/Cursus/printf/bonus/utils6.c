/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:16:31 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/15 22:20:41 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*if_hashtag(t_struct v, int i)
{
	if (ft_strchr(v.flag_order, '#') && v.str[i] == 'X')
		ft_strjoin("0X", (char const *)v.arg);
	else if (ft_strchr(v.flag_order, '#') && v.str[i] == 'x')
		ft_strjoin("0x", (char const *)v.arg);
	return ((char *)v.arg);
}

void	if_plus_or_space(t_struct v)
{
	if (ft_strchr(v.flag_order, '+') && *(long long *)v.arg <= 0)//si j'ai un '+' je le print
		write (1, "+", 1);
	else if (ft_strchr(v.flag_order, ' ') && *(long long *)v.arg < 0)//si j'ai un ' ' je le print
		write(1, " ", 1);
}


void	ft_write_answer2(int i, int len_field, t_struct v)
{
	if (v.str[i] == '%' || v.str[i] == 'c')//si j'ai un charactere
			print_char(v, len_field);
	else if (v.str[i] == 's' || v.str[i] == 'p' || v.str[i] == 'x'
		|| v.str[i] == 'X')
		print_string(v, len_field);
	else
	{
		if (*(long long *)v.arg <= 0 && ft_strchr(v.flag_order, '+'))
			erase_flag('+', v);
		else if (*(long long *)v.arg < 0 && ft_strchr(v.flag_order, ' '))
			erase_flag(' ', v);
		print_nb(v, len_field);
	}
}
