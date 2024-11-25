#include "so_long.h"

char	*convert_ber(t_game *game)
{
	int	map;
	char	*output;

	game->map.string = "";
	map = open("maps/map_valid.ber", O_RDONLY);
	if (map == -1)
		return (printf("Error opening map \n"), NULL);	// use ft_printf 
	output = get_next_line(map);
	while (output)
	{
		game->map.string = ft_strjoin(game->map.string, output);
		free(output);
		output = get_next_line(map);
	}
	free(output);
	close(map);
	ft_printf("%s\n", game->map.string);
	return (game->map.string);
}
