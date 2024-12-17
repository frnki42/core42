#include "push_swap.h"

// frees data->input and all strings inside it
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

// frees data->numbers
static void	free_numbers(t_data *data)
{
	if (data->numbers)
		free(data->numbers);
}

// frees both stacks
static void	free_stacks(t_data *data)
{
	t_stack	*current;
	t_stack	*next;

	if (data->a)
	{
		current = data->a;
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
	}
	if (data->b)
	{
		current = data->b;
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
	}
}

// exits clean
void	exit_clean(t_data *data)
{
	free_stacks(data);
	free_numbers(data);
	free_input(data);
	exit (0);
}

// ERROR! FCK! EVERYONE GRAB THEIR STUFF AND RUN!!
void	exit_error(t_data *data)
{
	ft_putstr_fd("Error\n", 2);
	free_stacks(data);
	free_numbers(data);
	free_input(data);
	exit (1);
}

