#include "so_long.h"

void	convert_ber(t_game *game, char *path)
{
	int	map;
	char	*output;

	game->map.string = "";
	map = open(path, O_RDONLY);
	if (map == -1)
		exit_game(game);
	output = get_next_line(map);
	while (output)
	{
		game->map.rows++;
		game->map.string = ft_strjoin(game->map.string, output);
		free(output);
		output = get_next_line(map);
	}
	free(output);
	close(map);
	ft_printf("# CONVERT_BER DONE\n");			// remove me
}

void	convert_str(t_game *game)
{
	game->map.array = ft_split(game->map.string, '\n');
	game->map.array_cpy = ft_split(game->map.string, '\n');
	ft_printf("# CONVERT_STR DONE\n");			// remove me
}

void	count_collectibles(t_game *game)
{
	int	i;

	i = -1;
	while (game->map.string[++i])
	{
		if (game->map.string[i] == 'C')
			game->map.collectibles++;
	}
	ft_printf("# %i COLLECTIBLES DETECTED\n", game->map.collectibles);	//remove me
}
