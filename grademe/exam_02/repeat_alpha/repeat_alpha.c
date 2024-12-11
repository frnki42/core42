#include <unistd.h>

void	repeat_alpha(char *str)
{
	int	i;
	int	amount;

	i = -1;
	while (str[++i])
	{
		amount = 1;
		if (str[i] >= 'a' && str[i] <= 'z')
			amount = str[i] - 96;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			amount = str[i] - 64;
		while (amount--)
			write(1, &str[i], 1);
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
