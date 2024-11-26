#include "so_long.h"

int	check_wall(t_game *game, int keycode)
{
	int	dest;

	if (keycode == 'a' || keycode == 'd')
	{
		if (keycode == 'a')
			dest = (game->mary.x / 32) - 1;
		else if (keycode == 'd')
			dest = (game->mary.x / 32) + 1;
		if (game->map.array[game->mary.y / 32][dest] == '1')
			return (0);
	}
	else if (keycode == 's' || keycode == 'w')
	{
		if (keycode == 's')
			dest = (game->mary.y / 32) + 1;
		else if (keycode == 'w')
			dest = (game->mary.y / 32) - 1;
		if (game->map.array[dest][game->mary.x / 32] == '1')
			return (0);
	}
	return (1);
}
