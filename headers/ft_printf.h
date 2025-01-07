/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 03:06:04 by lomont            #+#    #+#             */
/*   Updated: 2025/01/07 23:58:47 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *string, ...);
int		ft_printnbr(int n);
int		ft_printchar(char c);
int		ft_printstr(char *s);
int		ft_putunsigned(unsigned int n);
int		ft_puthexa_upper(unsigned int n);
int		ft_puthexa_lower(unsigned int n);
int		ft_print_hexaptr(void *n);
int		ft_hexaptr(unsigned long address);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlen(const char *s);
int		ft_toupper(int c);
void	ft_putnbr_fd(int n);

#endif