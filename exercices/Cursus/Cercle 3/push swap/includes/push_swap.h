/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:52:14 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/14 16:52:00 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"
# include "get_next_line_bonus.h"

typedef struct s_list
{
	int				data;
	int				is_min;
	int				is_max;
	struct s_list	*next;
}	t_list,	t_cell;

# define RESET "\033[0m"   //Réinitialisation
# define RED   "\033[31m"   //Couleur rouge

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
void	c_ss(t_list **a_list, t_list **b_list);
void	c_rr(t_list **a_list, t_list **b_list);
void	c_rrr(t_list **a_list, t_list **b_list);
void	c_sa_sb(t_list **list);
void	c_ra_rb(t_list **list);
void	c_rra_rrb(t_list **list);
void	c_pa_pb(t_list **a_list, t_list **b_list, char destination);
//algorythm
t_list	*sort_list(t_list *a_list, t_list *b_list, int len_a_list);
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
void	ft_putstr_fd(char *s, int fd);
int		ft_natoi(const char *nptr, int *i, t_list *a_list);
void	*ft_calloc(size_t nmemb, size_t size);
void	print_action(char *action, char chosen_list);
void	place_b_values(t_list **a_list, t_list *b_list);
void	sort_a(t_list **a_list);
t_list	*r_or_rr(t_list **list, int len_list, int pos, char chosen_list);
void	if_is_max(t_list **a_list, int bigger_nb);
void	if_is_min(t_list **a_list, int smaller_nb);
t_list	*pos_of_value_for_b2(t_list **a_list, t_list *b_list, int bigger_nb);
int		find_lwr_val(t_list *list, int min, int data);
int		sorted_a_list(t_list *a_list);
int		get_at(t_list *L, int pos);
void	final_moves(t_list **a_list, int smaller_nb);

//checker
void	checker(int ac, char **av);
void	check_list(t_list *a_list, t_list *b_list);
int		do_instructions(char *instruction, t_list **a_list, t_list **b_list);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//get_next_line
char	*ft_line_save(char *line_save, int fd);
char	*line_to_print(const char *line_save);
char	*newline_save(char *line_save, int len_line);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strclen(const char *s, char c);

//to print
void	print_list(t_list *list, char *msg);
void	print_vals(t_list *a_list, t_list *b_list);

#endif