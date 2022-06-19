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

int	main(int ac, char **av)
{
	int		pid_ser;
	int		i;
	char	tmp;
	int		j;

	i = 0;
	if (ac == 3)
	{
		pid_ser = ft_atoi(av[1]);
		while (av[2][i])
		{
			tmp = av[2][i];
			j = 7;
			while (j)
			{
				if (tmp >> j & 1)
					kill(pid_ser, SIGUSR1);
				else
					kill(pid_ser, SIGUSR2);
				j--;
				usleep(3000);
			}
			i++;
		}
	}
	return (0);
}
