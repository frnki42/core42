#include "push_swap.h"

// pushes top element from stack b to the top of stack a
void	push_a(t_data *data)
{
	t_stack *tmp;

	if (data->b)
	{
		tmp = NULL;
		tmp = data->b;
		data->b = data->b->next;
		tmp->next = data->a;
		data->a = tmp;
		write(1, "pa\n", 3);
	}
}

// pushes top element from stack a to the top of stack b
void	push_b(t_data *data)
{
	t_stack *tmp;

	if (data->a)
	{
		tmp = NULL;
		tmp = data->a;
		data->a = data->a->next;
		tmp->next = data->b;
		data->b = tmp;
		write(1, "pb\n", 3);
	}
}
