#include "so_long.h"

// checks if argv is valid (*.ber file)
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

// performs all map checks
void	check_valid(t_game *game)
{
	int	res;

	res = 0;
	res += check_rectangle(game);
	res += check_collectible(game);
	res += check_exit(game);
	res += check_player(game);
	res += check_surrounded(game);
	res += check_composition(game);
	if (res)
		exit_game(game);
}
