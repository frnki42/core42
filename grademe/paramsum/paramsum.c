#include <unistd.h>

int	main(int argc, char **argv)
{
	char	temp;
	char	tem;

	if (argc <= 10)
	{
		temp = (argc - 1) + '0';
		write(1, &temp, 1);
		write(1, "\n", 1);
	}
	else
	{
		temp = ((argc - 1) % 10) + '0';
		tem = ((argc - 1) / 10) + '0';
		write(1, &tem, 1);
		write(1, &temp, 1);
		write(1, "\n", 1);
	}
	(void)argv;
	return (0);
}
