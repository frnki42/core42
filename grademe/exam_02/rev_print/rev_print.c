#include <unistd.h>

void	rev_print(char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	while (i--)
		write(1, &string[i], 1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return(write(1, "\n", 1));
	rev_print(argv[1]);
	write(1, "\n", 1);
	return (0);
}
