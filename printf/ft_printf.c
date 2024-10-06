#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	int i;
	va_list args;

	i= 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				i += write(1, "%", 1);
		/*	else if (*format == 'c')
				i += ft_putchar(1, va_arg(args, char), 1);
			else if (*format == 's')
				i += ft_putstr_fd(args, char *);
			else if (*format == 'd' || format == 'i')
				i += ft_putnbr_fd(args, int);
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

	i = ft_printf("%%HI\n");
	printf("%i %%HI\n", i);
	return (0);
}
