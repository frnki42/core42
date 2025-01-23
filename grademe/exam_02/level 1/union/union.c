#include <unistd.h>

int	main(int argc, char **argv)
{
	int	h[127] = {0};
	int	i;
	int	j;

	if (argc != 3)
		return (write(1, "\n", 1));
	i = 0;
	while(++i < 3)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!h[(int)argv[i][j]]++)
				write(1, &argv[i][j], 1);
		}
	}
	write(1, "\n", 1);
	return(0);
}
