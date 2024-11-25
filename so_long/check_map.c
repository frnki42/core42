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

int	check_collectible(t_game *game)
{
	int	collectible;
	int	i;

	collectible = -1;
	i = 0;
	while (game->map.string[i])
	{
		if (game->map.string[i++] == 'C')
			collectible++;
	}
	return (collectible);
}

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
