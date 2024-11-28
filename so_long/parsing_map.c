#include "so_long.h"

// converts .ber file into string
void	convert_ber(t_game *game, char *path)
{
	int	map;
	char	*output;

	if (check_argv(path))
		exit_game(game);
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
}

// converts 1d map into 2d map
void	convert_str(t_game *game)
{
	game->map.array = ft_split(game->map.string, '\n');
	game->map.array_cpy = ft_split(game->map.string, '\n');
}

// detects amount of collectibles
void	count_collectibles(t_game *game)
{
	int	i;

	i = -1;
	while (game->map.string[++i])
	{
		if (game->map.string[i] == 'C')
			game->map.collectibles++;
	}
}

// puts textures according to the map
void	show_map(t_game *game, int x, int y)
{
	if (game->map.array[y][x] == 'P')
	{
		game->map.array[y][x] = '0';
		game->mary.x = x * 32;
		game->mary.y = y * 32;
	}
	if (game->map.array[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
				game->tex_empty, x * 32, y * 32);
	if (game->map.array[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
				game->tex_wall, x * 32, y * 32);
	if (game->map.array[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
				game->tex_collectible, x * 32, y * 32);
	if (game->map.array[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
				game->tex_exit, x * 32, y * 32);
}

// show_map wrapper function
void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map.array[++y])
	{
		x = -1;
		while (game->map.array[y][++x])
			show_map(game, x, y);
	}
}
