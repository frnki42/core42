#include "push_swap.h"

static void	free_stacks(t_data *data)
{
	if (data->stack_a)
		free(data->stack_a);
	if (data->stack_b)
		free(data->stack_b);
}

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

void	exit_clean(t_data *data)
{
	free_stacks(data);
	free_input(data);
	exit (0);
}

void	exit_error(t_data *data)
{
	ft_putstr_fd("Error\n", 2);
	free_stacks(data);
	free_input(data);
	exit (1);
}

