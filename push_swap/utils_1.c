#include "push_swap.h"

void	convert_argv(t_data *data, char *argv)
{
	data->input = ft_split(argv, ' ');
	if (!data->input)
		exit_error(data);
}

void	convert_args(t_data *data, char **argv)
{
	size_t	i;

	data->input = (char **)malloc(sizeof(char *) * (data->size + 1));
	if (!data->input)
		exit_error(data);
	i = 0;
	while (i < data->size)
	{
		data->input[i] = (char *)malloc(ft_strlen(argv[i + 1]) + 1);
		if (!data->input[i])
			exit_error(data);
		ft_strlcpy(data->input[i], argv[i + 1],
			ft_strlen(argv[i + 1]) + 1);
		i++;
	}
	data->input[i] = NULL;
}

void	convert_input(t_data *data)
{
	int	i;

	data->numbers = (long *)malloc(sizeof(long) * data->size);
	if (!data->numbers)
		exit_error(data);
	i = -1;
	while (data->input[++i])
		data->numbers[i] = ft_atolong(data->input[i]);
}

void print_stack(t_data *data)
{
	t_stack *current_a;
	t_stack *current_b;

	current_a = data->a;
	current_b = data->b;
	ft_printf("  A\t  B\n");
	ft_printf("-------\t-------\n");
	while (current_a || current_b)
	{
		if (current_a)
		{
		    ft_printf("%d", current_a->num);
		    current_a = current_a->next;
		}
		else
		    ft_printf(" ");
		ft_printf("\t");
		if (current_b)
		{
		    ft_printf("%d", current_b->num);
		    current_b = current_b->next;
		}
		ft_printf("\n");
	}
}

void	algo44(t_data *data)
{
	find_highest_a(data);
	find_lowest_a(data);
	if (data->a->num == data->lowest_a)
		handle_lowest_zero(data);
	else if (data->a->next->num == data->lowest_a)
		handle_lowest_one(data);
	else if (data->a->next->next->num == data->lowest_a)
		handle_lowest_two(data);
	else if (data->a->next->next->next->num == data->lowest_a)
		handle_lowest_three(data);
}
