/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:36:43 by lomont            #+#    #+#             */
/*   Updated: 2025/01/08 00:08:25 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	static int	counter;

	counter = 0;
	if (n >= 10)
		ft_putunsigned(n / 10);
	counter += ft_printchar((n % 10) + '0');
	return (counter);
}

int	ft_printnbr(int n)
{
	int	counter;

	counter = 0;
	if (n == -2147483648)
	{
		return (ft_printstr("-2147483648"));
	}
	if (n < 0)
	{
		counter += ft_printchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		counter += ft_printnbr(n / 10);
		counter += ft_printchar((n % 10) + '0');
	}
	else
	{
		counter += ft_printchar(n + '0');
	}
	return (counter);
}

int	ft_printstr(char *s)
{
	int	counter;

	counter = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		return (counter += 6);
	}
	while (*s)
	{
		write(1, &*s, 1);
		s++;
		counter++;
	}
	return (counter);
}

int	ft_printchar(char c)
{
	write (1, &c, 1);
	return (1);
}
