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
	int	y;

	data->stack_a = (int *)malloc(sizeof(int) * data->size);
	if (!data->stack_a)
		exit_error(data);
	y = -1;
	while (data->input[++y])
		data->stack_a[y] = ft_atoi(data->input[y]);
}

void	single_arg(t_data *data, char *argv)
{
	// check if argv[1] is one or multiple numbers
	data->size = count_numbers(argv);
	if (data->size < 1)
		exit_clean(data);
	// convert *char to *char[data->size]
	convert_argv(data, argv);
	// check if data->input is valid (only numbers)
	check_valid(data);
	// convert *char to *int
	convert_input(data);
	check_doubles(data);
}

int	main(int argc, char **argv)
{
	t_data	data;
	if (argc == 1)
		return (ft_putstr_fd(argv[0], 1), 1);
	// initialize structures
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
