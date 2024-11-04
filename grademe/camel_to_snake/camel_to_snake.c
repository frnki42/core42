#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	count_capitals(char *str)
{
	int	capitals;

	capitals = 0;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			capitals++;
		str++;
	}
	return (capitals);
}

char	*camel_to_snake(char *str)
{
	char	*res;
	int	i;
	int	j;

	i = 0;
	j = 0;
	res = malloc(ft_strlen(str) + count_capitals(str) + 1);
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			res[j] = '_';
			j++;
			res[j] = str[i] + 32;
		}
		else
			res[j] = str[i];
		i++;
		j++;
	}
	str[i] = '\0';
	return (res);
}

int	main(int argc, char **argv)
{
	char	*result;
	int	i;

	if (argc != 2)
		return (write(1, "\n", 1));
	i = -1;
	result = camel_to_snake(argv[1]);
	while (result[++i])
		write(1, &result[i], 1);
	write(1, "\n", 1);
	free(result);
	(void)argc;
	return (0);
}
