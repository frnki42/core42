#include <unistd.h>

void	search_and_replace(char *str, char hay, char needle)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == hay)
			str[i] = needle;
		write(1, &str[i], 1);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 4 || argv[2][1] || argv[3][1])
		return (write(1, "\n", 1));
	search_and_replace(argv[1], argv[2][0], argv[3][0]);
	write(1, "\n", 1);
	return (0);
}
