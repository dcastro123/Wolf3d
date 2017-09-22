/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 20:44:17 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/21 17:25:36 by dcastro-         ###   ########.fr       */
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
# define ROT_SPEED	0.025
# define MV_SPEED	0.08

# define VEC_X_ROTLEFT(x, y)	x * cos(ROT_SPEED) - y * sin(ROT_SPEED)
# define VEC_Y_ROTLEFT(x, y)	x * sin(ROT_SPEED) + y * cos(ROT_SPEED)
# define VEC_X_ROTRIGHT(x, y)	x * cos(-ROT_SPEED) - y * sin(-ROT_SPEED)
# define VEC_Y_ROTRIGHT(x, y)	x * sin(-ROT_SPEED) + y * cos(-ROT_SPEED)

# define SKYBLUE	0x87ceeb
# define WHITE		0xf8f8ff
# define BROWN		0x8b4513
# define GREEN		0x228b22
# define BLUE		0x80
# define RED 		0xcd0000
# define BLACK		0x0

# define K_LFT		123
# define K_RGHT		124
# define K_UP 		126
# define K_DWN		125
# define K_ESC		53

typedef	struct	s_env
{
	void		*mlx;
	void		*win;
	char		*image;
	int			*data;
	int			**map;
	double		x_pos;
	double		y_pos;
	double		x_dirvec;
	double		y_dirvec;
	double		camera_xpos;
	double		camera_ypos;
	double		plane_ypos;
	double		plane_xpos;
	double		ray_xpos;
	double		ray_ypos;
	double		ray_xdir;
	double		ray_ydir;
	double		walldist;
	double		x_sidedist;
	double		y_sidedist;
	double		x_deltadist;
	double		y_deltadist;
	int			start;
	int			end;
	int			x_step;
	int			y_step;
	int			line_h;
	int			side;
	int			x;
	int			hit;
	int			bits;
	int			size;
	int			map_xpos;
	int			map_ypos;
	int			up;
	int			down;
	int			left;
	int			right;
}				t_env;

int				g_wolfmap[MAP_W][MAP_H];

void			print_controls(void);
void			setup_env(t_env *e);
void			destroy_everything(t_env *e);
void			init_window(t_env *e);
int				reset_img(t_env *e);
void			set_hooks(t_env *e);

int				calc_movement(t_env *e);
int				calc_move(t_env *e);
int				calc_rotate(t_env *e);
int				krelease_hooks(int keycode, t_env *e);
int				kpress_hooks(int keycode, t_env *e);
int				close_window_hook(t_env *e);

void			raycast(t_env *e);
void			draw_line(t_env *env);
void			draw_bg(t_env *e);
#endif
