#include "so_long.h"

int	check_valid(t_game *game)
{
	int	res;

	res = 0;
	res += check_rectangle(game);
	res += check_collectible(game);
	res += check_exit(game);
	res += check_player(game);
	return (res);
}

void	create_window(t_game *game)
{
	game->win = mlx_new_window(game->mlx, game->map.columns * 32, game->map.rows * 32, ".frnki");
	ft_printf("# CREATE_WINDOW DONE\n");
}

void	manipulate_map(t_game *game)
{
	if (game->map.array[game->mary.y / 32][game->mary.x / 32] == 'C')
	{
		game->mary.collectible++;
		game->map.array[game->mary.y / 32][game->mary.x / 32] = '0';
		ft_printf("# %i/%i COLLECTIBLES COLLECTED!\n", game->mary.collectible, game->map.collectibles);
	}
	if (game->map.array[game->mary.y / 32][game->mary.x / 32] == 'E'&& (game->mary.collectible == game->map.collectibles))
		exit_game(game);	
}

void	start_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_game(game);
	ft_printf("# MLX INITIALIZED\n");		// remove me
}

void	display_mary(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->mary.xpm_right, game->mary.x, game->mary.y);
	ft_printf("# DISPLAY_MARY DONE\n");	// remove me
}
