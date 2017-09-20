/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 20:44:17 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/20 05:43:40 by dcastro-         ###   ########.fr       */
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
# define SKYBLUE
# define WHITE
# define BROWN
# define GREEN
# define BLUE
# define ROT_SPEED	0.060
# define MV_SPEED	0.12
# define K_LFT		123
# define K_RGHT		124
# define K_UP 		126
# define K_DWN		125
# define K_ESC		53

int wolfmap[MAP_W][MAP_H];

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
	double	x_sidedist;
	double	y_sidedist;
	double	x_deltadist;
	double	y_deltadist;
	int 	start;
	int 	end;
	int 	x_step;
	int 	y_step;
	int 	line_h;
	int 	side;
	int		x;
	int		hit;
	int		bits;
	int		size;
	int		map_xpos;
	int		map_ypos;
	int		up;
	int		down;
	int		left;
	int		right;



}				t_env;

void	print_controls(void);
void	setup_env(t_env *e);
void	destroy_struct(t_env *e);
void	init_window(t_env *e);
int 	reset_img(t_env *e);

int 	calc_movement(t_env *e);
int 	calc_move(t_env *e);
int 	calc_rotate(t_env *e);
int 	krelease_hooks(int keycode, t_env *e);
int		kpress_hooks(int keycode, t_env *e);
int 	close_window_hook(t_env *e);

void	raycast(t_env *e);
void	set_hooks(t_env *e);
#endif
