/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:35:34 by jaeyjeon          #+#    #+#             */
/*   Updated: 2022/05/31 18:55:53 by jaeyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "inc/42Get_Next_Line/get_next_line.h"

# define KEY_ESC				53
# define KEY_W				13
# define KEY_S				1
# define KEY_A				0
# define KEY_D				2
# define PRESS_RED_BUTTON	17

typedef struct s_param
{
	void	*mlx;
	void	*win;
	void	*character;
	void	*ground;
	void	*wall;
	size_t	fd;
	int		x;
	int		y;
	int		width;
	int		height;
	int		win_width;
	int		win_height;
}	t_param;

#endif
