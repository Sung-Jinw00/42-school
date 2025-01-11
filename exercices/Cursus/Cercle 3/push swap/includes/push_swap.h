/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:52:14 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/12 00:48:24 by marvin           ###   ########.fr       */
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
t_list	*sort_list(t_list *a_list, t_list *b_list, int len_a_list);
void	chunk_list(double min, double max, t_list **a_list, double ratio);
//list creation
t_cell	*create_cell(int data);
int		find_min(t_list **a_list);
int		find_max(t_list **a_list);
t_list	*initiate_a_list(int ac, char **av);
t_list	*add_at(t_list *L, int data, int pos);
//error managment
int		duplicates(t_list *list);
int		check_all_args(char **numbers);
void	error(char *msg, t_list *a_list);
//utils
int		is_nb(char c);
long	len_list(t_list *list);
t_list	*free_list(t_list *list);
int		sorted_list_grow(t_list *list);
int		sorted_list_degrow(t_list *list);
int		unsorted_grow(t_list *a_list);
void	ft_putstr_fd(char *s, int fd);
char	*bases_sorted_way(t_list *list);
int		ft_natoi(const char *nptr, int *i, t_list *a_list);
void	*ft_calloc(size_t nmemb, size_t size);
int		chunk_check(t_list *list, int first_chunk, int sec_chunk);
int		pos_of_highest_value_in_chunk(t_list *b_list, int chunk);
void	connext_last_and_first_val(t_list **a_list);
void	print_action(char *action, char chosen_list);
void	pos_of_value_for_b(t_list **a_list, t_list *b_list);
int		last_3_bnrs(t_list *a_list);
void	sort_a(t_list **a_list);
t_list	*r_or_rr(t_list **list, int len_list, int pos);
void	if_is_max(t_list **a_list, int bigger_nb);
void	if_is_min(t_list **a_list, int smaller_nb);
t_list	*pos_of_value_for_b2(t_list **a_list, t_list *b_list, int bigger_nb);
t_list	*ft_listdup(t_list *src);
int		find_a_value(t_list *list, int min_or_max, int data, char *smaller_or_bigger);

//to print
void	print_list(t_list *list, char *msg);
void	print_vals_and_chunks(t_list *a_list, t_list *b_list);

#endif