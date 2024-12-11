#include "push_swap.h"

void	swap_a(t_data *data)
{
	int	tmp;

	tmp = data->a->num;
	data->a->num = data->a->next->num;
	data->a->next->num = tmp;
	write(1, "sa\n", 3);
}

void	swap_b(t_data *data)
{
	int	tmp;

	tmp = data->b->num;
	data->b->num = data->b->next->num;
	data->b->next->num = tmp;
	write(1, "sb\n", 3);
}

void	push_a(t_data *data)
{
	t_stack *tmp;

	if (data->b)
	{
		tmp = NULL;
		tmp = data->b;					// save struct
		data->b = data->b->next;			// finish handling stack b
		tmp->next = data->a;				// connect node with stack a
		data->a = tmp;					// set start of stack a to node
		write(1, "pa\n", 3);
	}
}

void	push_b(t_data *data)
{
	t_stack *tmp;

	if (data->a)
	{
		tmp = NULL;
		tmp = data->a;					// save struct
		data->a = data->a->next;			// finish handling stack a
		tmp->next = data->b;				// connect node with stack b
		data->b = tmp;					// set start of stack b to node
		write(1, "pb\n", 3);
	}
}
