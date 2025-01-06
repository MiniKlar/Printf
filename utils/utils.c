/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:36:43 by lomont            #+#    #+#             */
/*   Updated: 2025/01/06 03:32:56 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int ft_putunsigned(unsigned int n)
{
	static int counter;

	counter = 0;
	if (n >= 10)
		ft_putunsigned(n / 10);
	counter += ft_printchar((n % 10) + '0');
	return(counter);
}

int	ft_printnbr(int n)
{
	int counter;

	counter = 0;
	if (n == -2147483648)
	{
		return (ft_printstr("-2147483648"));
	}
	if (n < 0)
	{
		//printf("%s\n", "Hello tu es passe par cette boucle !");
		counter += ft_printchar('-');
		//printf("Ceci est le compteur moins %d\n", counter);
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
	//printf("Ceci est le compteur %d\n", counter);
	return (counter);
}

int	ft_printstr(char *s)
{
	int counter;
	counter = 0;
	while (*s)
	{
		write(1, &*s, 1);
		s++;
		counter++;
	}
	return(counter);
}

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return(1);
}

char *ft_hexadecimal_ptr(unsigned long n)
{
	char *base16;
	char *tmp = malloc(sizeof (char) * 8);
	int k;
	int i;
	
	base16 ="0123456789abcdef";
	
	if (n > 0)
	{
		i = 0;
		while (n != 0)
		{
			k = n % 16;
			n /= 16;
			tmp[i] = base16[k]; 
			i++;
		}
	}
	return (tmp);
}

int ft_putptr_fd(void *ptr)
{
	int i;
	int counter;
	unsigned long nbr;

	nbr = (unsigned long)ptr;

	char *hexadecimal_lower = ft_hexadecimal_ptr(nbr);
	counter = 0;
	i = 0;
	i = ft_strlen(hexadecimal_lower);
	counter += ft_printstr("0x");
	//printf("counter : %d\n", counter);
	while (i != 0)
	{
		ft_printchar(hexadecimal_lower[i - 1]);
		i--;
		counter++;
	}
	free(hexadecimal_lower);
	return(counter);
}
