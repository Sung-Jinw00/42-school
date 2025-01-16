/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:31:45 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/04 13:31:45 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void f(unsigned int i, char *s)
{
	unsigned int	i;

	if (*s >= 'A' && *s <= 'Z')
		*s += 32;
	else if (*s >= 'a' && *s <= 'z')
		*s -= 32;
	else
		i = 1;
	if (i == 1)
		return ;
} */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/* #include<stdio.h>

int	main(void)
{
	char s[12] = "Hello world";

	ft_striteri(s, *f);
	printf("%s\n", s);
	return (0);
} */
