/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:52:51 by marvin            #+#    #+#             */
/*   Updated: 2024/10/30 18:52:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int				i;
	char			*new_str;
	unsigned int	max_len;

	new_str = malloc(len + 1);
	max_len = start + (unsigned int)len;
	i = 0;
	while (start < max_len && s[start])
		new_str[i++] = s[start++];
	new_str[i] = '\0';
	return (new_str);
}
