/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DrawMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:41:42 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/05/28 15:14:13 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx/mlx.h"

typedef struct s_imgparam
{
	void	*img;
	int		height;
	int		width;
}	t_imgparam;

int	main(void)
{
	void		*mlx;
	void		*win;
	t_imgparam	ground;
	t_imgparam	wall;
	int			xloc;
	int			yloc;
	int			i;

	xloc = 0;
	yloc = 0;
	i = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "DrawMap");
	ground.img = mlx_xpm_file_to_image(mlx, "imgs/ground.xpm", &ground.width, &ground.height);
	wall.img = mlx_xpm_file_to_image(mlx, "imgs/rock.xpm", &wall.width, &wall.height);
	while (i < 15)
	{
		mlx_put_image_to_window(mlx, win, wall.img, xloc, yloc);
		xloc += wall.width;
		i++;
	}
	yloc += wall.height;
	xloc = 0;
	i = 0;
	while (i < 15)
	{
		mlx_put_image_to_window(mlx, win, ground.img, xloc, yloc);
		xloc += ground.width;
		i++;
	}
	mlx_loop(mlx);
	return (0);
}
