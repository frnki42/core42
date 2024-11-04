#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*rstr_capitalizer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i + 1] + 32;
	}
	while((*str && (*str >= 'a' && *str <= 'z') &&
	    	((*(str + 1) < 'A') || *(str + 1) > 'z') ||
		(*(str + 1) >= '[' && *str <= 96)))
	{
		*str = *str - 32;
		str--;
	}	       
	return (str);
}

int	main(int argc, char **argv)
{
	int	i;
	char	*res;

	if (argc < 2)
		return (write(1, "\n", 1));
	i = 1;
	while (i < argc)
	{
		res = rstr_capitalizer(argv[i++]);
		while (*res)
			write(1, &(*res++), 1);
		write(1, "\n", 1);
	}
}
