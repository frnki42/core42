#include "push_swap.h"

// check if character is a digit
void	check_num(t_data *data, int c)
{
	if (!(c >= '0' && c <= '9'))
		exit_error(data);
}

// check if character is digit, + or -
void	check_sign(t_data *data, int c)
{
	if (!((c >= '0' && c <= '9') || c == '-' || c == '+'))
		exit_error(data);
}

// check if input is valid
void	check_input(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (data->input[++y])
	{
		x = -1;
		while (data->input[y][++x])
		{
			if (x == 0)
				check_sign(data, data->input[y][x]);
			else
				check_num(data, data->input[y][x]);
		}
	}
}

// executes all checks
void	check_valid(t_data *data)
{

	if (!data->input)
		exit_error(data);
	// check_characters(data);
	check_input(data);
	// check if there is doubles
}
