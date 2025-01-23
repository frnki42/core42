#include <unistd.h>

void	snake_to_camel(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '_')
		{
			str[i] = str[i + 1] - 32;
			write(1, &str[i++], 1);
		}
		else
			write(1, &str[i], 1); 
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (write(1, "\n", 1));
	snake_to_camel(argv[1]);
	write(1, "\n", 1);
	return (0);
}
