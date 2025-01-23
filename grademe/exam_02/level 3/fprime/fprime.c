#include <stdlib.h>
#include <stdio.h>

void	fprime(int n)
{
	int	i;

	if (n == 1)
		printf("1");
	i = 2;
	while (n > 1)
	{
		if (n % i == 0)
		{
			printf("%i", i);
			n /= i;
			if (n > 1)
				printf("*");
		}
		else
			i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		fprime(atoi(argv[1]));
	printf("\n");
	return (0);
}
