/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum_equal_al.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:32:44 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @return
 * True if the argument is an alphanumeric argument.
*/
int	ft_isnum_equal_al(int c)
{
	if (c == '4')
		return ('a');
	else if (c == '8')
		return ('b');
	else if (c == '3')
		return ('e');
	else if (c == '6' || c == '9')
		return ('g');
	else if (c == '1')
		return ('i');
	else if (c == '0')
		return ('o');
	else if (c == '5')
		return ('s');
	else if (c == '7')
		return ('t');
	else if (c == '2')
		return ('z');
	return (c);
}

/*
t = 7
z = 2

} */