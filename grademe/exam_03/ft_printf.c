#include <stdarg.h>
#include <unistd.h>

int	ft_puthexa(unsigned int num, int count)
{
	char	*base;

	if (num == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (++count);
	}
	base = "0123456789abcdef";
	if (num > 15)
		count = ft_puthexa(num / 16, count);
	if (write(1, &base[num % 16], 1) == -1)
		return (-1);
	return (++count);
}

int	ft_putnbr(int num)
{
	char	digits[11];
	int	amount;
	int	i;

	if (num == 0)
		return (write(1, "0", 1));
	if (num == -2147483648)
		return (write(1, "-2147483648", 11));
	amount = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		amount++;
	}
	i = 0;
	while (num > 0)
	{
		digits[i++] = (num % 10) + '0';
		num /= 10;
	}
	while (i > 0)
	{
		write(1, &digits[--i], 1);
		amount++;
	}
	return (amount);
}

int	ft_putstr(char *str)
{
	int	amount;

	if (!str)
		return (write(1, "(null)", 6));
	amount = 0;
	while (*str)
	{
		if (write(1, str++, 1) == -1)
			return (-1);
		amount++;
	}
	return (amount);
}

int	handle_format(const char *format, va_list args)
{
	if (*format == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (*format == 'd')
		return (ft_putnbr(va_arg(args, int)));
	if (*format == 'x')
		return (ft_puthexa(va_arg(args, unsigned int), 0));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	amount;
	int	tmp;

	if (!format)
		return (-1);
	va_start(args, format);
	amount = 0;
	while (*format)
	{
		if (*format == '%')
		{
			tmp = handle_format(++format, args);
			if (tmp == -1)
				return (va_end(args), -1);
			amount += tmp;
		}
		else if (write(1, format, 1) == -1)
			return (va_end(args), -1);
		else
			amount++;
		format++;
	}
	va_end(args);
	return (amount);
}
