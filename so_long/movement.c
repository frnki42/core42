#include "so_long.h"

// moves player 32 pixel left
void	move_left(int keycode, t_game *game)
{
	if (check_wall(game, keycode))
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->tex_empty, game->player.x * 32, game->player.y * 32);
		game->player.x -= 1;
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.xpm_left, game->player.x * 32, game->player.y * 32);
		game->player.moves++;
		ft_printf("MOVES: %i\n", game->player.moves);
	}
}

// moves player 32 pixel right
void	move_right(int keycode, t_game *game)
{
	if (check_wall(game, keycode))
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->tex_empty, game->player.x * 32, game->player.y * 32);
		game->player.x += 1;
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.xpm_right, game->player.x * 32, game->player.y * 32);
		game->player.moves++;
		ft_printf("MOVES: %i\n", game->player.moves);
	}
}

// moves player 32 pixel down
void	move_down(int keycode, t_game *game)
{
	if (check_wall(game, keycode))
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->tex_empty, game->player.x * 32, game->player.y * 32);
		game->player.y += 1;
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.xpm_down, game->player.x * 32, game->player.y * 32);
		game->player.moves++;
		ft_printf("MOVES: %i\n", game->player.moves);
	}
}

// moves player 32 pixel up
void	move_up(int keycode, t_game *game)
{
	if (check_wall(game, keycode))
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->tex_empty, game->player.x * 32, game->player.y * 32);
		game->player.y -= 1;
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.xpm_up, game->player.x * 32, game->player.y * 32);
		game->player.moves++;
		ft_printf("MOVES: %i\n", game->player.moves);
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
