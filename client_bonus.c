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

void	send_byte(int pid, char c)
{
	int	j;

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
