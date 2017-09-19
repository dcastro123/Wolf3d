/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 20:44:17 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/19 04:16:14 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdlib.h>
# include <math.h>
# include <stdint.h>
# include <unistd.h>
# include "../libft/inc/libft.h"
# include "../resources/mlx.h"
# include <pthread.h>
# include <fcntl.h>
# include <stdio.h>
# include <time.h>

# define WINDOW_W	1280
# define WINDOW_H	720
# define MAP_W		24
# define MAP_H		24
# define WHITE
# define BROWN
# define GREEN
# define BLUE
# define ROT_SPEED	0.060
# define MV_SPEED	0.12
# define K_UP
# define K_DWN
# define K_LFT
# define K_RGHT
# define K_ESC

// typedef struct 	s_map
// {







// }				t_map;


typedef struct 	s_env
{
	void	*mlx;
	void	*win;
	char	*image;
	int 	*data;
	double x_pos;
	double y_pos;
	double x_dirvec;
	double y_dirvec;
	double camera_xpos;
	double camera_ypos;
	double	plane_ypos;
	double	plane_xpos;
	double	ray_xpos;
	double	ray_ypos;
	double	ray_xdir;
	double	ray_ydir;
	double	walldist;
	double xrot;
	double yrot;
	int		i;
	int		size;
	int		hit;
	int		bits;
	int		size;
	int		end;
	int		map_xpos;
	int		map_ypos;
	int		up;
	int		down;
	int		left;
	int		right;



}				t_env;
#endif
