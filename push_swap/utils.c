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
