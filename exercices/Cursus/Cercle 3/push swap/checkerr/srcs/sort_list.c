/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:20:51 by locagnio          #+#    #+#             */
/*   Updated: 2025/01/13 23:35:15 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int do_instructions(char *instruction, t_list **a_list, t_list **b_list)
{
	if (!ft_strncmp(instruction, "sa\n", 4))
		c_sa_sb(a_list);
	else if (!ft_strncmp(instruction, "sb\n", 4))
		c_sa_sb(b_list);
	else if (!ft_strncmp(instruction, "ss\n", 4))
		c_ss(a_list, b_list);
	else if (!ft_strncmp(instruction, "pa\n", 4))
		c_pa_pb(a_list, b_list, 'a');
	else if (!ft_strncmp(instruction, "pb\n", 4))
		c_pa_pb(a_list, b_list, 'b');
	else if (!ft_strncmp(instruction, "ra\n", 4))
		c_ra_rb(a_list);
	else if (!ft_strncmp(instruction, "rb\n", 4))
		c_ra_rb(b_list);
	else if (!ft_strncmp(instruction, "rr\n", 4))
		c_rr(a_list, b_list);
	else if (!ft_strncmp(instruction, "rra\n", 5))
		c_rra_rrb(a_list);
	else if (!ft_strncmp(instruction, "rrb\n", 5))
		c_rra_rrb(b_list);
	else if (!ft_strncmp(instruction, "rrr\n", 5))
		c_rrr(a_list, b_list);
	return (1);
}

void	c_error(char *msg, t_list *a_list, t_list *b_list)
{
	free_list(a_list);
	free_list(b_list);
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int valid_instruction(char *instruction, t_list *a_list, t_list *b_list)
{
	if (!ft_strncmp(instruction, "sa\n", 4))
		return (1);
	else if (!ft_strncmp(instruction, "sb\n", 4))
		return (1);
	else if (!ft_strncmp(instruction, "ss\n", 4))
		return (1);
	else if (!ft_strncmp(instruction, "pa\n", 4))
		return (1);
	else if (!ft_strncmp(instruction, "pb\n", 4))
		return (1);
	else if (!ft_strncmp(instruction, "ra\n", 4))
		return (1);
	else if (!ft_strncmp(instruction, "rb\n", 4))
		return (1);
	else if (!ft_strncmp(instruction, "rr\n", 4))
		return (1);
	else if (!ft_strncmp(instruction, "rra\n", 5))
		return (1);
	else if (!ft_strncmp(instruction, "rrb\n", 5))
		return (1);
	else if (!ft_strncmp(instruction, "rrr\n", 5))
		return (1);
	c_error(RED"Error : Invalid instruction !\n"RESET, a_list, b_list);
	return (0);
}

void	check_list(t_list *a_list, t_list *b_list)
{
	char *instruction;

	instruction = get_next_line(0);
	while (instruction[0] != '\n')
	{
		if (valid_instruction(instruction, a_list, b_list))
			do_instructions(instruction, &a_list, &b_list);
		instruction = get_next_line(0);
		if (!instruction)
			break ;
	}
	if (b_list)
	{
		ft_printf("KO\n");
		free_list(a_list);
		return ;
	}
	if (sorted_a_list(a_list))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_list(a_list);
	free_list(b_list);
}
