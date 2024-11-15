/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:05:11 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/15 22:46:09 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_string(char *str)
{
	int i;

	i = 0;
	while (str[i])
		str[i++] = 'A';
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	t_struct	v;
	int			count;

	if (!str)
		return (0);
	v.arg = 0;
	v.str = str;
	set_string(v.flag_order);//je met tout a zero
	va_start(args, str);
	v.arg = malloc(8);
	count = print_this_bs(args, v);//je print et retourne le nombre de characteres que j'ai imprimer
	free(v.arg);
	va_end(args);
	return (count);
}

#include <stdio.h>

int main(void)
{
	//printf("original : %d\n", printf("original :   |%%|\n"));
	//printf("copie    : %d\n", ft_printf("copie    :   |%%|\n"));
	printf("original : %d\n", printf("original :   |% s|\n", "Hello world"));
	printf("copie    : %d\n", ft_printf("copie    :   |% s|\n", "Hello world"));
	return (0);
}
