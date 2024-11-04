/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:48:36 by locagnio          #+#    #+#             */
/*   Updated: 2024/10/22 09:15:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r01boxs.h"

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

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}
