#include <stdlib.h>
#include <stdio.h>

int	euclidiean_algo(int a, int b)
{
	int	temp;

	while (b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return (a);
}

int	main(int argc, char **argv)
{
	int	gcd;
	int	input_one;
	int	input_two;

	if (argc != 3)
		return (printf("\n"));
	input_one = atoi(argv[1]);
	input_two = atoi(argv[2]);
	gcd = euclidiean_algo(input_one, input_two);
	printf("%i\n", gcd);
	return (0);
}
