/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 03:56:55 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/23 22:16:51 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	destroy_everything(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
}

int		reset_img(t_env *e)
{
	mlx_destroy_image(e->mlx, e->image);
	e->image = mlx_new_image(e->mlx, WINDOW_W, WINDOW_H);
	e->data = (int*)mlx_get_data_addr(e->image, &e->bits, &e->size, &e->end);
	draw_bg(e);
	raycast(e);
	return (0);
}

void	setup_env(t_env *e)
{
	e->side = 0;
	e->x_pos = 22;
	e->y_pos = 12;
	e->x_dirvec = -1;
	e->y_dirvec = 0;
	e->camera_xpos = 0;
	e->plane_xpos = 0;
	e->plane_ypos = 0.66;
	e->left = 0;
	e->right = 0;
	e->down = 0;
	e->up = 0;
}

void	init_window(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WINDOW_W, WINDOW_H, "Wolf3d");
	e->image = mlx_new_image(e->mlx, WINDOW_W, WINDOW_H);
	e->data = (int*)mlx_get_data_addr(e->image, &e->bits, &e->size, &e->end);
	setup_env(e);
}

void	set_hooks(t_env *e)
{
	mlx_hook(e->win, 2, 0, kpress_hooks, e);
	mlx_hook(e->win, 3, 0, krelease_hooks, e);
	mlx_hook(e->win, 17, 0, close_window_hook, e);
}
