/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 03:04:33 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/19 03:04:38 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int 	calc_move(t_env *e)
{
	if (e->up == 1)
	{
		if(wolfmap[int(e->x_pos + e->x_dirvec * MV_SPEED)][int(e->ypos)] == 0)
      e->x_pos += e->x_dirvec * MV_SPD;
		if(wolfmap[int(e->xpos)][int(y_pos + e->y_dirvec * MV_SPD)] == 0)
      posY += dirY * moveSpeed;
	}
	if (e->down == 1)
	{
		if(wolfmap[int(e->x_pos - e->x_dirvec * MV_SPD)][int(e->y_pos)] == 0)
      e->x_pos -= e->x_dir * MV_SPD;
		if(wolfmap[int(e->x_pos)][int(e->y_pos - e->y_dirvec * MV_SPD)] == 0)
      e->y_pos -= e->y_dirvec * MV_SPD;
	}
}

int 	calc_rotate(t_env *e)
{
	if (e->left == 1)
	{
	  double oldDirX;
	  double oldPlaneX;

	  oldDirX = dirX;

      dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
      dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);

      oldPlaneX= planeX;
      planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
      planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
  	}
  	if (e->right == 1)
  	{
  		double oldDirX = dirX;
  		double oldPlaneX = planeX;

  		dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
  		dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
      planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
      planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
  	}
}

int 	calc_movement(t_env *e)
{
  calc_move(e);
  calc_rotate(e);
  return (0);
}

int 	krelease_hook(int keycode, t_env *e)
{
	if (keycode == K_UP)
		e->up = 0;
	else if (keycode == K _DWN)
		e->down = 0;
	else if (keycode == K_LFT)
		e->left = 0;
	else if (keycode == K_RGHT)
		e->right = 0;
	else if (keycode == K_ESC)
		exit(0);
}

int	key_press_hooks(int keycode, t_env *e)
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
		exit(0);
	return (0);
}
