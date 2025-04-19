/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_arrint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:46:21 by locagnio          #+#    #+#             */
/*   Updated: 2025/04/15 19:04:46 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

/**
 * @brief
 * Convert an array of characters into an array of int.
 * 
 * @param str_char The sting that will be converted in an array of ints.
 * @param len_arrint The pointer on an int that will receive the len of the
 * array.
 * 
 * @return
 * Returns the converted array of characters, if the string is NULL or empty,
 * the function returns NULL. 
 * 
 * @note The numbers should be separated by at least one non-numeric character.
*/
int	*str_to_arrint(char *str_char, int *len_arrint)
{
	int	i;
	int	j;
	int	*str_int;

	if (len_arrint)
		*len_arrint = ft_arrintlen(str_char);
	if (!str_char || !str_char[0])
		return (NULL);
	str_int = malloc(sizeof(int) * ft_arrintlen(str_char));
	i = 0;
	j = 0;
	while (str_char[i])
	{
		if (ft_isnum(str_char[i]))
			str_int[j++] = ft_natoi(str_char, &i);
		else
			i++;
	}
	return (str_int);
}
