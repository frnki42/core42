#include "so_long.h"

// destroys stuff
void	destroy_stuff(t_game *game)
{
	if (game->tex_empty)
		mlx_destroy_image(game->mlx, game->tex_empty);
	if (game->tex_wall)
		mlx_destroy_image(game->mlx, game->tex_wall);
	if (game->tex_collectible)
		mlx_destroy_image(game->mlx, game->tex_collectible);
	if (game->tex_exit)
		mlx_destroy_image(game->mlx, game->tex_exit);
	if (game->mary.xpm_left)
		mlx_destroy_image(game->mlx, game->mary.xpm_left);
	if (game->mary.xpm_right)
		mlx_destroy_image(game->mlx, game->mary.xpm_right);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
}

// frees stuff
void	free_stuff(t_game *game)
{
	size_t	i;

	if (game->map.string)
		free(game->map.string);
	if (game->map.array)
	{
		i = 0;
		while (i < game->map.rows)
			free(game->map.array[i++]);
		free(game->map.array);
	}
	if (game->map.array_cpy)
	{
		i = 0;
		while (i < game->map.rows)
			free(game->map.array_cpy[i++]);
		free(game->map.array_cpy);
	}
	if (game->mlx)
		free(game->mlx);
}

// exits game
int	exit_game(t_game *game)
{
	destroy_stuff(game);
	free_stuff(game);
	exit (0);
	return (0);
}
