/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:52:14 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/09 16:50:09 by locagnio         ###   ########.fr       */
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
int		sorted_list(t_list *list);
int		unsorted_grow(t_list *a_list);
void	ft_putstr_fd(char *s, int fd);
char	*bases_sorted_way(t_list *list);
int		ft_natoi(const char *nptr, int *i, t_list *a_list);
void	print_list(t_list *list, char *msg);
void	print_action(char *action, char chosen_list);
void	*ft_calloc(size_t nmemb, size_t size);
int		chunk_check(t_list *list, int first_chunk, int sec_chunk);
int		pos_of_highest_value_in_chunk(t_list *b_list, int chunk);

void	print_vals_and_chunks(t_list *a_list, t_list *b_list);

#endif