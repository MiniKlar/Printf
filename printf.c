/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:36:50 by lomont            #+#    #+#             */
/*   Updated: 2024/12/10 02:47:39 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int ft_multiplication(int n, ...)
{
	int	i;
	int sum;
	sum = 1;

	i = 0;
	va_list ptr;
	va_start(ptr, n);
	while (i < n)
	{
		sum *= va_arg(ptr, int);
		i++;
	}
	
	return (sum);
}

int	ft_printf(const char *string, ...)
{
	int	i;
	//int counter;

	i = 0;
	//counter = 2;
	// while (string[i] != '\0')
	// {
	// 	if (string[i] == '%' && string[i + 1] != '%')
	// 		counter++;
	// 	i++;
	// }
	i = 0;
	va_list ptr;
	va_start(ptr, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%' && string[i + 1] == 'd')
		{
			ft_putnbr_fd(va_arg(ptr, int), 1);
			i += 2;
		}
		if (string[i] == '%' && string[i + 1] == 'i')
		{
			ft_putnbr_fd(va_arg(ptr, int), 1);
			i += 2;
		}
		if (string[i] == '%' && string[i + 1] == 's')
		{
			ft_putstr_fd(va_arg(ptr, char *), 1);
			i += 2;
		}
		if (string[i] == '%' && string[i + 1] == 'c')
		{
			ft_putchar_fd(va_arg(ptr, int), 1);
			i += 2;
		}
		if (string[i] == '%' && string[i + 1] == 'u')
		{
			ft_putunsigned_fd(va_arg(ptr, unsigned int), 1);
			i += 2;
		}
		if (string[i] == '%' && string[i + 1] == '%')
		{
			ft_putchar_fd('%', 1);
			i += 2;
		}
		if (string[i] == '%' && string[i + 1] == 'x')
		{
			ft_putchar_fd('%', 1);
			i += 2;
		}
		else
		{
			write(1, &string[i], 1);
			i++;
		}
	}
	va_end(ptr);
	return (i);
}

int main(void)
{
	// int	i;
	// int *ptr;

	// i = 42;
	// ptr = &i;
	//ft_printf("La multiplication de 4 * 5 est : %d et %s et %c \n", ft_multiplication(2, 4, 1), "SALUT", 'p');
	//printf("La multiplication de 4 * 5 est : %d et %s et %c\n", ft_multiplication(2, 4, 1), "SALUT", 'p');
	ft_printf("Salut %d tu vas bien %%\n", 30);
	printf("Salut %d tu vas bien %%\n", 30);
}
