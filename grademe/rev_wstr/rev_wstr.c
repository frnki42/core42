#include <unistd.h>

void	rev_wstr(char *str)
{
	int	i;
	int	len;
	char	*printme;

	len = 0;
	printme = str;
	while (str[len])
		len++;
	while (str[--len])
	{
		i = 0;
		if (str[len - 1] == ' ')
		{
			printme = &str[len];
			while (printme[i] && printme[i] != ' ')
				write(1, &printme[i++], 1);
			write(1, " ", 1);
		}
		else if (len == 0)
		{
			while (*str && *str != ' ')
				write(1, &(*str++), 1);
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
