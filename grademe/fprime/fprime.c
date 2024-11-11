#include <stdio.h>
#include <stdlib.h>

void	fprime(int n)
{
	int	factor;

	factor = 2;
	if (n == 1)
	{
		printf("1");
		return ;
	}
	while (n > 1)
	{
		if (n % factor == 0)
		{
			printf("%d", factor);
			n = n / factor;
			if (n > 1)
				printf("*");
		}
		else
			factor++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		fprime(atoi(argv[1]));
	printf("\n");
	return (0);
}
