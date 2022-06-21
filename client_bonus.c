/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 01:38:24 by yelousse          #+#    #+#             */
/*   Updated: 2022/06/19 03:46:51 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// void	handler(int sig, siginfo_t *info, void *context)

// struct sigaction	sa;
// sa.sa_sigaction = &handler;
// 	sa.sa_flags = SA_SIGINFO;
// 	sigaction(SIGUSR1, &sa, NULL);
// 	sigaction(SIGUSR2, &sa, NULL);

// void	handle_sigusr1(int sig)
// {
// }

void	send_byte(int pid, char c)
{
	int j;

	j = 7;
	while (j >= 0)
	{
		if (c >> j & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		j--;
		usleep(800);
	}
}

void	handler(int sig)
{
	if (sig == SIGUSR2)
		ft_putstr("Done✅\n");
}

int	main(int ac, char **av)
{
	int		pid_ser;
	int		i;

	i = 0;
	signal(SIGUSR2, handler);
	if (ac == 3)
	{
		pid_ser = ft_atoi(av[1]);
		while (av[2][i])
		{
			send_byte(pid_ser, av[2][i]);
			i++;
		}
		send_byte(pid_ser, 0);
	}
	return (0);
}
