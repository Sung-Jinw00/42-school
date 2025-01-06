/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:52:11 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/06 21:22:57 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

	/* intervertit les 2 premiers elements du sommet de la liste */
	void	sa_sb(t_list **list);
	/* intervertit les 2 premiers elements du sommet des deux listes */
	void	ss(t_list **list_a, t_list **list_b);
	/* prend le premier element d'une liste et l'integre a l'autre liste comme premier element */
	void	pa_pb(t_list **list_a, t_list **list_b, char index);
	/* decale toutes les valeurs d'une position vers le haut, le premier deviens le dernier */
	void	ra_rb(t_list **list);
	/* decale toutes les valeurs d'une position vers le haut pour les deux listes */
	void	rr(t_list **list_a, t_list **list_b);
	/* decale toutes les valeurs d'une position vers le bas, le dernier deviens le premier */
	void	rra_rrb(t_list **list);
	/* decale toutes les valeurs d'une position vers le bas pour les deux listes */
	void	rrr(t_list **list_a, t_list **list_b);




void	push_swap(int ac, char **av)
{
	t_list *list_a;
	t_list *list_b;

	list_a = initiate_a_list(ac, av);
	list_b = NULL;
	print_list(list_a, "liste a : ");
	pa_pb(&list_a, &list_b, 'b');
	pa_pb(&list_a, &list_b, 'b');
	pa_pb(&list_a, &list_b, 'b');
	print_list(list_a, "\nliste a : ");
	print_list(list_b, "liste b : ");
	rr(&list_a, &list_b);
	print_list(list_a, "\nliste a : ");
	print_list(list_b, "liste b : ");
	rr(&list_a, &list_b);
	print_list(list_a, "\nliste a : ");
	print_list(list_b, "liste b : ");
	free_list(list_a);
	free_list(list_b);
}

int	main(int ac, char **av)
{
	push_swap(ac, av);
	return (0);
}