#include "so_long.h"

int	movement(int keycode, t_game *game)
{
//	printf("You pressed: %c (keycode: %i)\n", (char)keycode, keycode);
	if (keycode == ' ')
		mlx_put_image_to_window(game->mlx, game->win, game->tex_collectible, game->mary.x, game->mary.y);
	if (keycode == 'a')
	{
		if (check_wall(game, keycode))
			game->mary.x -= 32;
		game->mary.moves++;
		mlx_clear_window(game->mlx, game->win);
		manipulate_map(game);
		render_map(game);
		mlx_put_image_to_window(game->mlx, game->win, game->mary.xpm_left, game->mary.x, game->mary.y);
		ft_printf("MOVES: %i\n", game->mary.moves);				// replace me with counter in game
	}
	if (keycode == 'd')
	{
		if (check_wall(game, keycode))
			game->mary.x += 32;
		game->mary.moves++;
		mlx_clear_window(game->mlx, game->win);
		manipulate_map(game);
		render_map(game);
		mlx_put_image_to_window(game->mlx, game->win, game->mary.xpm_right, game->mary.x, game->mary.y);
		ft_printf("MOVES: %i\n", game->mary.moves);				// replace me with counter in game
	}
	if (keycode == 's')
	{
		if (check_wall(game, keycode))
			game->mary.y += 32;
		game->mary.moves++;
		mlx_clear_window(game->mlx, game->win);
		manipulate_map(game);
		render_map(game);
		mlx_put_image_to_window(game->mlx, game->win, game->mary.xpm_left, game->mary.x, game->mary.y);
		ft_printf("MOVES: %i\n", game->mary.moves);				// replace me with counter in game
	}
	if (keycode == 'w')
	{
		if (check_wall(game, keycode))
			game->mary.y -= 32;
		game->mary.moves++;
		mlx_clear_window(game->mlx, game->win);
		manipulate_map(game);
		render_map(game);
		mlx_put_image_to_window(game->mlx, game->win, game->mary.xpm_right, game->mary.x, game->mary.y);
		ft_printf("MOVES: %i\n", game->mary.moves);				// replace me with counter in game
	}
	if (keycode == 'r')
		mlx_clear_window(game->mlx, game->win);
	if (keycode == KEY_BACKSPACE)
		mlx_clear_window(game->mlx, game->win);
	if (keycode == KEY_ENTER)
		render_map(game);
	if (keycode == KEY_ESCAPE)
	{
		exit_game(game);
		exit (0);
		return (1);
	}
	return (0);
}