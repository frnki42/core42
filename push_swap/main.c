#include "push_swap.h"

// handles single argv
static void	process_single_arg(t_data *data, char *argv)
{
	init_structs(data);
	data->size = count_numbers(argv);
	if (data->size < 1)
		exit_clean(data);
	convert_argv(data, argv);
	check_input(data);
	convert_input(data);
	check_doubles(data);
	check_ints(data);
	fill_stack_a(data);
}

// handles multiple argvs
static void	process_multiple_args(t_data *data, int argc, char **argv)
{
	init_structs(data);
	data->size = argc - 1;
	if (data->size < 1)
		exit_clean(data);
	convert_args(data, argv);
	check_input(data);
	convert_input(data);
	check_doubles(data);
	check_ints(data);
	fill_stack_a(data);
}

// "Hello, World!"
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		return (ft_putstr_fd(argv[0], 1), write(1, "\n", 1), 1);
	if (argc == 2)
		process_single_arg(&data, argv[1]);
	if (argc > 2)
		process_multiple_args(&data, argc, argv);
	is_sorted(&data);
	select_algo(&data);
	exit_clean(&data);
	return (0);
}
