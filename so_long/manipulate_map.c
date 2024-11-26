#include "so_long.h"

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
