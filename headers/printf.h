/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 03:06:04 by lomont            #+#    #+#             */
/*   Updated: 2024/12/28 03:22:16 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printnbr_fd(int n, int fd);
int		ft_printchar_fd(char c, int fd);
int		ft_printstr_fd(char *s, int fd);
int		ft_putunsigned_fd(unsigned int n, int fd);
int 	ft_hexadecimal_lower(int n);
int		ft_hexadecimal_upper(int n);
int 	ft_putptr_fd(void *ptr);
char 	*ft_hexadecimal_ptr(unsigned long n);
#endif