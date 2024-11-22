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
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
// custom header
# include "minilibx-linux/mlx.h"
// window sizes
# define WIDTH	1280
# define HEIGHT	720
// colors
# define AQUA_DARK	0x689d6a
# define AQUA_LIGHT	0x8ec07c
# define BG_0		0x282828
# define FG_1		0xebdbb2
// typedef & structs
typedef struct	s_vars
{
	char	**map;
	int	img_width;
	int	img_height;
	void	*img[5];
	void	*mlx;
	void	*win;
}	t_vars;
#endif
