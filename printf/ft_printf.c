/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 12:21:54 by efembock          #+#    #+#             */
/*   Updated: 2024/10/06 13:02:16 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

static int	ft_atoi(const char *nptr)
{
	int	either;
	int	i;
	int	result;

	either = 1;
	i = 0;
	result = 0;
	while (nptr[i] && (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			either = -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * either);
}
static int	ft_putnbr(int n)
{
	char	temp;
	long	nlong;

	nlong = n;
	if (nlong < 0)
	{
		write(1, "-", 1);
		nlong = -nlong;
	}
	if (nlong > 9)
		ft_putnbr(nlong / 10);
	temp = (nlong % 10) + '0';
	write(1, &temp, 1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				i += write(1, "%", 1);
			else if (*format == 'd' || *format == 'i')
				i += ft_putnbr(ft_atoi(args));
		/*	else if (*format == 'c')
				i += ft_putchar(1, va_arg(args, char), 1);
			else if (*format == 's')
				i += ft_putstr_fd(args, char *);
			else if (*format == 'u')
				i += ft_putunsigned(args, unsigned long);*/
		}
		else
			i += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (i);
}

int	main()
{
	int i;

	i = ft_printf("Test me please!%%\n");
	printf("Test me please!%%%i\n", i);
	return (0);
}
