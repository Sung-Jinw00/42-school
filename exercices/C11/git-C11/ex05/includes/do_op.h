/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:48:59 by locagnio          #+#    #+#             */
/*   Updated: 2024/09/22 17:32:25 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>

void		ft_add(char *s1, char *s2);
void		ft_sub(char *s1, char *s2);
void		ft_mult(char *s1, char *s2);
void		ft_div(char *s1, char *s2);
void		ft_mod(char *s1, char *s2);
void		ft_putstr(char *str);
long long	mini_atoi(char *str);
void		ft_putstr(char *str);
void		ft_putnbr(long long n);

#endif