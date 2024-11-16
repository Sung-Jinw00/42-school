/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:36:48 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/16 19:58:42 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_h
# define TESTS_h

# include <stdio.h>

int	ft_printf(const char *str, ...);
void	tests_c(char c);
void	tests_s(char *str);
void	tests_d(int nb);
void	tests_i(int i);
void	tests_u(int ui);
void	tests_x(int x);
void	tests_x_maj(int x_maj);
void	tests_percent(void);

#endif

