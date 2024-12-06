#include "push_swap.h"

static void	free_input(t_data *data)
{
	size_t	i;

	i = 0;
	if (data->input)
	{
		while (data->input[i])
			free(data->input[i++]);
		free(data->input);
	}
}

static void	free_numbers(t_data *data)
{
	if (data->numbers)
		free(data->numbers);
}

static void	free_stacks(t_data *data)
{
	t_stack *ptr;
	t_stack	*tmp;

	ptr = NULL;
	tmp = NULL;
	ptr = data->a;
	while (ptr)
	{
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
	ptr = data->b;
	while (ptr)
	{
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
}

void	exit_clean(t_data *data)
{
	free_stacks(data);
	free_numbers(data);
	free_input(data);
	exit (0);
}

void	exit_error(t_data *data)
{
	ft_putstr_fd("Error\n", 2);
	free_stacks(data);
	free_numbers(data);
	free_input(data);
	exit (1);
}

