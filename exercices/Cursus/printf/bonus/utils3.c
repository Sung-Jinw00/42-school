/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:56:47 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/15 22:43:18 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	standard_conds(t_struct v, int i)
{
	if (v.str[i] == 'c' || v.str[i] == 's' || v.str[i] == 'p'
		|| v.str[i] == 'd' || v.str[i] == 'i' || v.str[i] == 'u'
		|| v.str[i] == 'x' || v.str[i] == 'X' || v.str[i] == '%')
		return (1);
	return (0);
}

int	bonus_conds(t_struct v, int i)
{
	if (v.str[i] == '-' || v.str[i] == '0' || v.str[i] == '.'
		|| v.str[i] == '#' || v.str[i] == ' ' || v.str[i] == '+'
		|| (v.str[i] >= '0' && v.str[i] <= '9'))
		return (1);
	return (0);
}

char	bonus_flag_finder(int i, t_struct v)
{
	if (v.str[i] == '-')
		return ('-');
	else if (v.str[i] == '0')
		return ('0');
	else if (v.str[i] == '.')
		return ('.');
	else if (v.str[i] == '#')
		return ('#');
	else if (v.str[i] == ' ')
		return (' ');
	else if (v.str[i] == '+')
		return ('+');
	else
		return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;
	size_t	i;

	if (size != 0 && nmemb > (-1 / size))
		return (NULL);
	tab = (void *)malloc(nmemb * size);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		*(char *)(tab + i) = 0;
		i++;
	}
	return (tab);
}

int	ft_len_field(int i, t_struct v)
{
	int len_val;

	len_val = 0;
	if (v.str[i] == '%' || v.str[i] == 'c')//si c'est un char
		len_val = 1;//len de 1
	else if (v.str[i] == 's' || v.str[i] == 'p' || v.str[i] == 'X'
		|| v.str[i] == 'x')//si c'est une chaine de characteres
		len_val = ft_strlen((const char *)v.arg);//len de la chaine
	else if (v.str[i] == 'd' || v.str[i] == 'i' || v.str[i] == 'u')
	{
		len_val = ft_digits((long long)v.arg);//sinon c'est un nombre, donc le nombre de chiffres que j'ai
		if (ft_strchr(v.flag_order, '+'))//si j'ai un plus avec un chiffre
			len_val++;//je rajoute le signe a la len
	}
	if (v.nb1 > len_val)//si le nombre donne pour le champ est plus grand que la len de ma valeur
	{
		len_val = v.nb1;
		printf("len_field : %d\n", len_val);
		return (len_val);
	}
	else if (ft_strchr(v.flag_order, ' '))//sinon si j'ai un flag espace
		erase_flag(' ', v);//je l'enleve, si y'a pas la place ca annule
	printf("len_field : %d\n", len_val);
	return (len_val);
}
