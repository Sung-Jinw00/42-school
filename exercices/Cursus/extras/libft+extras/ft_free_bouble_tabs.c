/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bouble_tabs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:39:14 by marvin            #+#    #+#             */
/*   Updated: 2025/01/19 15:39:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

char	**ft_free_bouble_tabs(char **split, int j)
{
	while (j >= 0)
		free(split[j--]);
	free(split);
	return (NULL);
}
