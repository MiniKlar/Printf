/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:36:50 by lomont            #+#    #+#             */
/*   Updated: 2024/12/28 03:23:46 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"
#include "../headers/printf.h"

int	ft_printf(const char *string, ...)
{
	int	i;
	int counter;

	counter = 0;
	i = 0;
	va_list ptr;
	va_start(ptr, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%' && string[i + 1] == 'c')
		{
			counter += ft_printchar_fd(va_arg(ptr, int), 1);
			//printf("\nCounter est : %d\n", counter);
			i += 2;
		}
		else if (string[i] == '%' && string[i + 1] == 's')
		{
			counter += ft_printstr_fd(va_arg(ptr, char *), 1);
			//printf("\nCounter est : %d\n", counter);
			i += 2;
		}
		else if (string[i] == '%' && string[i + 1] == 'p')
		{
			counter += ft_putptr_fd(va_arg(ptr, void *));
			//printf("\nCounter est : %d\n", counter);
			i += 2;
		}
		else if (string[i] == '%' && string[i + 1] == 'd')
		{
			counter += ft_printnbr_fd(va_arg(ptr, int), 1);
			//printf("\nCounter est : %d\n", counter);
			i += 2;
		}
		else if (string[i] == '%' && string[i + 1] == 'i')
		{
			counter += ft_printnbr_fd(va_arg(ptr, int), 1);
			//printf("\nCounter est : %d\n", counter);
			i += 2;
		}
		else if (string[i] == '%' && string[i + 1] == 'u')
		{
			counter += ft_putunsigned_fd(va_arg(ptr, unsigned int), 1);
			//printf("\nCounter est : %d\n", counter);
			i += 2;
		}
		else if (string[i] == '%' && string[i + 1] == 'x')
		{
			counter += ft_hexadecimal_lower(va_arg(ptr, int));
			//printf("\nCounter est : %d\n", counter);
			i += 2;
		}
		else if (string[i] == '%' && string[i + 1] == 'X')
		{
			counter += ft_hexadecimal_upper(va_arg(ptr, int));
			//printf("\nCounter est : %d\n", counter);
			i += 2;
		}
		else if (string[i] == '%' && string[i + 1] == '%')
		{
			counter += ft_printchar_fd('%', 1);
			//printf("\nCounter est : %d\n", counter);
			i += 2;
		}
		else
		{
			write(1, &string[i], 1);
			i++;
			counter++;
		}	
	}
	va_end(ptr);
	return (counter);
}

int main(void)
{
	//int i;
	//printf("%d\n",printf("%p%s%c%d\n", &i, "SALUT TU VAS BIEN", 'c', 300));
	//printf("%d\n",ft_printf("%p%s%c%d\n", &i, "SALUT TU VAS BIEN", 'c', 300));
	printf("Nombre de caracteres : %d\n",ft_printf("%% %% %X %X\n", 100, -100));
	printf("Nombre de caracteres : %d\n",printf("%% %% %X %X\n", 100, -100));
}
