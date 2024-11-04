#include <unistd.h>

void	search_and_replace(char *string, char replaceme, char withme)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == replaceme)
			string[i] = withme;
		write(1, &string[i++], 1);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 4 || argv[2][1] != '\0' || argv[3][1] != '\0')
		return (write(1, "\n", 1));
	search_and_replace(argv[1], argv[2][0], argv[3][0]);
	write(1, "\n", 1);
	return (0);
}
