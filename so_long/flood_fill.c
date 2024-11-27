#include "so_long.h"

int	flood_fill(t_game *game)
{
	if (
}

int	init_flood_fill(t_game *game)
{
	int	start_x;
	int	start_y;
	int	x;
	int	y;

	start_x = 0;
	start_y = 0;
	y = 0;
	while (game->map.array[y])
	{
		x = 0;
		while (game->map.array[y][x])
		{
			if (game->map.array[y][x] == 'P')
			{
				start_x = x;
				start_y = y;
			}
			x++;
		}
		y++;
	}
}
