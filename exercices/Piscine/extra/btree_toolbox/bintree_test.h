/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bintree_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:18:39 by marvin            #+#    #+#             */
/*   Updated: 2024/10/04 09:18:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINTREE_TEST_H
# define BINTREE_TEST_H

typedef struct Node
{
	int				data;
	struct Node		*left;
	struct Node		*right;
}	BinTree,	Node;

#endif