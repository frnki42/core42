#include "so_long.h"

// replace all reachable '0' 'C' 'P' 'E' with 'X' in game->map.array_cpy
void	flood_fill(t_game *game, size_t y, size_t x)
{
	if (x < 1 || x >= game->map.columns - 1 ||
		y < 1 || y >= game->map.rows - 1)
		return ;
	if (game->map.array_cpy[y][x] == '0'||
		game->map.array_cpy[y][x] == 'C' ||
		game->map.array_cpy[y][x] == 'P' ||
		game->map.array_cpy[y][x] == 'E')
	{
		game->map.array_cpy[y][x] = 'X';
		flood_fill(game, y + 1, x);
		flood_fill(game, y - 1, x);
		flood_fill(game, y, x + 1);
		flood_fill(game, y, x - 1);
	}
}

// check if only '1' and 'X' exist in game->map.array_cpy
int	check_flood(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map.array_cpy[++y])
	{
		x = -1;
		while (game->map.array_cpy[y][++x])
		{
			if (!(game->map.array_cpy[y][x] == '1' ||
				game->map.array_cpy[y][x] == 'X' ||
				game->map.array_cpy[y][x] == '0'))
				return (ft_printf("Error\n"), 1);
		}
	}
	return (0);
}

// locate game->map.start_x and game->map.start_y
void	detect_start(t_game *game)
{
	size_t	x;
	size_t	y;

	y = -1;
	while (game->map.array[++y])
	{
		x = -1;
		while (game->map.array[y][++x])
		{
			if (game->map.array[y][x] == 'P')
			{
				game->map.start_x = x;
				game->map.start_y = y;
			}
		}
	}
	ft_printf("# DETECT_START DONE\n");
}


