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

void	fill_stack(t_data *data)
{
	size_t	i;

	data->a = (t_stack *)malloc(sizeof(t_stack) * data->size);
	if (!data->a)
		exit_error(data);
	i = 0;
	while (i < data->size)
	{
		data->a[i].num = (int)data->numbers[i];
		if (!i)
			data->a[i].prev = NULL;
		else
			data->a[i].prev = &data->a[i - 1];
		if (i == data->size - 1)
			data->a[i].next = &data->a[0];
		else
			data->a[i].next = &data->a[i + 1];
		i++;
	}
	data->a[0].prev = &data->a[i - 1];
}

void	init_structs(t_data *data)
{
	data->size = 0;
	data->input = NULL;
	data->numbers = NULL;
	data->a = NULL;
	data->b = NULL;
}
