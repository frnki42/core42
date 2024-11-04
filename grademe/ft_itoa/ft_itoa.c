#include <stdlib.h>

int	int_len(int number)
{
	int	counter;

	counter = 0;
	while (number != 0)
	{
		number = number / 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int nbr)
{
	char	*ascii;

	long	number;
	long	len;

	if (nbr < 0)
		nbr = -nbr;
	number = nbr;
	len = int_len(number);
	ascii = malloc(len + 1);
	if (!ascii)
		return (NULL);
	ascii[len] = '\0';
	if (number < 0)
		ascii[0] = '-';
	while (len--)
	{
		ascii[len] = (number % 10) + '0';
		number = number / 10;
	}
	return(ascii);
}

#include <stdio.h>

int	main(void)
{
	char	*string;
	int	number;

	string = NULL;
	number = 4242;
	printf("%s\n", string);
	string = ft_itoa(number);
	printf("%s\n", string);
	free(string);
	return (0);
}

