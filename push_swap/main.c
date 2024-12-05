#include "push_swap.h"

void	convert_argv(t_data *data, char *argv)
{
	if (!argv)
		exit_error(data);
	data->input = ft_split(argv, ' ');
	if (!data->input)
		exit_error(data);
}

void	convert_input(t_data *data)
{
	int	i;

	data->stack_a = (int *)malloc(sizeof(int) * data->size);
	if (!data->stack_a)
		exit_error(data);
	data->stack_c = (long *)malloc(sizeof(long) * data->size);
	if (!data->stack_c)
		exit_error(data);
	i = -1;
	while (data->input[++i])
	{
		data->stack_a[i] = ft_atoi(data->input[i]);
		data->stack_c[i] = ft_atolong(data->input[i]);
	}
}

void	single_arg(t_data *data, char *argv)
{
	data->size = count_numbers(argv);
	if (data->size < 1)
		exit_clean(data);
	convert_argv(data, argv);
	check_input(data);
	convert_input(data);
	check_doubles(data);
	check_ints(data);
}

int	main(int argc, char **argv)
{
	t_data	data;
	if (argc == 1)
		return (ft_putstr_fd(argv[0], 1), 1);
	init_structs(&data);
	if (argc == 2)
		single_arg(&data, argv[1]);
	if (argc > 2)
	{
		// multiple_args(data);
		// store args
		// check args if valid
		// convert args to *int
	}
	// execute algorithm
	exit_clean(&data);
	return (0);
}
