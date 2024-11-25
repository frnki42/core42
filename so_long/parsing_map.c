#include "so_long.h"

char	*convert_ber(t_game *game)
{
	int	map;
	char	*output;

	game->map.string = "";
	map = open("maps/map_valid.ber", O_RDONLY);
	if (map == -1)
		return (ft_printf("Error opening map \n"), NULL); 
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
	ft_printf("%s", game->map.string);			// remove me
	ft_printf("%i\n", game->map.rows);			// remove me
	return (game->map.string);
}

void	convert_str(t_game *game)
{
	int	i;

	i = 0;
	game->map.array = ft_split(game->map.string, '\n');
	ft_printf("# MAP.ARRAY ALLOCATED\n");			// remove me
	while (game->map.array[i])				// remove me
		ft_printf("%s\n", game->map.array[i++]);	// remove me
}
