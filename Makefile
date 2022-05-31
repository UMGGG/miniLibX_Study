# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeyjeon <@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 16:01:20 by jaeyjeon          #+#    #+#              #
#    Updated: 2022/05/31 17:54:05 by jaeyjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc -Wall -Wellor -Wextra -Lmlx -lmlx -framework OpenGL -framework AppKit MoveImage.c
	./a.out
