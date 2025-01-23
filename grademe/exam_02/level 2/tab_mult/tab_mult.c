#include <unistd.h>

int	ft_atoi(char *input)
{
	int	number;
	int	i;

	i = 0;
	number = 0;
	while (input[i])
	{
		if (input[i] >= '0' && input[i] <= '9')
			number = (number * 10) + input[i] - '0';
		i++;
	}
	return (number);
}

void	put_number(int number)
{
	char	temp;

	if (number > 9)
		put_number(number / 10);
	temp = (number % 10) + '0';
	write(1, &temp, 1);
}

int	main(int argc, char **argv)
{
	int input_number;

	if (argc < 2)
		return (write(1, "\n", 1));
	input_number = ft_atoi(argv[1]);
	write(1, "1 x ", 4);
	put_number(input_number);
	write(1, " = ", 3);
	put_number(input_number * 1);
	write(1, "\n", 1);

	write(1, "2 x ", 4);
	put_number(input_number);
	write(1, " = ", 3);
	put_number(input_number * 2);
	write(1, "\n", 1);

	write(1, "3 x ", 4);
	put_number(input_number);
	write(1, " = ", 3);
	put_number(input_number * 3);
	write(1, "\n", 1);

	write(1, "4 x ", 4);
	put_number(input_number);
	write(1, " = ", 3);
	put_number(input_number * 4);
	write(1, "\n", 1);

	write(1, "5 x ", 4);
	put_number(input_number);
	write(1, " = ", 3);
	put_number(input_number * 5);
	write(1, "\n", 1);

	write(1, "6 x ", 4);
	put_number(input_number);
	write(1, " = ", 3);
	put_number(input_number * 6);
	write(1, "\n", 1);

	write(1, "7 x ", 4);
	put_number(input_number);
	write(1, " = ", 3);
	put_number(input_number * 7);
	write(1, "\n", 1);

	write(1, "8 x ", 4);
	put_number(input_number);
	write(1, " = ", 3);
	put_number(input_number * 8);
	write(1, "\n", 1);

	write(1, "9 x ", 4);
	put_number(input_number);
	write(1, " = ", 3);
	put_number(input_number * 9);
	write(1, "\n", 1);
	(void)argc;
	return (0);
}
