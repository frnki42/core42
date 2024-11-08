#include <unistd.h>

void	fizzbuzz(int max)
{
	int	i;
	char	ones;
	char	tens;

	i = 1;
	while (i <= max)
	{
		if (i % 5 == 0 && i % 3 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else if (i > 10)
		{
			ones = i % 10 + '0';
			tens = i / 10 + '0';
			write(1, &tens, 1);
			write(1, &ones, 1);
		}
		else
		{
			ones = i + '0';
			write(1, &ones, 1);
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(void)
{
	fizzbuzz(100);
	return (0);
}
