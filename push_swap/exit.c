#include "push_swap.h"

static void	free_stacks(t_data *data)
{
	if (data->stack_a)
		free(data->stack_a);
	if (data->stack_b)
		free(data->stack_b);
}

void	exit_clean(t_data *data)
{
	free_stacks(data);
}
