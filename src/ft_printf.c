/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:36:50 by lomont            #+#    #+#             */
/*   Updated: 2025/01/08 00:40:28 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	format_handler(va_list ptr, char str)
{
	int	counter;

	counter = 0;
	if (str == 'c')
		counter += ft_printchar(va_arg(ptr, int));
	else if (str == 's')
		counter += ft_printstr(va_arg(ptr, char *));
	else if (str == 'p')
		counter += ft_print_hexaptr(va_arg(ptr, void *));
	else if (str == 'd')
		counter += ft_printnbr(va_arg(ptr, long int));
	else if (str == 'i')
		counter += ft_printnbr(va_arg(ptr, long int));
	else if (str == 'u')
		counter += ft_putunsigned(va_arg(ptr, unsigned int));
	else if (str == 'x')
		counter += ft_puthexa_lower(va_arg(ptr, int));
	else if (str == 'X')
		counter += ft_puthexa_upper(va_arg(ptr, int));
	else if (str == '%')
		counter += ft_printchar('%');
	return (counter);
}

int	ft_printf(const char *string, ...)
{
	int		i;
	int		counter;
	va_list	ptr;

	counter = 0;
	i = 0;
	va_start(ptr, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			counter += format_handler(ptr, string[i + 1]);
			i++;
		}
		else
		{
			write(1, &string[i], 1);
			counter++;
		}
		i++;
	}
	va_end(ptr);
	return (counter);
}
