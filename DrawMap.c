/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DrawMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:41:42 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/05/26 18:50:20 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx/mlx.h"

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*ground_img;
	void	*wall_img;
	int		img_width;
	int		img_height;
	int		Xloc;
	int		Yloc;
	int		i;

	img_width = 48;
	img_height = 48;
	Xloc = 0;
	Yloc = 0;
	i = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "putImage");
	ground_img = mlx_xpm_file_to_image(mlx, "imgs/ground.xpm", &img_width, &img_height);
	wall_img = mlx_xpm_file_to_image(mlx, "imgs/rock.xpm", &img_width, &img_height);
	while (i < 10)
	{
		mlx_put_image_to_window(mlx, win, wall_img, Xloc, Yloc);
		Xloc += img_width;
		i++;
	}
	Yloc += img_width;
	Xloc = 0;
	i = 0;
	while (i < 10)
	{
		mlx_put_image_to_window(mlx, win, ground_img, Xloc, Yloc);
		Xloc += img_width;
		i++;
	}
	mlx_loop(mlx);
	return (0);
}
