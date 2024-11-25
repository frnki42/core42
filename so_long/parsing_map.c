#include "so_long.h"

void	convert_ber(t_game *game)
{
	int	map;
	char	*output;

	game->map.string = "";
	map = open("maps/first_map.ber", O_RDONLY);
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
	ft_printf("# MAP.STRING ALLOCATED\n");			// remove me
}

void	convert_str(t_game *game)
{
	game->map.array = ft_split(game->map.string, '\n');
	ft_printf("# MAP.ARRAY ALLOCATED\n");			// remove me
}
