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
	if(write(1, &str[n % 16], 1) == -1)
		return (-1);
	return (++count);
}

static int	ft_putptr(unsigned long ptr, int count)
{
	if (ptr == 0)
		return (count += write(1, "(nil)", 5));
	if(write(1, "0x", 2) == -1)
			return (-1);
	return (ft_puthexa(ptr, count + 2, 'x'));
}

static int	ft_putunsigned(unsigned int n, int count)
{
	char	temp;
	
	if(n > 9)
		count = ft_putunsigned(n / 10, count);
	temp = (n % 10) + '0';
	if(write(1, &temp, 1) == -1)
		return (-1);
	return (++count);	
}

static int	ft_putnbr(int n, int count)
{
	char	temp;
	long	nlong;

	nlong = n;
	if(nlong < 0)
	{
		if(write(1, "-", 1) == -1)
			return (-1);
		count++;
		nlong = -nlong;
	}
	if (nlong > 9)
		count = ft_putnbr(nlong / 10, count);
	temp = (nlong % 10) + '0';
	if(write(1, &temp, 1) == -1)
		return (-1);
	return (++count);
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

static int	ft_format(const char *format, va_list args)
{
	int	i;
	
	i = 0;
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
	{
		if(write(1, "%", 1) == -1)
			return (-1);
		return (1);
	}
	else
		return (-1);
	return (i);
}
int	ft_printf(const char *format, ...)
{
	int	counter;
	int	result;
	va_list	args;

	counter = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			result = ft_format(format, args);
			if (result == -1)
				return (-1);
			counter += result;
		}
		else
		{
			if(write(1, format, 1) == -1)
				return (-1);
			counter++;
		}
		format++;
	}
	va_end(args);
	return (counter);
}
/*
int	main()
{
	int	i;
	int	j;
	char	*str;
	char	*str2;

	printf("#####TEST:1#####\n");
	printf("     -char-\n");
	i = ft_printf("%%%cty%cwo%c%c", '4', 'T', '!', '%');
	printf("\n");
	j = printf("%%%cty%cwo%c%c", '4', 'T', '!', '%');
	printf("\n");
	ft_printf("custom(i) = %i\n", i);
	printf("printf(j) = %i\n", j);

	printf("#####TEST:2#####\n");
	printf("    -string-\n");
	str = "TEST";
	i = ft_printf("%s", str);
	printf("\n");
	j = printf("%s", str);
	printf("\n");
	ft_printf("custom(i) = %i\n", i);
	printf("printf(j) = %i\n", j);
	str2 = "T%ST M3% PL3453!%";
	i = ft_printf("%s", str2);
	printf("\n");
	j = printf("%s", str2);
	printf("\n");
	ft_printf("custom(i) = %i\n", i);
	printf("printf(j) = %i\n", j);
	
	printf("#####TEST:3#####\n");
	printf("      -int-\n");
	i = ft_printf("%i", -2147483647);
	printf("\n");
	j = printf("%i", -2147483647);
	printf("\n");
	ft_printf("custom(i) = %i\n", i);
	printf("printf(j) = %i\n", j);
	i = ft_printf("%i", 2147483647);
	printf("\n");
	j = printf("%i", 2147483647);
	printf("\n");
	ft_printf("custom(i) = %i\n", i);
	printf("printf(j) = %i\n", j);

	printf("#####TEST:4#####\n");
	printf("   -unsigned-\n");
	i = ft_printf("%u", 4294967295);
	printf("\n");
	j = printf("%u", (unsigned int)4294967295);
	printf("\n");
	ft_printf("custom(i) = %u\n", i);
	printf("printf(j) = %u\n", j);

	printf("#####TEST:5#####\n");
	printf("     -hexa-\n");
	i = ft_printf("%x", 42);
	printf("\n");
	j = printf("%x", 42);
	printf("\n");
	ft_printf("custom(i) = %u\n", i);
	printf("printf(j) = %u\n", j);
	i = ft_printf("%x", 4242);
	printf("\n");
	j = printf("%x", 4242);
	printf("\n");
	ft_printf("custom(i) = %u\n", i);
	printf("printf(j) = %u\n", j);

	printf("#####TEST:6#####\n");
	printf("   -pointer-   \n");
	str = NULL;
	i = ft_printf("%p", str);
	printf("\n");
	str = NULL;
	j = printf("%p", str);
	printf("\n");
	ft_printf("custom(i) = %u\n", i);
	printf("printf(j) = %u\n", j);
	str = ".fourtyTWO";
	i = ft_printf("%p", str);
	printf("\n");
	j = printf("%p", str);
	printf("\n");
	ft_printf("custom(i) = %u\n", i);
	printf("printf(j) = %u\n", j);

	return (0);
}*/
