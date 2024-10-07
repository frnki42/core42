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

static int	ft_putunsigned(unsigned int n, int count)
{
	char	temp;
	
	if(n > 9)
		count = ft_putunsigned(n / 10, count);
	temp = (n % 10) + '0';
	count += write(1, &temp, 1);
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
		write(1, &str[i++], 1);
	return (i);
}

static int ft_putchar(int i)
{
	char	c;

	c = i;
	write(1, &c, 1);
	return (1);
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
				i += ft_putchar(va_arg(args, int));
			else if (*format == 's')
				i += ft_putstr(va_arg(args, char *));
			else if (*format == 'd' || *format == 'i')
				i += ft_putnbr(va_arg(args, int), 0);
			else if (*format == 'u')
				i += ft_putunsigned(va_arg(args, unsigned int), 0);
			else if (*format == 'x' || *format == 'X')
				i += ft_puthexa(va_arg(args, unsigned int), 0, *format);
			else if (*format =='p')
				i += ft_puthexa(va_arg(args, unsigned long), 0, *format);

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

	printf("-----TEST#1-----\n");
	printf("------char------\n");
	i = ft_printf("%c%c%c%c\n", '4', 'F', 'T', '%');
	j = printf("%c%c%c%c\n", '4', 'F', 'T', '%');
	ft_printf("i = %i\n", i);
	printf("j = %i\n", j);

	printf("-----TEST#2-----\n");
	printf("-----string-----\n");
	str = NULL;
	i = ft_printf("%s\n", str);
	j = printf("%s\n", str);
	ft_printf("i = %i\n", i);
	printf("j = %i\n", j);
	
	printf("-----TEST#3-----\n");
	printf("-------int------\n");
	i = ft_printf("%i\n", -2147483647);
	j = printf("%i\n", -2147483647);
	ft_printf("i = %i\n", i);
	printf("j = %i\n", j);
	i = ft_printf("%i\n", 2147483647);
	j = printf("%i\n", 2147483647);
	ft_printf("i = %i\n", i);
	printf("j = %i\n", j);

	printf("-----TEST#4-----\n");
	printf("----unsigned----\n");
	i = ft_printf("%u\n", 2147483647);
	j = printf("%u\n", 2147483647);
	ft_printf("i = %u\n", i);
	printf("j = %u\n", j);

	printf("-----TEST#5-----\n");
	printf("------hexa------\n");
	i = ft_printf("%x\n", 42);
	j = printf("%x\n", 42);
	ft_printf("i = %u\n", i);
	printf("j = %u\n", j);

	printf("-----TEST#6-----\n");
	printf("----pointer----\n");
	str = "Test!\n";
	i = ft_printf("%p\n", str);
	str = "Test!\n";
	j = printf("%p\n", str);
	ft_printf("i = %u\n", i);
	printf("j = %u\n", j);
	return (0);
}
