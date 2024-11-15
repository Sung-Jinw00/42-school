/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:48:36 by locagnio          #+#    #+#             */
/*   Updated: 2024/10/20 00:18:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	error_peers(void)
{
	write(2, "Les conditions sont invalides\n", 30);
	return (0);
}

int	ft_error_sol(void)
{
	write(2, "aucune, solution trouvee\n", 25);
	return (0);
}
int	ft_error_dupl(void)
{
	write(2, "doublons trouvee\n", 17);
	return (0);
}

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}
