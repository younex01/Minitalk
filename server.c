/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 01:38:09 by yelousse          #+#    #+#             */
/*   Updated: 2022/06/19 03:26:04 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_pid = 0;

void	reset(char *c, int *shifter, int pid)
{
	*c = 0;
	*shifter = 0;
	g_pid = pid;
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	shifter = 0;

	(void)context;
	if (g_pid != info->si_pid)
		reset(&c, &shifter, info->si_pid);
	if (sig == SIGUSR1)
		c = c << 1 | 1;
	else if (sig == SIGUSR2)
		c = c << 1 | 0;
	shifter++;
	if (shifter == 8)
	{
		write(1, &c, 1);
		c = 0;
		shifter = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_putnbr(pid);
	ft_putstr("\n");
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
