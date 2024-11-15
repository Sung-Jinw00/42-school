/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:18:39 by marvin            #+#    #+#             */
/*   Updated: 2024/10/04 09:18:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTE_TEST_H
# define LISTE_TEST_H

typedef struct s_Cell
{
	int				data;
	struct s_Cell	*next;
}	List,	Cell;

#endif