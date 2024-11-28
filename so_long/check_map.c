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
			{
				ft_printf("Error\n# MAP IS NOT RECTANGULAR\n");
				return (1);
			}
			i++;
		}
	}
	return (0);
}

// checks if at least one collectible is present
int	check_collectible(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.string[i])
	{
		if (game->map.string[i++] == 'C')
			return (0);
	}
	return (ft_printf("Error\n# NO COLLECTIBLES IN MAP DETECTED\n"), 1);
}

// checks if only one exit is present
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
	if (exit > 0)
		ft_printf("Error\n# MAP CONTAINS EXIT DUPLICATES\n");
	return (exit);
}

// checks if only one player is present
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
	if (player > 0)
		ft_printf("Error\n# MAP CONTAINS START DUPLICATES\n");
	return (player);
}

// checks if map is only composed of {0, 1, C, E, P, \n}
int	check_composition(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.string[i])
	{
		if (game->map.string[i] == '0' ||
			game->map.string[i] == '1' ||
			game->map.string[i] == 'C' ||
			game->map.string[i] == 'E' ||
			game->map.string[i] == 'P' ||
			game->map.string[i] == '\n')
			i++;
		else
		{
			ft_printf("Error\n# WRONG MAP COMPOSITION\n");
			return (1);
		}
	}
	return (0);
}
