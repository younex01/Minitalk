/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 01:38:24 by yelousse          #+#    #+#             */
/*   Updated: 2022/06/17 16:42:39 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigusr1(int sig)
{
	
}

int	main(int ac, char **av)
{
	int	pid_ser;
	struct sigaction	sa;
	sa.sa_handler = &handle_sigusr1;
	sigaction(SIGUSR1, &sa, NULL);
	if (ac == 3)
	{
		pid_ser = ft_atoi(av[1]);
	}
	return (0);
}
