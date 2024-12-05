#include "push_swap.h"

size_t	count_numbers(char *argv)
{
	size_t	amount;
	size_t	is_number;

	amount = 0;
	is_number = 0;
	while (*argv)
	{
		if (*argv != ' ' && is_number == 0)
		{
			is_number = 1;
			amount++;
		}
		if (*argv == ' ')
			is_number = 0;
		argv++;
	}
	return (amount);
}
