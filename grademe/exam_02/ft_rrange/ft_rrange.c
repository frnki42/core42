#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	i = 0;
	int	*res = NULL;

	if (start < end)
	{
		while ((start + i) <= end)
			i++;
	}
	else
	{
		while ((start - i) >= end)
			i++;
	}
	res = (int *)malloc(sizeof(int) * i);
	if (!res)
		return (NULL);
	if (start < end)
	{
		while (i--)
			res[i] = start++;
	}
	else
	{
		while (i--)
			res[i] = start--;
	}
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	int	*res = ft_rrange(0, -3);
	int	i = 0;

	while (i < 4)
		printf("%i\n", res[i++]);
	free(res);
	return (0);
}*/
