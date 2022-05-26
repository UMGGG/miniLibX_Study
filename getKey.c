/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getKey.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:30:29 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/05/26 18:30:07 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "mlx/mlx.h"

#define KEY_ESC				53
#define KEY_W				13
#define KEY_S				1
#define PRESS_RED_BUTTON	17

typedef struct s_param{
	int		x;
	int		y;
}				t_param;

void	param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
}

int	key_press(int keycode, t_param *param)
{
	if (keycode == KEY_W)//Action when W key pressed
		param->x++;
	else if (keycode == KEY_S) //Action when S key pressed
		param->x--;
	else if (keycode == KEY_ESC) //Quit the program when ESC key pressed
		exit(0);
	printf("x: %d\n", param->x);
	return (0);
}

int	close(void)
{
	printf("press_red_button");
	exit(0);
	return (0);
}

int	main(void)
{
	void		*mlx;
	void		*win;
	t_param		param;

	param_init(&param);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "getKey");
	printf("-------------------------------\n");
	printf("Current x = 3\n");
	mlx_key_hook(win, &key_press, &param);
	mlx_hook(win, PRESS_RED_BUTTON, 0, &close, &param);
	mlx_loop(mlx);
}
