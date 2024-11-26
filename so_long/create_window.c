#include "so_long.h"

void	create_window(t_game *game)
{
	game->win = mlx_new_window(game->mlx, game->map.columns * 32, game->map.rows * 32, ".frnki");
	ft_printf("# CREATE_WINDOW DONE\n");
}
