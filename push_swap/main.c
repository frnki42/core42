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
		ft_strlcpy(data->input[i], argv[i + 1], ft_strlen(argv[i + 1]) + 1);
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
	fill_stack(data);
}

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
	fill_stack(data);
}

void	print_stack(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->size)
	{
		ft_printf("# INDEX NO.  %i\n", data->size);
		ft_printf("# NUM:       %i\n", data->a[i].num);
		ft_printf("# POSITION:  %p\n", &data->a[i].num);
		ft_printf("# PREV:      %p\n", data->a[i].prev);
		ft_printf("# NEXT:      %p\n", data->a[i++].next);
		ft_printf("#############################\n");
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		return (ft_putstr_fd(argv[0], 1), 1);
	if (argc == 2)
		process_single_arg(&data, argv[1]);
	if (argc > 2)
		process_multiple_args(&data, argc, argv);
	print_stack(&data);					//!remove me
	select_algo(&data);
	// execute algorithm
	exit_clean(&data);
	return (0);
}
