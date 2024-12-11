#include <unistd.h>

char	*rot_13(char *string)
{
	int	i;

	i = -1;
	while(string[++i])
	{
		if (string[i] >= 'a' && string[i] <= 'm')
			string[i] += 13; 
		else if (string[i] >= 'n' && string[i] <= 'z')
			string[i] -= 13;
		else if (string[i] >= 'A' && string[i] <= 'M')
			string[i] += 13; 
		else if (string[i] >= 'N' && string[i] <= 'Z')
			string[i] -= 13;
		write(1, &string[i], 1);
	}
	return (string);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return(write(1, "\n", 1));
	rot_13(argv[1]);
	write(1, "\n", 1);
	return (0);
}
