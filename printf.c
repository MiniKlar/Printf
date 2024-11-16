/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 03:15:27 by lomont            #+#    #+#             */
/*   Updated: 2024/11/16 03:38:21 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	ft_printf(int n, ...)
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
	va_end(ptr);
	return (sum);
}

int main(void)
{
	printf("La multiplication de 4 * 5 est : %d\n",ft_printf(2, 4, 5, 2));
	printf("La multiplication de 2 * 2 est : %d\n",ft_printf(4, 2, 2, 2));
	printf("La multiplication de 4 * 50 est : %d\n",ft_printf(3, 4, 50, 2));
}