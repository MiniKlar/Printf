/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:36:43 by lomont            #+#    #+#             */
/*   Updated: 2024/12/10 02:29:32 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putunsigned_fd(unsigned int n, int fd)
{
	if (n >= 10)
		ft_putunsigned_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}