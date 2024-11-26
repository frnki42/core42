#include "so_long.h"

// checks if all rows have the same length (rectangle)
int	check_rectangle(t_game *game)
{
	size_t	i;

	if (game->map.array)
	{
		game->map.columns = ft_strlen(game->map.array[0]);
		i = 0;
		while (i < game->map.rows)
		{
			if (game->map.columns != ft_strlen(game->map.array[i]))
					return (1);
			i++;
		}
	}
	return (0);
}

// checks if there is any collectible inside the map
int	check_collectible(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.string[i])
	{
		if (game->map.string[i++] == 'C')
			return (0);
	}
	return (1);
}

// checks if there is one exit present
int	check_exit(t_game *game)
{
	int	exit;
	int	i;

	exit = -1;
	i = 0;
	while (game->map.string[i])
	{
		if (game->map.string[i++] == 'E')
			exit++;
	}
	return (exit);
}

// checks if there is one player present
int	check_player(t_game *game)
{
	int	player;
	int	i;

	player = -1;
	i = 0;
	while (game->map.string[i])
	{
		if (game->map.string[i++] == 'P')
			player++;
	}
	return (player);
}

// checks if next move would hit a wall
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
