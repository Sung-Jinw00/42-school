/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:10:05 by locagnio          #+#    #+#             */
/*   Updated: 2025/03/27 20:28:13 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extras.h"

/* return the len of the list
*/
long	len_list(t_list *L)
{
	long	len;

	len = 0;
	while (L)
	{
		len++;
		L = L->next;
	}
	return (len);
}
