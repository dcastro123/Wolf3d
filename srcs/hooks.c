/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 03:04:33 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/20 05:43:28 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int 	calc_move(t_env *e)
{
	int	x_temp;
	int	y_temp;

	x_temp = (int)(e->x_pos + e->x_dirvec * MV_SPEED);
	y_temp = (int)(e->y_pos + e->y_dirvec * MV_SPEED);
	if (e->up == 1)
	{
		if (wolfmap[x_temp][(int)(e->y_pos)] == 0)
			e->x_pos += e->x_dirvec * MV_SPEED;
		if (wolfmap[(int)(e->x_pos)][y_temp] == 0)
			e->y_pos += e->y_dirvec * MV_SPEED;
	}
	if (e->down == 1)
	{
		if (wolfmap[x_temp][(int)(e->y_pos)] == 0)
			e->x_pos -= e->x_dirvec * MV_SPEED;
		if (wolfmap[(int)(e->x_pos)][y_temp] == 0)
			e->y_pos -= e->y_dirvec * MV_SPEED;
	}
	return (0);
}

int 	calc_rotate(t_env *e)
{
	if (e->left == 1)
	{
		double x_dirtemp;
		double x_planetemp;

		x_dirtemp = e->x_dirvec;

		e->x_dirvec = e->x_dirvec * cos(ROT_SPEED) - e->y_dirvec * sin(ROT_SPEED);
		e->y_dirvec = x_dirtemp * sin(ROT_SPEED) + e->y_dirvec * cos(ROT_SPEED);
		x_planetemp= e->plane_xpos;
		e->plane_xpos = e->plane_xpos * cos(ROT_SPEED) - e->plane_ypos * sin(ROT_SPEED);
		e->plane_ypos = x_planetemp * sin(ROT_SPEED) + e->plane_ypos * cos(ROT_SPEED);
	}
	if (e->right == 1)
	{
		double x_dirtemp = e->x_dirvec;
		double x_planetemp = e->plane_xpos;

		e->x_dirvec = e->x_dirvec * cos(-ROT_SPEED) - e->y_dirvec * sin(-ROT_SPEED);
		e->y_dirvec = x_dirtemp * sin(-ROT_SPEED) + e->y_dirvec * cos(-ROT_SPEED);
		e->plane_xpos = e->plane_xpos * cos(-ROT_SPEED) - e->plane_ypos * sin(-ROT_SPEED);
		e->plane_ypos = x_planetemp * sin(-ROT_SPEED) + e->plane_ypos * cos(-ROT_SPEED);
	}
	return (0);
}

int 	krelease_hooks(int keycode, t_env *e)
{
	if (keycode == K_UP)
		e->up = 0;
	else if (keycode == K_DWN)
		e->down = 0;
	else if (keycode == K_LFT)
		e->left = 0;
	else if (keycode == K_RGHT)
		e->right = 0;
	else if (keycode == K_ESC)
		exit(0);
	return (0);
}

int	kpress_hooks(int keycode, t_env *e)
{
	if (keycode == K_UP)
		e->up = 1;
	else if (keycode == K_DWN)
		e->down = 1;
	else if (keycode == K_LFT)
		e->left = 1;
	else if (keycode == K_RGHT)
		e->right = 1;
	else if (keycode == K_ESC)
		destroy_struct(e);
	return (0);
}

int 	calc_movement(t_env *e)
{
	calc_move(e);
	calc_rotate(e);
	reset_img(e);
	return (0);
}
