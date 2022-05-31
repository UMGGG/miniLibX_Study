/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MoveImage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:14:24 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/05/31 18:02:00 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define KEY_ESC				53
#define KEY_W				13
#define KEY_S				1
#define KEY_A				0
#define KEY_D				2
#define PRESS_RED_BUTTON	17

typedef struct s_param
{
	void	*mlx;
	void	*win;
	void	*character;
	void	*ground;
	int		x;
	int		y;
	int		width;
	int		height;
}	t_param;

int	key_press(int keycode, t_param *param)
{
	if (keycode == KEY_W && param->y != 0)
		param->y -= param->height;
	if (keycode == KEY_S && param->y != 480)
		param->y += param->height;
	else if (keycode == KEY_A && param->x != 0)
		param->x -= param->width;
	else if (keycode == KEY_D && param->x != 480)
		param->x += param->width;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("y: %d x: %d\n", param->y, param->x);
	return (0);
}

void	drawmap(t_param *loc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= 11)
	{
		while (j <= 11)
		{
			mlx_put_image_to_window(loc->mlx, loc->win, loc->ground, 48 * i, 48 * j);
			j++;
		}
		j = 0;
		i++;
	}
}

int	draw(t_param *loc)
{
	mlx_clear_window(loc->mlx, loc->win);
	drawmap(loc);
	mlx_put_image_to_window(loc->mlx, loc->win, loc->character, loc->x, loc->y);
	return (0);
}

int	redbut(void)
{
	printf ("press red button");
	exit (0);
	return (0);
}

int	main(void)
{
	t_param		loc;

	loc.x = 0;
	loc.y = 0;
	loc.mlx = mlx_init();
	loc.character = mlx_xpm_file_to_image(loc.mlx, "imgs/character.xpm", &loc.width, &loc.height);
	loc.ground = mlx_xpm_file_to_image(loc.mlx, "imgs/ground.xpm", &loc.width, &loc.height);
	loc.win = mlx_new_window(loc.mlx, loc.width * 11, loc.height * 11, "MoveImage");
	draw(&loc);
	mlx_key_hook(loc.win, &key_press, &loc);
	mlx_hook(loc.win, PRESS_RED_BUTTON, 0, &redbut, &loc);
	mlx_loop_hook(loc.mlx, &draw, &loc);
	mlx_loop(loc.mlx);
	return (0);
}
