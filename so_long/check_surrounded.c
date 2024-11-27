#include "so_long.h"

// checks if the map is surrounded by walls
int	check_surrounded(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->map.rows)
	{
		if (game->map.array[i][0] != '1' || game->map.array[i][game->map.columns - 1] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (game->map.array[0][i])
	{
		if (game->map.array[0][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (game->map.array[game->map.rows - 1][i])
	{
		if (game->map.array[game->map.rows - 1][i] != '1')
			return (1);
		i++;
	}
	return (0);
}
