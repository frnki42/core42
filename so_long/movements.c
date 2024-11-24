#include "so_long.h"

int	movements(int keycode, t_game *game)
{
	if (keycode == ' ')
		mlx_put_image_to_window(game->mlx, game->win, game->mary.sprite[0], game->mary.x, game->mary.y);
	if (keycode == 'a')
		game->mary.x -= 32;
	if (keycode == 'd')
		game->mary.x += 32;
	if (keycode == 's')
		game->mary.y += 32;
	if (keycode == 'w')
		game->mary.y -= 32;
	mlx_clear_window(game->mlx, game->win);
	mlx_put_image_to_window(game->mlx, game->win, game->mary.sprite[0], game->mary.x, game->mary.y);
	if (keycode == 'r')
		mlx_clear_window(game->mlx, game->win);
	if (keycode == 65288)			// backspace
		mlx_clear_window(game->mlx, game->win);
	if (keycode == 65293)			// enter
		print_floor(game);
	if (keycode == 65307)			// escape
		exit_game(game);
	printf("You pressed: %c (keycode: %i)\n", (char)keycode, keycode);
	return (0);
}
