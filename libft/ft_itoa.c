/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:25:10 by miniklar          #+#    #+#             */
/*   Updated: 2024/11/12 22:24:33 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_negative(long n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

static int	count_digit(long n)
{
	int	counter;

	counter = 0;
	if (n < 0)
		n = -n;
	if (n == 0)
		counter++;
	while (n != 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len_n;
	size_t	i;
	int		neg;
	long	n1;

	n1 = n;
	neg = is_negative(n1);
	len_n = count_digit(n1) + neg;
	str = malloc(sizeof(char) * (len_n + 1));
	if (!str)
		return (NULL);
	i = len_n;
	if (neg == 1)
		n1 = n1 * -1;
	while (i-- != 0)
	{
		str[i] = (n1 % 10) + '0';
		n1 /= 10;
	}
	if (neg == 1)
		str[0] = '-';
	str[len_n] = 0;
	return (str);
}
/*int	main(void)
{
	char *str;

	str = ft_itoa(-10004);
	printf("%s\n", str);
}*/
