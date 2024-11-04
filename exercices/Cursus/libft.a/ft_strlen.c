/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:20:21 by locagnio          #+#    #+#             */
/*   Updated: 2024/10/30 18:37:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i - 1);
}

/* #include <stdio.h>

int main(void)
{
	char str[] = "Yeppi";
	int i;

	i = ft_strlen(str);
	printf("%d\n", i);
	return(0);

} */
