#include <unistd.h>

void	inter(char *hay, char *needle)
{
	int	check[127] = {0};
	int	i;
	int	j;

	i = -1;
	while (hay[++i])
	{
		j = -1;
		while (needle[++j])
		{
			if (hay[i] == needle[j] && check[(int)needle[j]] == 0)
			{
				write(1, &hay[i], 1);
				check[(int)needle[j]] = 1;
			}
		}
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
