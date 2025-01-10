/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:52:11 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/09 20:49:39 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

	/* intervertit les 2 premiers elements du sommet de la liste */
	void	sa_sb(t_list **list, char chosen_list);
	/* intervertit les 2 premiers elements du sommet des deux listes */
	void	ss(t_list **a_list, t_list **b_list);
	/* prend le premier element d'une liste et l'integre a l'autre liste comme premier element */
	void	pa_pb(t_list **a_list, t_list **b_list, char destination);
	/* decale toutes les valeurs d'une position vers le haut, le premier deviens le dernier */
	void	ra_rb(t_list **list, char chosen_list);
	/* decale toutes les valeurs d'une position vers le haut pour les deux listes */
	void	rr(t_list **a_list, t_list **b_list);
	/* decale toutes les valeurs d'une position vers le bas, le dernier deviens le premier */
	void	rra_rrb(t_list **list, char chosen_list);
	/* decale toutes les valeurs d'une position vers le bas pour les deux listes */
	void	rrr(t_list **a_list, t_list **b_list);

void	push_swap(int ac, char **av)
{
	t_list *a_list;
	t_list *b_list;
	int len_a_list;

	a_list = initiate_a_list(ac, av);
	if (duplicates(a_list))
		error(RED"Error : duplicates !\n"RESET, a_list);
	if (sorted_list(a_list))
	{
		free_list(a_list);
		return ;
	}
	b_list = NULL;
	len_a_list = len_list(a_list);
	//print_list(a_list, "liste a initiale : ");
	a_list = sort_list(a_list, b_list, len_a_list);
	//print_list(a_list, "liste a finale : ");
	free_list(a_list);
	free_list(b_list);
}

int	main(int ac, char **av)
{
	if (ac >= 2)
		push_swap(ac, av);
	return (0);
}
