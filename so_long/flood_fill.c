#include "so_long.h"

// use array_cpy to replace all 0 C P E with 'X
void	flood_fill(t_game *game, size_t y, size_t x)  //int collectibles, int exit int player 
{
	if (x < 1 || x >= (game->map.columns - 1) || y < 1 || y >= (game->map.rows - 1))
	{
		if (game->map.array_cpy[y][x] == '0'|| game->map.array_cpy[y][x] == 'C' || game->map.array_cpy[y][x] == 'P' || game->map.array_cpy[y][x] == 'E')
		{
			game->map.array_cpy[y][x] = 'X';			// 80 chars here
			flood_fill(game, y + 1, x);
			flood_fill(game, y - 1, x);
			flood_fill(game, y, x + 1);
			flood_fill(game, y, x - 1);
		}
	}
}
	// run over it again to check if only 1 and 'X' are left

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


