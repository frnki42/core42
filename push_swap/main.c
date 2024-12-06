#include "push_swap.h"

void	convert_argv(t_data *data, char *argv)
{
	if (!argv)
		exit_error(data);
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
	init_structs(data);
	data->size = count_numbers(argv);
	if (data->size < 1)
		exit_clean(data);
	convert_argv(data, argv);
	check_input(data);
	convert_input(data);
	check_doubles(data);
	check_ints(data);
}

void	multiple_args(t_data *data, int argc, char **argv)
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
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		return (ft_putstr_fd(argv[0], 1), 1);
	if (argc == 2)
		single_arg(&data, argv[1]);
	if (argc > 2)
		multiple_args(&data, argc, argv);
	// execute algorithm
	exit_clean(&data);
	return (0);
}
