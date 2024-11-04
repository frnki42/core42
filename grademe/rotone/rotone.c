#include <unistd.h>

void	rotone(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((str[i] >= 'a' && str[i] <= 'y') || (str[i] >= 'A' && str[i] <= 'Y'))
			str[i] = str[i] + 1;
		else if (str[i] == 'Z' || str[i] == 'z')
			str[i] = str[i] - 25;
		write(1 , &str[i], 1);
	}
}

int	main(int argc, char ** argv)
{
	if (argc != 2)
		return (write(1, "\n", 1));
	rotone(argv[1]);
	write(1, "\n", 1);
	return (0);
}
