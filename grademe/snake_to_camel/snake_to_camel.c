#include <stdlib.h>
#include <unistd.h>

void	complete_task(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			write(1, &str[i], 1);
			i++;
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

int	count_res_len(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '_')
			j++;
		i++;
	}
	return (i - j);
}

char	*snake_to_camel(char *str, char *res)	//"this_is_snake_case"
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '_' && (str[i + 1] >= 'a' && str[i + 1] <= 'z'))
			res[i] = str[i + 1] - 32;
		else
			res[i] = str[i];
		i++;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	int	res_len;
	char	*res;

	if (argc != 2)
		return (write(1, "\n", 1));
	res_len = count_res_len(argv[1]);
	res = malloc(res_len + 1);
	if (!res)
		return (-1);
	res[res_len] = '\0';
	res = snake_to_camel(argv[1], res);
	complete_task(res);
	write(1, "\n", 1);
	free(res);
	return (0);
}
