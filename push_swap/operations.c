#include "push_swap.h"

void	swap_a(t_data *data)
{
	int	tmp;

	tmp = data->a->num;
	data->a->num = data->a->next->num;
	data->a->next->num = tmp;
	write(1, "sa\n", 3);
}
/*
void	swap_b(t_data *data)
{
	int	tmp;

	if (data->size > 1)
	{
		tmp = 0;
		tmp = data->b[0].num;
		data->b[0].num = data->b[1].num;
		data->b[1].num = tmp;
		write(1, "sb\n", 3);
	}
}
*/
