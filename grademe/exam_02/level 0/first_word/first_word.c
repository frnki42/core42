#include <unistd.h>

void	first_word(char *str)
{
	while (*str == ' ')
		str++;
	while (*str && *str != ' ')
		write(1, &(*str++), 1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (write(1, "\n", 1));
	first_word(argv[1]);
	write(1, "\n", 1);	
	return (0);
}
