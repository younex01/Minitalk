/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:20:53 by yelousse          #+#    #+#             */
/*   Updated: 2022/06/17 15:20:56 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_putnbr(int n)
{
	char	c;
	long	nb;
	int		len;

	len = 0;
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
		len++;
	}
	if (nb <= 9)
	{
		c = nb + 48;
		len += ft_putchar(c);
	}
	if (nb > 9)
	{
		len += ft_putnbr(nb / 10);
		c = (nb % 10) + 48;
		len += ft_putchar(c);
	}
	return (len);
}
