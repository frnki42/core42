#include <unistd.h>

int	space_check(char *string)
{
	while (*string)
	{
		if (*string != ' ')
			return (1);
	string++;
	}
	return (0);
}
int	ft_strlen(char *string)
{
	int	i;
	
	i = 0;
	while (string[i])
		i++;
	return (i);
}

void	last_word(char *string)
{
	int	i;
	char	*ptr;

	i = 0;
	while (string[i])
		i++;
	i--;
	while (string[i] == ' ')
		i--;
	while (string[--i] && string[i] != ' ')
		ptr = &string[i];
	i = -1;
	while (ptr[++i] && ptr[i] != ' ')
	{
		write(1, &ptr[i], 1);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (write(1, "\n", 1));
	if (space_check(argv[1]) == 0)
		return (write(1,  "\n", 1));
	last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}
