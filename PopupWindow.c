/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PopupWindow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:21:28 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/05/26 17:23:03 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx/mlx.h>

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "PopupWindow");
	mlx_loop(mlx);
}
