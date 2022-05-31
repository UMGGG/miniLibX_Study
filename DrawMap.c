/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DrawMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:41:42 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/05/31 18:57:08 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkmap_length(t_param *param)
{
	char	*str;
	int		check_width;

	str = get_next_line(param->fd);
	if (str == NULL)
		return (0);
	while (str != NULL)
	{
		param->win_height++;
		param->win_width = ft_strlen(str);
		while (*str != '\0')
		{
			if (*str == '1')

			else if (*str == '0')

			str++;
			param->x += param->width;
		}
		str = get_next_line(param->fd);
	}
}

int	drawmap(t_param *param)
{
	char	*str;

	mlx_clear_window(param->mlx, param->win);
	str = get_next_line(param->fd);
	while (str != NULL)
	{
		while (*str != '\0')
		{
			if (*str == '0')
				mlx_put_image_to_window(param->mlx, param->win, param->ground, param->x, param->y);
			else if (*str == '1')
				mlx_put_image_to_window(param->mlx, param->win, param->wall, param->x, param->y);
			str++;
			param->x += param->width;
		}
		str = get_next_line(param->fd);
		param->x = 0;
		param->y += param->height;
	}
	return (0);
}

int	main(void)
{
	t_param	param;

	param.mlx = mlx_init();
	param.ground = mlx_xpm_file_to_image(param.mlx, "imgs/ground.xpm", &param.width, &param.height);
	param.wall = mlx_xpm_file_to_image(param.mlx, "imgs/rock.xpm", &param.width, &param.height);
	param.win = mlx_new_window(param.mlx, 1000, 1000, "DrawMap");
	param.x = 0;
	param.y = 0;
	param.fd = open("maps/map.ber", O_RDONLY);
	param.win_width = 0;
	param.win_height = 0;
	drawmap(&param);
	mlx_loop(param.mlx);
	return (0);
}
