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
				return (-1);
			amount += tmp;
		}
		else if (write(1, format, 1) == -1)
			return (-1);
		else
			amount++;
		format++;
	}
	va_end(args);
	return (amount);
}
