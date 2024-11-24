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
// window sizes
# define WIDTH	1280
# define HEIGHT	720
// colors
# define AQUA_DARK	0x689d6a
# define AQUA_LIGHT	0x8ec07c
# define BG_0		0x282828
# define FG_1		0xebdbb2
// typedef & structs

typedef struct	s_mary
{
	int	x;
	int	y;
	void	*sprite[2];
}	t_mary;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	t_mary	mary;
	char	**map;
	int	tex_width;
	int	tex_height;
	void	*tex[4];
}	t_game;
// prototypes
int	movements(int keycode, t_game *game);
int	exit_game(t_game *game);
int	print_floor(t_game *game);
void	load_game_textures(t_game *game);
void	load_mary(t_game *game);
#endif
