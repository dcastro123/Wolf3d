/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 03:04:33 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/21 17:31:48 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		calc_move(t_env *e)
{
	int	x_utemp;
	int	y_utemp;
	int	x_dtemp;
	int	y_dtemp;

	x_utemp = (int)(e->x_pos + e->x_dirvec * MV_SPEED);
	y_utemp = (int)(e->y_pos + e->y_dirvec * MV_SPEED);
	x_dtemp = (int)(e->x_pos - e->x_dirvec * MV_SPEED);
	y_dtemp = (int)(e->y_pos - e->y_dirvec * MV_SPEED);
	if (e->up == 1)
	{
		if (g_wolfmap[x_utemp][(int)(e->y_pos)] == 3)
			e->x_pos += e->x_dirvec * MV_SPEED;
		if (g_wolfmap[(int)(e->x_pos)][y_utemp] == 3)
			e->y_pos += e->y_dirvec * MV_SPEED;
	}
	if (e->down == 1)
	{
		if (g_wolfmap[x_dtemp][(int)(e->y_pos)] == 3)
			e->x_pos -= e->x_dirvec * MV_SPEED;
		if (g_wolfmap[(int)(e->x_pos)][y_dtemp] == 3)
			e->y_pos -= e->y_dirvec * MV_SPEED;
	}
	return (0);
}

int		calc_rotate(t_env *e)
{
	double x_dirtemp;
	double x_planetemp;

	x_dirtemp = e->x_dirvec;
	if (e->left == 1)
	{
		e->x_dirvec = VEC_X_ROTLEFT(e->x_dirvec, e->y_dirvec);
		e->y_dirvec = VEC_Y_ROTLEFT(x_dirtemp, e->y_dirvec);
		x_planetemp = e->plane_xpos;
		e->plane_xpos = VEC_X_ROTLEFT(e->plane_xpos, e->plane_ypos);
		e->plane_ypos = VEC_Y_ROTLEFT(x_planetemp, e->plane_ypos);
	}
	if (e->right == 1)
	{
		e->x_dirvec = VEC_X_ROTRIGHT(e->x_dirvec, e->y_dirvec);
		e->y_dirvec = VEC_Y_ROTRIGHT(x_dirtemp, e->y_dirvec);
		x_planetemp = e->plane_xpos;
		e->plane_xpos = VEC_X_ROTRIGHT(e->plane_xpos, e->plane_ypos);
		e->plane_ypos = VEC_Y_ROTRIGHT(x_planetemp, e->plane_ypos);
	}
	return (0);
}

int		krelease_hooks(int keycode, t_env *e)
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

int		kpress_hooks(int keycode, t_env *e)
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
		destroy_everything(e);
	return (0);
}

int		calc_movement(t_env *e)
{
	if ((int)(e->x_pos + e->x_dirvec * MV_SPEED) < WINDOW_W &&\
		(int)(e->y_pos + e->y_dirvec * MV_SPEED) < WINDOW_H)
	{
		calc_move(e);
		calc_rotate(e);
		reset_img(e);
	}
	return (0);
}
