/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:39:40 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/01/03 18:50:08 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_character
{
	char	*msg;
	char	character;
	int		curr_bit;
	size_t	byte;
}		t_character;

typedef struct s_arg
{
	size_t	pid;
	char	*msg;
}				t_arg;

void	ft_putnbr(size_t n);
int		ft_atoi(char *str);

#endif
