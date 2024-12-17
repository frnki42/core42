#include "push_swap.h"

// converts argv into multiple strings
void	convert_argv(t_data *data, char *argv)
{
	data->input = ft_split(argv, ' ');
	if (!data->input)
		exit_error(data);
}

// copies strings from **argv to **input
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

// converts strings into longs
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

// selects algorithm according to data size
void	select_algo(t_data *data)
{
	if (data->size == 2)
		algo42(data);
	if (data->size == 3)
		algo43(data);
	if (data->size == 4)
		algo44(data);
	if (data->size == 5)
		algo45(data);
	if (data->size > 5)
		algo4more(data);
}
