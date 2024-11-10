#include <stdlib.h>

int	get_amount(int start, int end)
{
	int	i;

	i = 0;
	if (start < end)
	{
		while (start < end)
		{
			start++;
			i++;
		}
	}
	else if (start > end)
	{
		while (start > end)
		{
			start--;
			i++;
		}
	}
	return (i);
}

int	*ft_rrange(int start, int end)
{
	int	*array;
	int	amount;
	int	i;

	amount = get_amount(start, end);
	array = (int *)malloc(sizeof(int) * amount + 1); 
	i = 0;
	if (start < end)
	{
		while (i <= amount)
			array[i++] = end--;
	}
	else
	{
		while (i <= amount)
			array[i++] = end++;
	}
	return (array);
}
/*
#include <stdio.h>

int	main(void)
{
	int	i;
	int	*integers;

	i = 0;
	integers = ft_rrange(0, -5);
	while (i < 6)
	{
		printf("integers[%i] = %i\n", i, integers[i]);
		i++;
	}
	free(integers);
	return (0);
}*/
