/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MoveImage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:14:24 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/06/02 17:26:32 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

int	key_press(int keycode, t_param *param)
{
	if (keycode == KEY_W && param->y != 0)
	{
		param->y -= param->he;
		param->move++;
	}
	if (keycode == KEY_S && param->y != 480)
	{
		param->y += param->he;
		param->move++;
	}
	else if (keycode == KEY_A && param->x != 0)
	{
		param->x -= param->wi;
		param->move++;
	}
	else if (keycode == KEY_D && param->x != 480)
	{
		param->x += param->wi;
		param->move++;
	}
	else if (keycode == KEY_ESC)
		exit(0);
	printf("move: %d\n", param->move);
	return (0);
}

int	draw(t_param *loc)
{
	mlx_clear_window(loc->mlx, loc->win);
	drawmap(loc);
	mlx_put_image_to_window(loc->mlx, loc->win, loc->c, loc->x, loc->y);
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
	t_param		par;

	par.mlx = mlx_init();
	par.g = mlx_xpm_file_to_image(par.mlx, "imgs/g.xpm", &par.wi, &par.he);
	par.w = mlx_xpm_file_to_image(par.mlx, "imgs/r.xpm", &par.wi, &par.he);
	par.c = mlx_xpm_file_to_image(par.mlx, "imgs/c.xpm", &par.wi, &par.he);
	par.win = mlx_new_window(par.mlx, 1000, 1000, "DrawMap");
	par.x = 0;
	par.y = 0;
	par.win_width = 0;
	par.win_height = 0;
	par.move = 0;
	par.fd = open("maps/map.ber", O_RDONLY);
	if (checkmap_length(&par))
		draw(&par);
	else
	{
		printf("ERROR");
		return (0);
	}
	mlx_key_hook(par.win, &key_press, &par);
	mlx_hook(par.win, PRESS_RED_BUTTON, 0, &redbut, &par);
	mlx_loop_hook(par.mlx, &draw, &par);
	mlx_loop(par.mlx);
	return (0);
}
