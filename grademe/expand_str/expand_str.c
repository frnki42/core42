#include <unistd.h>

void	expand_str(char *str)
{
	int	i;

	i = -1; 
	while (str[++i] == ' ')
		;
	while (str[i])
	{
		if (str[i] != ' ')
			write(1, &str[i++], 1);
		else if (str[i] == ' ')
		{
			while (str[i] == ' ')
				i++;
			if (str[i] == '\0')
				break;
			write(1, "   ", 3);
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (write(1, "\n", 1));
	expand_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}
