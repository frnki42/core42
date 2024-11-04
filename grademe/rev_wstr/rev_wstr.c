#include <unistd.h>

int	ft_strlen(char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

void	rev_wstr(char *str)
{
	int	len;
	char	*temp;

	temp = NULL;
	len = ft_strlen(str);
	while(str[--len])
	{
		if (str[len - 1] == ' ')
		{
			temp = &str[len];
			while (*temp && *temp != ' ')
				write(1, &(*temp++), 1);
			write(1, " ", 1);
		}
		else if (len == 0)
		{
			temp = &str[len];
			while (*temp && *temp != ' ')
				write(1, &(*temp++), 1);
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
