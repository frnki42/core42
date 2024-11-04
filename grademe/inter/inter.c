#include <unistd.h>

int	ft_strlen(char *string)
{
	int	i;

	if (!string)
		return (0);
	while (string[i])
		i++;
	return (i);
}

int	check_second(char first, char *second)
{
	int	i;

	i = -1;
	while (second[++i])
	{
		if (second[i] == first)
			return (1);
	}
	return (0);
}

int	check_existance(char *first, int index)
{
	int	i;

	i = 0;
	while (i < index)		//traverse first string
	{				//check if char exists in string already
		if (first[index] == first[i])
			return (1);
		i++;
	}
	return (0);
}

void	inter(char *first, char *second)
{
	int	i;

	i = 0;
	while (first[i])		//traverse first string
	{				//check if char exists in string already
		if (check_existance(first, i) == 0)
		{
			if (check_second(first[i], second) == 1)
				write(1, &first[i], 1);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (write(1, "\n", 1));
	inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
/*

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (write(1, "\n", 1);
	inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}*/
