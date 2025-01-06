/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:52:14 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/06 21:40:07 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"

typedef struct s_list
{
	int				data;
	struct s_list	*next;
} t_list, t_cell;

# define RESET       "\033[0m"  // Réinitialisation
# define RED         "\033[31m"  // Couleur rouge

void	push_swap(int ac, char **av);
void	sa_sb(t_list **list);
void	ss(t_list **list_a, t_list **list_b);
void	pa_pb(t_list **list_a, t_list **list_b, char index);
void	ra_rb(t_list **list);
void	rr(t_list **list_a, t_list **list_b);
void	rra_rrb(t_list **list);
void	rrr(t_list **list_a, t_list **list_b);
t_cell	*create_cell(int data);
t_list	*add_at(t_list *L, int data, int pos);
int		check_all_args(char **numbers);
t_list	*initiate_a_list(int ac, char **av);

//utils
int		is_nb(char c);
int		ft_natoi(const char *nptr, int *i);
void	ft_putstr_fd(char *s, int fd);
void	print_list(t_list *list, char *msg);
t_list	*free_list(t_list *list);
void	print_action(char *action, char chosen_list);

#endif