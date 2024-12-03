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

// check if {P, E, C} got reached by flood_fill in game->map.array_cpy
int	check_path(t_game *game)
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
			{
				ft_printf("Error\n# NO VALID PATH DETECTED\n");
				return (1);
			}
		}
	}
	return (0);
}

// locate game->map.start_x and game->map.start_y
void	detect_start(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	if (!game->map.array)
		exit_game(game, 1);
	while (game->map.array[y])
	{
		x = 0;
		while (game->map.array[y][x])
		{
			if (game->map.array[y][x] == 'P')
			{
				game->map.start_x = x;
				game->map.start_y = y;
			}
			x++;
		}
		y++;
	}
}

// displays player
void	display_mary(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->mary.xpm_right, game->mary.x * 32, game->mary.y * 32);
}
