#include "push_swap.h"

size_t	count_numbers(char *argv)
{
	size_t	amount;
	size_t	number;

	amount = 0;
	number = 0;
	while (*argv)
	{
		if (*argv != ' ' && number == 0)
		{
			number = 1;
			amount++;
		}
		if (*argv == ' ')
			number = 0;
		argv++;
	}
	return (amount);
}

void	check_doubles(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < data->size)
	{
		j = 1 + i;
		while (j < data->size)
		{
			if (data->stack_a[i] == data->stack_a[j++])
				exit_error(data);
		}
		i++;
	}
}

long	ft_atolong(const char *nptr)
{
	int	either;
	int	i;
	long	result;

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
