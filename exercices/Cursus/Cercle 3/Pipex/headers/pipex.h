/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:16:53 by locagnio          #+#    #+#             */
/*   Updated: 2024/12/16 19:20:55 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

////////////////////////////// [Colors/Policy] ////////////////////////////////
# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define CYAN "\033[36m"
# define RESET "\033[0m"

# define BOLD "\033[1m"

///////////////////////////////// [Headers] ///////////////////////////////////
# include "ft_printf.h"
# include "libft.h"
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>

//////////////////////////////// [Functions] //////////////////////////////////
int	main(int ac, char **av);

#endif