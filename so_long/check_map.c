#include "so_long.h"

int	check_rows(t_game *game)
{
	size_t	i;

	if (game->map.array)
	{
		game->map.columns = ft_strlen(game->map.array[0]);
		i = 1;
		while (i < game->map.rows)
		{
			if (game->map.columns != ft_strlen(game->map.array[i]))
					return (1);
			i++;
		}
	}
	return (0);
}
