/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efembock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:16:08 by efembock          #+#    #+#             */
/*   Updated: 2025/01/23 14:56:05 by efembock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H
// std header
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
// custom header
# include "mlx.h"
# include "libft/get_next_line/get_next_line.h"
# include "libft/printf/ft_printf.h"
# include "libft/libft.h"

// keys
# define KEY_ESCAPE	65307
// typedef & structs

typedef struct s_player
{
	int		collectible;
	int		moves;
	int		x;
	int		y;
	void	*xpm_left;
	void	*xpm_right;
	void	*xpm_up;
	void	*xpm_down;
}	t_player;

typedef struct s_map
{
	int		collectibles;
	size_t	columns;
	size_t	rows;
	size_t	start_x;
	size_t	start_y;
	char	*string;
	char	**array;
	char	**array_cpy;
}	t_map;

typedef struct s_game
{
	t_player	player;
	t_map		map;
	int			tex_width;
	int			tex_height;
	void		*mlx;
	void		*tex_empty;
	void		*tex_wall;
	void		*tex_collectible;
	void		*tex_exit;
	void		*win;
}	t_game;

// prototypes
void	check_argv(t_game *game, char *argv);
int		check_collectible(t_game *game);
int		check_composition(t_game *game);
void	check_empty_lines(t_game *game);
int		check_exit(t_game *game);
int		check_path(t_game *game);
int		check_player(t_game *game);
int		check_rectangle(t_game *game);
int		check_surrounded(t_game *game);
int		check_wall(t_game *game, int keycode);
void	check_valid(t_game *game);
void	convert_ber(t_game *game, char *path);
void	convert_str(t_game *game);
void	count_collectibles(t_game *game);
void	destroy_stuff(t_game *game);
void	detect_start(t_game *game);
void	flood_fill(t_game *game, size_t y, size_t x);
void	free_stuff(t_game *game);
void	initialize_game(t_game *game);
void	init_game(t_game *game);
void	init_map(t_game *game);
void	init_player(t_game *game);
void	load_game_textures(t_game *game);
void	load_player(t_game *game);
void	manipulate_map(t_game *game);
int		movement(int keycode, t_game *game);
void	move_down(int keycode, t_game *game);
void	move_left(int keycode, t_game *game);
void	move_right(int keycode, t_game *game);
void	move_up(int keycode, t_game *game);
int		exit_game(t_game *game, int exit_status);
void	render_map(t_game *game);
void	show_map(t_game *game, int x, int y);
void	win_screen(int moves);
#endif
