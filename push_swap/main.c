#include "push_swap.h"

static size_t	count_numbers(const char *argv)
{
	size_t	amount;
	size_t	i;

	amount = 0;
	i = 0;
	while (*argv)
	{
		if (*argv != ' ' && i == 0)
		{
			i = 1;
			amount++;
		}
		if (*argv == ' ')
			i = 0;
		argv++;
	}
	return (amount);
}

static void	single_arg(t_data *data, char *argv)
{
	// check if argv[1] is one or multiple numbers
	data->size = count_numbers(argv);
	if (data->size < 1)
		exit_clean(data);
	// convert str to *int || int
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
	ft_printf("string: %s\n", argv[1]);\
	ft_printf("int : %i\n", ft_atoi(argv[1]));
	ft_printf("%i\n", data.size);
	return (0);
}
