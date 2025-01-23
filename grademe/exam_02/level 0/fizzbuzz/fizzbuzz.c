#include <unistd.h>

int	main(void)
{
	int	i = 0;
	char	temp = '\0';
	char	tem = '\0';

	while (++i <= 100)
	{
		if (!(i % 3) && !(i % 5))
			write(1, "fizzbuzz", 8);
		else if (!(i % 3))
			write(1, "fizz", 4);
		else if (!(i % 5))
			write(1, "buzz", 4);
		else if  (i > 10)
		{
			temp = (i % 10) + '0';
			tem = (i / 10) + '0';
			write(1, &tem, 1);
			write(1, &temp, 1);

		}
		else
		{
			temp = i + '0';
			write(1, &temp, 1);
		}
		write(1, "\n", 1);
	}
	return (0);
}
