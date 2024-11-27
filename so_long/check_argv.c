#include "so_long.h"

int	check_argv(char *argv)
{
	int	len;

	if (!argv)
		return (1);
	len = 0;
	len = ft_strlen(argv);
	if (len < 5)
		return (2);
	if (argv[--len] != 'r')
		return (3);
	if (argv[--len] != 'e')
		return (3);
	if (argv[--len] != 'b')
		return (3);
	if (argv[--len] != '.')
		return (3);
	return (0);
}
