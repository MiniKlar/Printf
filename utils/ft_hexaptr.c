/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:00:45 by lomont            #+#    #+#             */
/*   Updated: 2025/01/08 00:04:01 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_hexaptr(unsigned long address)
{
	char	*base16;
	int		counter;

	base16 = "0123456789abcdef";
	counter = 0;
	if (address >= 16)
		counter += ft_hexaptr((address / 16));
	counter += ft_printchar(base16[address % 16]);
	return (counter);
}

int	ft_print_hexaptr(void *n)
{
	int				counter;
	unsigned long	address;

	address = (unsigned long) n;
	counter = 0;
	if (address == 0)
	{
		write (1, "(nil)", 5);
		return (counter += 5);
	}
	counter += ft_printstr("0x");
	counter += ft_hexaptr(address);
	return (counter);
}
