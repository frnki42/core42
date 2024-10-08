#include <unistd.h>

int ft_putstr(char *str)
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
