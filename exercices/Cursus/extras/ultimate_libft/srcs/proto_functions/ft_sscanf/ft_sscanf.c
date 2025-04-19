/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sscanf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 01:29:23 by marvin            #+#    #+#             */
/*   Updated: 2025/04/19 03:29:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultimate_libft.h"

static void	assign_base(void *type_var, char type, t_sscanf *v)
{
	char	*str_nb;
	char	*conv_nb;
	int		len_nb;

	if (!type_var)
		return ;
	v->output++;
	if ((type == 'x' && !ft_strncmp(v->src + v->i, "0x", 2))
		|| (type == 'X' && !ft_strncmp(v->src + v->i, "0X", 2)))
		v->i += 2;
	else if (type == 'o' && v->src[v->i] == '0')
		v->i++;
	len_nb = ft_len_nb(v->src + v->i, v->end_arg);
	str_nb = ft_strndup(v->src + v->i, len_nb);
	v->i += len_nb;
	if (type == 'x')
		conv_nb = ft_convert_base(str_nb, "0123456789abcdef", "0123456789");
	else if (type == 'X')
		conv_nb = ft_convert_base(str_nb, "0123456789ABCDEF", "0123456789");
	else
		conv_nb = ft_convert_base(str_nb, "01234567", "0123456789");
	free(str_nb);
	type_var = (void *)ft_atold(conv_nb);
	free(conv_nb);
}

static void	assign_u_int(void *u_int_var, char type, t_sscanf *v)
{
	char	*str_nb;
	int		len_nb;
	long	*nb;

	if (!u_int_var)
		return ;
	if (type == 'i' && !ft_strncmp(v->src + v->i, "0x", 2))
		assign_base(u_int_var, 'x', v);
	else if (type == 'i' && !ft_strncmp(v->src + v->i, "0X", 2))
		assign_base(u_int_var, 'X', v);
	else if (type == 'i' && v->src[v->i] == '0')
		assign_base(u_int_var, '0', v);
	if (type == 'i' && (!ft_strncmp(v->src + v->i, "0x", 2)
			|| !ft_strncmp(v->src + v->i, "0X", 2) || v->src[v->i] == '0'))
		return ;
	v->output++;
	len_nb = ft_len_nb(v->src + v->i, v->end_arg);
	str_nb = ft_strndup(v->src + v->i, len_nb);
	nb = u_int_var;
	if (type == 'u')
		*nb = (unsigned int)ft_atol(str_nb);
	else
		*nb = ft_atoi(str_nb);
	free(str_nb);
	v->i += len_nb;
}

static void	assign_char_str_ptr(void *csp_var, char type, t_sscanf *v)
{
	int		j;
	int		*ptr_var;
	char	*str_var;

	if (!csp_var)
		return ;
	v->output++;
	j = 0;
	str_var = NULL;
	if (type == 'c' || type == 's')
	{
		str_var = (char *)csp_var;
		if (type == 'c')
			*str_var = v->src[v->i++];
		else if (type == 's')
		{
			while (v->i < v->len_src && v->src[v->i] != v->end_arg)
				str_var[j++] = v->src[v->i++];
			str_var[j] = 0;
		}
		return ;
	}
	ptr_var = (int *)csp_var;
	*ptr_var = v->i++;
}

static void	parser(t_sscanf	*v, char type, va_list args, int *j)
{
	if (multi_charcmp(type, "csndiuxXo"))
		(*j)++;
	if (type == 'c' || type == 's')
		assign_char_str_ptr((char *)va_arg(args, char *), type, v);
	else if (type == 'n')
		assign_char_str_ptr((int *)va_arg(args, char *), type, v);
	else if (type == 'd' || type == 'i')
		assign_u_int(va_arg(args, int *), type, v);
	else if (type == 'u')
		assign_u_int(va_arg(args, unsigned int *), type, v);
	else if (type == 'x' || type == 'X' || type == 'o')
		assign_base(va_arg(args, int *), type, v);
}

/**
 * @brief put the arguments contained in src where the string is formated in
 * their respectives arguments.
 * 
 * @param src The string of reference.
 * @param format The formated version of `src`.
 * 
 * @note The valid formats are : */
/**
 * - %c -> character */
/**
 * - %s -> string */
/**
 * - %n -> position of a character */
/**
 * - %d/%i -> signed integer */
/**
 * - %u -> unsigned integer */
/**
 * - %x/%X -> convert hexadecimal into decimal */
/**
 * - %o -> convert octal into decimal
 * 
 * @return The number of characters written.
 */
int	ft_sscanf(const char *src, const char *format, ...)
{
	va_list		args;
	t_sscanf	v;
	int			j;

	if (!src)
		return (0);
	v = (t_sscanf){0};
	(ft_strcpy(v.src, src), j = 0);
	va_start(args, format);
	v.len_src = ft_strlen(src);
	while (v.i < v.len_src && src[v.i])
	{
		if (format[j] == '%')
		{
			v.end_arg = format[j + 2];
			parser(&v, format[j + 1], args, &j);
		}
		j++;
		v.i++;
		while (v.i < v.len_src && src[v.i] != v.end_arg)
			v.i++;
	}
	if (v.i < v.len_src && format[j] && format_not_finished(format, j))
		return (va_end(args), -1);
	return (va_end(args), v.output);
}
