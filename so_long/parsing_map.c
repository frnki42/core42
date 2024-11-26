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
	ft_printf("# MAP.STRING ALLOCATED\n");			// remove me
}

void	convert_str(t_game *game)
{
	game->map.array = ft_split(game->map.string, '\n');
	ft_printf("# MAP.ARRAY ALLOCATED\n");			// remove me
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

void	render_map(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (game->map.array[y])
	{
		x = 0;
		while (game->map.array[y][x])
		{
			if (game->map.array[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->tex_empty, x * 32, y * 32);
			if (game->map.array[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->tex_wall, x * 32, y * 32);
			if (game->map.array[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->tex_collectible, x * 32, y * 32);
			if (game->map.array[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->tex_exit, x * 32, y * 32);
			if (game->map.array[y][x] == 'P')
			{
				game->map.array[y][x] = '0';
				game->mary.x = x * 32;
				game->mary.y = y * 32;
			}
			x++;
		}
		y++;
	}
}
