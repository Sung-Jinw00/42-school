/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:00:12 by locagnio          #+#    #+#             */
/*   Updated: 2024/11/04 14:00:12 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFLIBFT_H
# define PRINTFLIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

size_t	ft_strlen(const char *s);
void	ft_putnbr_fd(int n, int fd);
void	ft_putunbr_fd(unsigned int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_itoa_base(int n, const char *base);
int		ft_printf(const char *str, ...);
void	ft_flags(const char *str, int i, void *arg, va_list args);
int		ft_miniatoi(const char *nptr);
void	ft_redpill(const char *str, int i, void *arg, va_list args);

#endif