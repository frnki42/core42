#include "minilibx-linux/mlx.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

#define WIDTH	1280
#define HEIGHT	720

typedef struct	s_vars
{
	int	img_width;
	int	img_height;
	void	*img;
	void	*mlx;
	void	*win;
}	t_vars;

int	print_bye(t_vars *vars)
{
	printf("Bye!\n");
	return (0);
}

int	print_hello(t_vars *vars)
{
	printf("Hello!\n");
	return (0);
}

int	exit_game(t_vars *vars)
{
	if (vars->img)
		mlx_destroy_image(vars->mlx, vars->img);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("'%c' was pressed. (keycode: %i)\n", (char)keycode, keycode);
	if (keycode == 65307)
		exit_game(vars);
	if (keycode == 120)
	{
		mlx_clear_window(vars->mlx, vars->win);
		printf("window cleared\n");
	}
	return (0);
}

int	mouse_click(int mouse_button, int x, int y, t_vars *vars)
{
	if (mouse_button == 1)
		mlx_string_put(vars->mlx, vars->win, x, y, AQUA_DARK, "I <3 MARY!");
	if (mouse_button == 2)
		mlx_string_put(vars->mlx, vars->win, x, y, FG_1 , "I <3 MARY!");
	if (mouse_button == 3)
		mlx_string_put(vars->mlx, vars->win, x, y, AQUA_LIGHT, "I <3 MARY!");
	if (mouse_button == 4)
		mlx_string_put(vars->mlx, vars->win, x, y, 0x98971a, "I <3 MARY!");
	if (mouse_button == 5)
		mlx_string_put(vars->mlx, vars->win, x, y, 0xfb4934, "I <3 MARY!");
	if (mouse_button == 8)
		mlx_put_image_to_window(vars->mlx, vars->win,vars->img, x, y);
	printf("mouse button [%d] clicked at (%d, %d)\n", mouse_button, x, y);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	int	x;
	int	y;

	x = 0;
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, ".frnki");
	if (!vars.win)
		return (free(vars.mlx), 1);
	vars.img = mlx_xpm_file_to_image(vars.mlx, "floor.xpm", &vars.img_width, &vars.img_height);
	if (!vars.img)
		return (free(vars.mlx), 1);
	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	mlx_hook(vars.win, 7, 1L<<4, print_hello, &vars);
	mlx_hook(vars.win, 8, 1L<<5, print_bye, &vars);
	mlx_hook(vars.win, 4, 1L<<2, mouse_click, &vars);
	mlx_hook(vars.win, 17, 0L, exit_game, &vars);
	mlx_loop(vars.mlx);
}

/*
	while (x < WIDTH)
	{
		y = 200;
		while (y < HEIGHT - 200)
		{
			mlx_pixel_put(vars.mlx, vars.win, x, y, AQUA_DARK);
			y++;
		}
		x++;
	}
	x = 0;
	while (x < WIDTH * 0.8)
	{
		y = 300;
		while (y < HEIGHT - 300)
		{
			mlx_pixel_put(vars.mlx, vars.win, x, y, BG_0);
			y++;
		}
		x++;
	}
	x = 0;
	while (x < WIDTH * 0.7)
	{
		y = 330;
		while (y < HEIGHT - 330)
		{
			mlx_pixel_put(vars.mlx, vars.win, x, y, FG_1);
			y++;
		}
		x++;
	}

int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}*/
/*
int	mouse_hook(int mousecode, t_vars *vars)
{
	printf("mousecode: %i\n", mousecode);
	return (0);
}
	mlx_hook(vars.win, 4, 1l<<2, mouse_hook, &vars);
*/
