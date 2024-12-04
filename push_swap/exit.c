#include "push_swap.h"

void	exit_clean(t_data *data)
{
	if (data->stack_a.content)
		free(data->stack_a.content);
	if (data->stack_b.content)
		free(data->stack_b.content);
}
