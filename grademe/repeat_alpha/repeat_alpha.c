#include <unistd.h>

void	repeat_alpha(char *string)
{
	int	i;
	int	amount;

	i = -1;
	while (string[++i])
	{
		amount = 1;
		if (string[i] >= 'a' && string[i] <= 'z')
			amount = string[i] - 96;
		else if (string[i] >= 'A' && string[i] <= 'Z')
			amount = string[i] - 64;
		while (amount--)
			write(1, &string[i], 1);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (write(1, "\n", 1));
	repeat_alpha(argv[1]);
	write(1, "\n", 1);
	return (0);
}
