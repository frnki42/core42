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

static int	ft_puthexa(unsigned long n, int count,char specifier)
{
	const char	*str;

	str = "0123456789abcdef";
	if (specifier == 'X')
		str = "0123456789ABCDEF";
	if (n > 15)
		count = ft_puthexa(n / 16, count, specifier);
	count += write(1, &str[n % 16], 1);
	return (count);
}

static int	ft_putptr(unsigned long ptr, int count)
{
	if (ptr == 0)
		return (count += write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	count = ft_puthexa(ptr, count, 'x');
	return (count);
}

static int	ft_putunsigned(unsigned int n, int count)
{
	char	temp;
	
	if(n > 9)
		count = ft_putunsigned(n / 10, count);
	temp = (n % 10) + '0';
	if(write(1, &temp, 1) == -1)
		return (-1);
	count++;
	return (count);	
}

static int	ft_putnbr(int n, int count)
{
	char	temp;
	long	nlong;

	nlong = n;
	if(nlong < 0)
	{
		count += write(1, "-", 1);
		nlong = -nlong;
	}
	if (nlong > 9)
		count = ft_putnbr(nlong / 10, count);
	temp = (nlong % 10) + '0';
	count += write(1, &temp, 1);
	return (count);
}

static int ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
	{
		if (write(1, &str[i++], 1) == -1)
			return (-1);
	}
	return (i);
}

static int ft_putchar(char c)
{
	return (write(1, &c, 1));
}
int	ft_printf(const char *format, ...)
{
	int	i;
	va_list	args;

	i = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				i += ft_putchar((char)va_arg(args, int));
			else if (*format == 's')
				i += ft_putstr(va_arg(args, char *));
			else if (*format == 'd' || *format == 'i')
				i += ft_putnbr(va_arg(args, int), 0);
			else if (*format == 'u')
				i += ft_putunsigned(va_arg(args, unsigned int), 0);
			else if (*format == 'x' || *format == 'X')
				i += ft_puthexa(va_arg(args, unsigned int), 0, *format);
			else if (*format =='p')
				i += ft_putptr(va_arg(args, unsigned long), 0);
			else if (*format == '%')
				i += write(1, "%", 1);
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
	int	i;
	int	j;
	char	*str;
	char	*str2;

	printf("#####TEST:1#####\n");
	printf("     -char-\n");
	i = ft_printf("custom: %%%cty%cwo%c%c\n", '4', 'T', '!', '%');
	j = printf("printf: %%%cty%cwo%c%c\n", '4', 'T', '!', '%');
	ft_printf("custom(i) = %i\n", i);
	printf("printf(j) = %i\n", j);

	printf("#####TEST:2#####\n");
	printf("    -string-\n");
	str = "TEST";
	i = ft_printf("custom: %s\n", str);
	j = printf("printf: %s\n", str);
	ft_printf("custom(i) = %i\n", i);
	printf("printf(j) = %i\n", j);
	str2 = "T%ST M3% PL3453!%";
	i = ft_printf("custom: %s\n", str2);
	j = printf("printf: %s\n", str2);
	ft_printf("custom(i) = %i\n", i);
	printf("printf(j) = %i\n", j);
	
	printf("#####TEST:3#####\n");
	printf("      -int-\n");
	i = ft_printf("custom: %i\n", -2147483647);
	j = printf("printf: %i\n", -2147483647);
	ft_printf("custom(i) = %i\n", i);
	printf("printf(j) = %i\n", j);
	i = ft_printf("custom: %i\n", 2147483647);
	j = printf("printf: %i\n", 2147483647);
	ft_printf("custom = %i\n", i);
	printf("printf = %i\n", j);

	printf("#####TEST:4#####\n");
	printf("   -unsigned-\n");
	i = ft_printf("custom: %u\n", 4294967295);
	j = printf("printf: %u\n", (unsigned int)4294967295);
	ft_printf("custom(i) = %u\n", i);
	printf("printf(j) = %u\n", j);

	printf("#####TEST:5#####\n");
	printf("     -hexa-\n");
	i = ft_printf("custom: %x\n", 42);
	j = printf("printf: %x\n", 42);
	ft_printf("custom(i= = %u\n", i);
	printf("printf(j) = %u\n", j);

	printf("#####TEST:6#####\n");
	printf("   -pointer-   \n");
	str = NULL;
	i = ft_printf("custom: %p\n", str);
	str = NULL;
	j = printf("printf: %p\n", str);
	ft_printf("custom(i) = %u\n", i);
	printf("printf(j) = %u\n", j);
	return (0);
}
