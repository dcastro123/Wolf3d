/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 03:04:23 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/21 02:11:32 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static	void	dda_hit(t_env *e)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (e->x_sidedist < e->y_sidedist)
		{
			e->x_sidedist += e->x_deltadist;
			e->map_xpos += e->x_step;
			e->side = 0;
		}
		else
		{
			e->y_sidedist += e->y_deltadist;
			e->map_ypos += e->y_step;
			e->side = 1;
		}
		if (g_wolfmap[e->map_xpos][e->map_ypos] != 3)
			hit = 1;
		else
			hit = 0;
	}
}

static	void	dda_start(t_env *e)
{
	e->x_deltadist = sqrt(1 + (e->ray_ydir * e->ray_ydir)\
			/ (e->ray_xdir * e->ray_xdir));
	e->y_deltadist = sqrt(1 + (e->ray_xdir * e->ray_xdir)\
			/ (e->ray_ydir * e->ray_ydir));
	if (e->ray_xdir < 0)
	{
		e->x_step = -1;
		e->x_sidedist = (e->ray_xpos - e->map_xpos) * e->x_deltadist;
	}
	else
	{
		e->x_step = 1;
		e->x_sidedist = (e->map_xpos + 1.0 - e->ray_xpos) * e->x_deltadist;
	}
	if (e->ray_ydir < 0)
	{
		e->y_step = -1;
		e->y_sidedist = (e->ray_ypos - e->map_ypos) * e->y_deltadist;
	}
	else
	{
		e->y_step = 1;
		e->y_sidedist = (e->map_ypos + 1.0 - e->ray_ypos) * e->y_deltadist;
	}
}

static	void	ray_start(t_env *e)
{
	e->camera_xpos = 2 * e->x / (double)WINDOW_W - 1;
	e->ray_xpos = e->x_pos;
	e->ray_ypos = e->y_pos;
	e->ray_xdir = e->x_dirvec + e->plane_xpos * e->camera_xpos;
	e->ray_ydir = e->y_dirvec + e->plane_ypos * e->camera_xpos;
	e->map_xpos = (int)e->ray_xpos;
	e->map_ypos = (int)e->ray_ypos;
	dda_start(e);
	dda_hit(e);
	if (e->side == 0)
		e->walldist = (e->map_xpos - e->ray_xpos +\
				(1 - e->x_step) / 2) / e->ray_xdir;
	else
		e->walldist = (e->map_ypos - e->ray_ypos +\
				(1 - e->y_step) / 2) / e->ray_ydir;
}

void			raycast(t_env *e)
{
	e->x = -1;
	while (++e->x < WINDOW_W)
	{
		ray_start(e);
		e->line_h = (int)(WINDOW_H / e->walldist);
		e->start = -e->line_h / 2 + WINDOW_H / 2;
		if (e->start < 0)
			e->start = 0;
		e->end = e->line_h / 2 + WINDOW_H / 2;
		if (e->end >= WINDOW_H)
			e->end = WINDOW_H - 1;
		draw_line(e);
	}
	mlx_put_image_to_window(e->mlx, e->win, e->image, 0, 0);
}
