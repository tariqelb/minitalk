/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:57:34 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/01/06 17:53:05 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_character	g_chr = {NULL, 0, 0, 0, 0};

void	ft_my_strcpy(char *temp)
{
	size_t	i;

	g_chr.msg = (char *) malloc(sizeof(char) * (g_chr.byte + 2));
	if (g_chr.msg == NULL)
	{
		write(2, "Allocation error\n", 17);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (temp[i])
	{
		g_chr.msg[i] = temp[i];
		i++;
	}
	g_chr.msg[i] = 0;
}

void	ft_concat_msg(void)
{
	char	*temp;
	size_t	i;

	temp = NULL;
	temp = (char *) malloc(sizeof(char) * (g_chr.byte + 2));
	if (temp == NULL)
	{
		write(2, "Allocation error\n", 17);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < g_chr.byte)
	{
		temp[i] = g_chr.msg[i];
		i++;
	}
	temp[i++] = g_chr.character;
	temp[i] = 0;
	free(g_chr.msg);
	ft_my_strcpy(temp);
	free(temp);
	g_chr.byte++;
}

void	ft_add_to_msg(void)
{
	g_chr.msg = (char *) malloc(sizeof(char) * 2);
	if (g_chr.msg == NULL)
	{
		write(2, "Allocation error\n", 17);
		exit(EXIT_FAILURE);
	}
	g_chr.msg[0] = g_chr.character;
	g_chr.msg[1] = 0;
	g_chr.byte++;
}

void	ft_handler(int sig, siginfo_t *info, void *ucontext)
{
	g_chr.pid = info->si_pid;
	(void)ucontext;
	if (sig == SIGUSR2)
		g_chr.character |= (1 << g_chr.curr_bit);
	g_chr.curr_bit++;
	if (g_chr.curr_bit == 8)
	{
		if (g_chr.character == 0)
		{
			write(1, g_chr.msg, g_chr.byte);
			g_chr.byte = 0;
			free(g_chr.msg);
		}
		else if (g_chr.byte == 0)
			ft_add_to_msg();
		else
			ft_concat_msg();
		g_chr.character = 0;
		g_chr.curr_bit = 0;
	}
}

int	main(void)
{
	struct sigaction	act;

	act.sa_sigaction = ft_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
	{
		pause();
		usleep(200);
		kill(g_chr.pid, SIGUSR1);
	}
}
