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

void	init_structs(t_data *data)
{
	data->input = NULL;
	data->numbers = NULL;
	data->size = 0;
	data->a = NULL;
	data->b = NULL;
}
