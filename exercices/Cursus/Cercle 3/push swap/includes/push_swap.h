/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:52:14 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/13 18:12:35 by locagnio         ###   ########.fr       */
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
	int				is_min;
	int				is_max;
	long			max_val;
	int				chunk_level;
	struct s_list	*next;
} t_list, t_cell;

# 	define RESET       "\033[0m"  // Réinitialisation
# 	define RED         "\033[31m"  // Couleur rouge

//main
void	push_swap(int ac, char **av);
//moves
void	ss(t_list **a_list, t_list **b_list);
void	rr(t_list **a_list, t_list **b_list);
void	rrr(t_list **a_list, t_list **b_list);
void	sa_sb(t_list **list, char chosen_list);
void	ra_rb(t_list **list, char chosen_list);
void	rra_rrb(t_list **list, char chosen_list);
void	pa_pb(t_list **a_list, t_list **b_list, char destination);
//algorythm
t_list	*sort_list(t_list *a_list, t_list *b_list, int len_a_list);//
//list creation
t_cell	*create_cell(int data);//
int		find_min(t_list **a_list);//
int		find_max(t_list **a_list);//
t_list	*initiate_a_list(int ac, char **av);//
t_list	*add_at(t_list *L, int data, int pos);//
//error managment
int		duplicates(t_list *list);//
int		check_all_args(char **numbers);//
void	error(char *msg, t_list *a_list);//
//utils
int		is_nb(char c);//
long	len_list(t_list *list);//
t_list	*free_list(t_list *list);//
int		sorted_list_grow(t_list *list);//
void	ft_putstr_fd(char *s, int fd);//
int		ft_natoi(const char *nptr, int *i, t_list *a_list);//
void	*ft_calloc(size_t nmemb, size_t size);//
void	print_action(char *action, char chosen_list);//
void	place_b_values(t_list **a_list, t_list *b_list);//
void	sort_a(t_list **a_list);//
t_list	*r_or_rr(t_list **list, int len_list, int pos);//
void	if_is_max(t_list **a_list, int bigger_nb);//
void	if_is_min(t_list **a_list, int smaller_nb);//
t_list	*pos_of_value_for_b2(t_list **a_list, t_list *b_list, int bigger_nb);//
t_list	*lstdup(t_list *src);//
int		find_lwr_val(t_list *list, int min, int data);//
int		sorted_a_list(t_list *a_list);//
int		get_at(t_list *L, int pos);//

//to print
void	print_list(t_list *list, char *msg);
void	print_vals_and_chunks(t_list *a_list, t_list *b_list);

#endif