/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 02:46:55 by lomont            #+#    #+#             */
/*   Updated: 2025/01/06 03:03:14 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int ft_puthexa_lower(unsigned int n)
{
	char *base16;
	int counter;
	
	counter = 0;
	base16 ="0123456789abcdef";
	if (n >= 16)
		ft_puthexa_lower(n / 16);
	counter += ft_printchar(base16[n % 16]);

	return (counter);
}

int ft_puthexa_upper(unsigned int n)
{
	char *base16;
	int counter;
	
	counter = 0;
	base16 ="0123456789ABCDEF";
	if (n >= 16)
		ft_puthexa_upper(n / 16);
	counter += ft_printchar(base16[16 - (n % 16)]);

	return (counter);
}