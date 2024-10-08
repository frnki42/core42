/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:14:39 by efembock          #+#    #+#             */
/*   Updated: 2024/10/02 10:57:26 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_puthexa(unsigned long n, int count, char specifier);
int	ft_putnbr(int n, int count);
int	ft_putptr(unsigned long ptr, int count);
int	ft_putstr(char *str);
int	ft_putunsigned(unsigned int n, int count);
int	ft_printf(const char *format, ...);
int	ft_format(const char *format, va_list args);

#endif
