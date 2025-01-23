#include <unistd.h>

void	rev_wstr(char *str)
{
	int	i;
	char	*word;

	i = -1;
	while (str[++i])
		;
	while (str[--i])
	{
		if (str[i - 1] == ' ' || str[i - 1] == '\0')
		{
			word = &str[i];
			while (*word && *word != ' ')
				write(1, &(*word++), 1);
			if (str[i - 1])
				write(1, " ", 1);
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (write(1, "\n", 1));
	rev_wstr(argv[1]);
	write(1, "\n", 1);
	return (0);
}
