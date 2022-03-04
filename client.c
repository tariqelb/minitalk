/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:36:49 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/01/06 18:20:48 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_isdigit(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] >= '0' && str[index] <= '9')
			index++;
		else
			return (0);
	}
	return (1);
}

void	ft_send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(200);
		bit++;
	}
}

void	ft_send_msg(t_arg *args)
{
	int	i;

	i = 0;
	while (args->msg[i])
	{
		ft_send_char(args->pid, args->msg[i]);
		i++;
	}
	ft_send_char(args->pid, args->msg[i]);
}

int	main(int ac, char **av)
{
	t_arg	args;

	if (ac != 3 || ft_isdigit(av[1]) == 0)
	{
		write(2, "invalid arguments\n", 18);
		return (1);
	}
	args.pid = ft_atoi(av[1]);
	if (args.pid == 0)
	{
		write(2, "invalid arguments\n", 18);
		return (1);
	}
	args.msg = av[2];
	ft_send_msg(&args);
	return (0);
}
