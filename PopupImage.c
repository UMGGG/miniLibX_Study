/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PopupImage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:49:28 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/05/26 18:49:52 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx/mlx.h"

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		width;
	int		height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "putImage");
	img = mlx_xpm_file_to_image(mlx, "imgs/ground.xpm", &width, &height);
	mlx_put_image_to_window(mlx, win, img, 50, 50);
	mlx_put_image_to_window(mlx, win, img, 50, 98);
	mlx_put_image_to_window(mlx, win, img, 50, 146);
	mlx_loop(mlx);
	return (0);
}
