#include "so_long.h"

void	start_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_game(game);
	ft_printf("# MLX INITIALIZED\n");		// remove me
}
