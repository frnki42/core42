/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: .frnki   <frnki@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:20:42 by .frnki            #+#    #+#             */
/*   Updated: 2024/11/16 16:24:42 by .frnki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
// std header
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
// custom header
# include "minilibx-linux/mlx.h"
# include "libft/get_next_line/get_next_line.h"
# include "libft/printf/ft_printf.h"
# include "libft/libft.h"
// window sizes
# define MAX_WIDTH	1280
# define MAX_HEIGHT	720
// colors
# define AQUA_DARK	0x689d6a
# define AQUA_LIGHT	0x8ec07c
# define BG_0		0x282828
# define FG_1		0xebdbb2
// keys
# define KEY_BACKSPACE	65288
# define KEY_ENTER	65293
# define KEY_ESCAPE	65307
// typedef & structs

typedef struct	s_mary
{
	int	collectible;
	int	moves;
	int	x;
	int	y;
	void	*xpm_left;
	void	*xpm_right;
}	t_mary;

typedef struct	s_map
{
	size_t	columns;
	size_t	rows;
	char	*string;
	char	**array;
}	t_map;

typedef struct	s_game
{
	t_mary	mary;
	t_map	map;
	int	tex_width;
	int	tex_height;
	void	*mlx;
	void	*tex_empty;
	void	*tex_wall;
	void	*tex_collectible;
	void	*tex_exit;
	void	*win;
}	t_game;
// prototypes
int	movement(int keycode, t_game *game);
int	exit_game(t_game *game);
void	load_game_textures(t_game *game);
void	load_mary(t_game *game);
void	start_mlx(t_game *game);
void	create_window(t_game *game);
void	init_game(t_game *game);
void	init_map(t_game *game);
void	init_mary(t_game *game);
void	display_mary(t_game *game);
void	convert_ber(t_game *game);
void	convert_str(t_game *game);
int	check_rectangle(t_game *game);
void	render_map(t_game *game);
void	manipulate_map(t_game *game);
int	check_collectible(t_game *game);
int	check_exit(t_game *game);
int	check_player(t_game *game);
#endif
