int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return(s1[i] - s2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	printf("%i\n", ft_strcmp(argv[1], argv[2]));
	(void)argc;
	return (0);
}*/
