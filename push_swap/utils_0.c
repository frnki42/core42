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

void	is_sorted(t_data *data)
{
	t_stack	*ptr;
	int	i;

	ptr = NULL;
	i = 0;
	ptr = data->a;
	while (ptr->next)
	{
		if (ptr->num > ptr->next->num)
			i = 1;
		ptr = ptr->next;
	}
	if (!i)
		exit_clean(data);
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

void	fill_stack_a(t_data *data)
{
	size_t	i;
	t_stack	*new;
	t_stack	*prev;

	i = 0;
	new = NULL;
	prev = NULL;
	while (i < data->size)
	{
		new = (t_stack *)malloc(sizeof(t_stack));
		if (!new)
			exit_error(data);
		new->num = (int)data->numbers[i];
		new->next = NULL;
		if (prev)
			prev->next = new;
		else
			data->a = new;
		prev = new;
		i++;
	}
}

void	init_structs(t_data *data)
{
	data->fourth_highest = 0;
	data->highest_a = 0;
	data->highest_b = 0;
	data->lowest_a = 0;
	data->lowest_b = 0;
	data->pivot = 0;
	data->size = 0;
	data->input = NULL;
	data->numbers = NULL;
	data->a = NULL;
	data->b = NULL;
}
