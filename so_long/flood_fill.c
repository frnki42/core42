#include "so_long.h"
/*
int	flood_fill(t_game *game, int x, int y)
{
	if (x < 1 || x >= (game->map.columns - 1) || y < 1 || y >= (game->map.rows - 1))
	// copy array and use this one to replace all 0 C P E with other CHAR
	// run over it again to check if only 1 and CHAR are left

	flood_fill(game, y + 1, x);
	flood_fill(game, y + 1, x);
	flood_fill(game, y, x + 1);
	flood_fill(game, y, x - 1);
}
*/
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
