#include "so_long.h"

// moves player 32 pixel left
void	move_left(int keycode, t_game *game)
{
	if (check_wall(game, keycode))
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->tex_empty, game->mary.x * 32, game->mary.y * 32);
		game->mary.x -= 1;
		mlx_put_image_to_window(game->mlx, game->win,
			game->mary.xpm_left, game->mary.x * 32, game->mary.y * 32);
		game->mary.moves++;
		ft_printf("MOVES: %i\n", game->mary.moves);
	}
}

// moves player 32 pixel right
void	move_right(int keycode, t_game *game)
{
	if (check_wall(game, keycode))
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->tex_empty, game->mary.x * 32, game->mary.y * 32);
		game->mary.x += 1;
		mlx_put_image_to_window(game->mlx, game->win,
			game->mary.xpm_right, game->mary.x * 32, game->mary.y * 32);
		game->mary.moves++;
		ft_printf("MOVES: %i\n", game->mary.moves);
	}
}

// moves player 32 pixel down
void	move_down(int keycode, t_game *game)
{
	if (check_wall(game, keycode))
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->tex_empty, game->mary.x * 32, game->mary.y * 32);
		game->mary.y += 1;
		mlx_put_image_to_window(game->mlx, game->win,
			game->mary.xpm_left, game->mary.x * 32, game->mary.y * 32);
		game->mary.moves++;
		ft_printf("MOVES: %i\n", game->mary.moves);
	}
}

// moves player 32 pixel up
void	move_up(int keycode, t_game *game)
{
	if (check_wall(game, keycode))
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->tex_empty, game->mary.x * 32, game->mary.y * 32);
		game->mary.y -= 1;
		mlx_put_image_to_window(game->mlx, game->win,
			game->mary.xpm_right, game->mary.x * 32, game->mary.y * 32);
		game->mary.moves++;
		ft_printf("MOVES: %i\n", game->mary.moves);
	}
}

// handles user input
int	movement(int keycode, t_game *game)
{
	if (keycode == KEY_ESCAPE)
		exit_game(game, 0);
	if (keycode == 'a')
		move_left(keycode, game);
	if (keycode == 'd')
		move_right(keycode, game);
	if (keycode == 's')
		move_down(keycode, game);
	if (keycode == 'w')
		move_up(keycode, game);
	manipulate_map(game);
	return (0);
}
