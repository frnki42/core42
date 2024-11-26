#include "so_long.h"

void	display_mary(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->mary.xpm_right, game->mary.x, game->mary.y);
	ft_printf("# DISPLAY_MARY DONE\n");	// remove me
}
