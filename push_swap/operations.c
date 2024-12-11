#include "push_swap.h"

// swaps first 2 ints on stack a
void	swap_a(t_data *data)
{
	int	tmp;

	if (data->a && data->a->next)
	{
		tmp = data->a->num;
		data->a->num = data->a->next->num;
		data->a->next->num = tmp;
		write(1, "sa\n", 3);
	}
}

// swaps first 2 ints on stack b
void	swap_b(t_data *data)
{
	int	tmp;

	if (data->b && data->b->next)
	{
		tmp = data->b->num;
		data->b->num = data->b->next->num;
		data->b->next->num = tmp;
		write(1, "sb\n", 3);
	}
}

// pushes top element from stack b to the top of stack a
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

// pushes top element from stack a to the top of stack b
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

// rotates stack a
void	rotate_a(t_data *data)
{
	t_stack	*last;
	t_stack *tmp;

	last = NULL;
	tmp = NULL;
	if (data->a && data->a->next)
	{
		tmp = data->a;
		data->a = data->a->next;
		last = data->a;
		while (last->next)
			last = last->next;
		last->next = tmp;
		tmp->next = NULL;
		write(1, "ra\n", 3);
	}
}

// rotates stack b
void	rotate_b(t_data *data)
{
	t_stack	*last;
	t_stack *tmp;

	last = NULL;
	tmp = NULL;
	if (data->b && data->b->next)
	{
		tmp = data->b;
		data->b = data->b->next;
		last = data->b;
		while (last->next)
			last = last->next;
		last->next = tmp;
		tmp->next = NULL;
		write(1, "rb\n", 3);
	}
}

// reverse rotates stack a
void	reverse_rotate_a(t_data *data)
{
	t_stack	*last;
	t_stack *tmp;

	last = NULL;
	tmp = NULL;
	if (data->a && data->a->next)
	{
		last = data->a;
		while (last->next->next)
			last = last->next;
		tmp = last->next;
		last->next = NULL;
		tmp->next = data->a;
		data->a = tmp;
		write(1, "rra\n", 4);
	}
}

// reverse rotates stack b
void	reverse_rotate_b(t_data *data)
{
	t_stack	*last;
	t_stack *tmp;

	last = NULL;
	tmp = NULL;
	if (data->b && data->b->next)
	{
		last = data->b;
		while (last->next->next)
			last = last->next;
		tmp = last->next;
		last->next = NULL;
		tmp->next = data->b;
		data->b = tmp;
		write(1, "rrb\n", 4);
	}
}
