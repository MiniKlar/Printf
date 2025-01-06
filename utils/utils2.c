/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:03:21 by lomont            #+#    #+#             */
/*   Updated: 2025/01/06 02:56:46 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
		ptr[i++] = (unsigned char) c;
	return (s);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c = c - 32;
		return (c);
	}
	else
		return (c);
}
void	ft_putnbr_fd(int n)
{
	if (n == -2147483648)
	{
		ft_printchar('-');
		ft_printchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		ft_printchar('-');
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10);
	ft_printchar((n % 10) + '0');
}