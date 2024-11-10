#include <unistd.h>

void	last_word(char *str)
{
	char	*temp;
	int	len;

	len = 0;
	temp = str;
	while (str[len])
		len++;
	while (str[--len] == ' ')
		;
	while (str[--len] && str[len] != ' ')
	{
		if (str[len - 1] == ' ')
			temp = &str[len];
	}
	len = 0;
	while (temp[len] && temp[len] != ' ')
		write(1, &temp[len++], 1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (write(1, "\n", 1));
	last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}
