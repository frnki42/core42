#include "push_swap.h"

static void	algo42(t_data *data)
{
	if (data->a->num > data->a->next->num)
		swap_a(data);
}

void	select_algo(t_data *data)
{
	if (data->size == 2)
		algo42(data);
}
