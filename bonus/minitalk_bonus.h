/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:03:06 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/01/06 00:45:47 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

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
	int		pid;
}				t_character;

typedef struct s_arg
{
	size_t	pid;
	char	*msg;
}				t_arg;

void	ft_putnbr(size_t n);
int		ft_atoi(char *str);

#endif
