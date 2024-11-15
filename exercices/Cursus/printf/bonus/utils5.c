/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:05:16 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/15 22:24:12 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*new_string;
	size_t		len;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_string = malloc(len);
	if (!new_string)
		return (NULL);
	while (s1[i] != '\0')
	{
		new_string[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		new_string[i++] = s2[j++];
	new_string[i] = '\0';
	return (new_string);
}

void	print_char(t_struct v, int len_field)
{
	int j;

	j = 0;
	if (!ft_strchr(v.flag_order, '-') || ft_strchr(v.flag_order, '0'))
	{
		while (j + 1 < len_field)
		{
			write(1, " ", 1);
			j++;
		}
		write(1, &(*(char *)v.arg), 1);
	}
	else if (ft_strchr(v.flag_order, '-'))
	{
		write(1, &(*(char *)v.arg), 1);
		while (++j < len_field)
			write(1, " ", 1);
	}
}

void	print_string(t_struct v, int len_field)
{
	int j;
	int limit;

	j = 0;
	limit = len_field - (int)ft_strlen((const char *)v.arg);
	if (len_field == (int)ft_strlen((const char *)v.arg))//je met la limite de remplissage de characteres par defaut si j'ai de la marge
		ft_putstr_fd((char *)v.arg, 1);
	else if (!ft_strchr(v.flag_order, '-') || ft_strchr(v.flag_order, '0'))
	{
		/* while (j < limit)
		{
			write(1, " ", 1);
			j++;
		} */
		ft_putstr_fd((char *)v.arg, 1);
	}
	else if (ft_strchr(v.flag_order, '-'))
	{
		ft_putstr_fd((char *)v.arg, 1);
		j = (int)ft_strlen((const char *)v.arg);
		while (j++ <= len_field)
			write(1, " ", 1);
	}
}

static void	print_nb2(t_struct v, int len_field, int len_nb)
{
	int	limit_filling;
	int count;
	int j;

	j = 0;
	count = 0;
	limit_filling = 0;
	if (!ft_strchr(v.flag_order, '-') || ft_strchr(v.flag_order, '0'))
	{
		limit_filling = len_field - len_nb;
		while (j < limit_filling)
		{
			if (ft_strchr(v.flag_order, '0'))
				write(1, "0", 1);
			else
				write(1, " ", 1);
			j++;
		}
		if_plus_or_space(v);
		ft_putnbr_fd(&count, *(long long *)v.arg, 1);
	}
}

void	print_nb(t_struct v, int len_field)
{
	int j;
	int count;
	int len_nb;

	j = 0;
	count = 0;
	len_nb = ft_digits(*(long long *)v.arg);
	if (ft_strchr(v.flag_order, '+') && *(long long *)v.arg <= 0)//si j'ai un '+' je le print
		len_nb++;
	else if (ft_strchr(v.flag_order, ' ') && *(long long *)v.arg < 0)//si j'ai un ' ' je le print
		len_nb++;
	if (len_field == len_nb)//si j'ai ne meme nombre de chiffres que ma len
		ft_putnbr_fd(&count, *(long long *)v.arg, 1);
	else if (!ft_strchr(v.flag_order, '-') || ft_strchr(v.flag_order, '0'))
		print_nb2(v, len_field, len_nb);
	else if (ft_strchr(v.flag_order, '-'))
	{
		if_plus_or_space(v);
		ft_putnbr_fd(&count, *(long long *)v.arg, 1);
		j = len_nb;
		while (j++ < len_field)
			write(1, " ", 1);
	}
}
