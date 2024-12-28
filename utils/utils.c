/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:36:43 by lomont            #+#    #+#             */
/*   Updated: 2024/12/28 03:24:04 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"
#include "../headers/libft.h"

int ft_putunsigned_fd(unsigned int n, int fd)
{
	static int counter;

	counter = 0;
	if (n >= 10)
	{
		ft_putunsigned_fd(n / 10, fd);
	}
	counter += ft_printchar_fd((n % 10) + '0', fd);
	return(counter);
}

char *ft_hexadecimal(int n)
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
	else if (n < 0)
	{
		i = 8;
		ft_memset(tmp, 'f', i);
		n *= -1;
		while (n != 0)
		{
			k = n % 16;
			n /= 16;
			tmp[i - 1] = base16[15 - k];
			i--;
		}
		tmp[7] += 1;
	}
	return (tmp);
}

int ft_hexadecimal_lower(int n)
{
	int i;
	int counter;
	char *hexadecimal_lower = ft_hexadecimal(n);
	counter = 0;
	if (n > 0)
	{
		i = ft_strlen(hexadecimal_lower);
		while (i != 0)
		{
			counter += ft_printchar_fd(hexadecimal_lower[i - 1], 1);
			i--;
		}
	}
	else if (n < 0)
	{
		i = 0;
		while (i != 8)
		{
			counter += ft_printchar_fd(hexadecimal_lower[i], 1);
			i++;
		}
	}
	else
		counter += ft_printchar_fd('0', 1);
	return(counter);
}

int ft_hexadecimal_upper(int n)
{
	int i;
	int counter;
	char *hexadecimal_upper = ft_hexadecimal(n);
	counter = 0;
	if (n < 0)
	{
		i = 0;
		while (hexadecimal_upper[i] != '\0')
		{
				if (hexadecimal_upper[i] >= 'a' && hexadecimal_upper[i] <= 'f')
					counter += ft_printchar_fd(ft_toupper(hexadecimal_upper[i]), 1);
				else
					counter += ft_printchar_fd(hexadecimal_upper[i], 1);			
			i++;
		}
	}
	else if (n > 0)
	{
		i = 8;
		while (i != 0)
		{
			if (hexadecimal_upper[i - 1] >= 'a' && hexadecimal_upper[i - 1] <= 'f')
				counter += ft_printchar_fd(ft_toupper(hexadecimal_upper[i - 1]), 1);
			else
				counter += ft_printchar_fd(hexadecimal_upper[i - 1], 1);
			i--;
		}
	}
	else
		counter += ft_printchar_fd('0', 1);
	return(counter);
}

int	ft_printnbr_fd(int n, int fd)
{
	static int counter;
	int count;

	counter = 0;
	count = 0;

	if (n == -2147483648)
	{
		ft_printchar_fd('-', fd);
		ft_printchar_fd('2', fd);
		n = 147483648;
		counter += 2;
	}
	if (n < 0)
	{
		//printf("%s\n", "Hello tu es passe par cette boucle !");
		count += ft_printchar_fd('-', fd);
		counter = count;
		//printf("Ceci est le compteur moins %d\n", counter);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	count += ft_printchar_fd((n % 10) + '0', fd);
	counter += count;
	//printf("Ceci est le compteur %d\n", counter);
	return (counter);
}

int	ft_printstr_fd(char *s, int fd)
{
	int counter;
	counter = 0;
	while (*s)
	{
		write(fd, &*s, 1);
		s++;
		counter++;
	}
	return(counter);
}

int	ft_printchar_fd(char c, int fd)
{
	if (!c)
		return(0);
	write(fd, &c, 1);
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
	counter += ft_printstr_fd("0x", 1);
	//printf("counter : %d\n", counter);
	while (i != 0)
	{
		ft_printchar_fd(hexadecimal_lower[i - 1], 1);
		i--;
		counter++;
	}
	return(counter);
}
