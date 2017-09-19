/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 20:43:17 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/19 04:42:20 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

/* Wolf3d map
** 1 is north
** 2 is west
** 3 is floor
** 6 is east
** 8 is south
** 4, 7, 5 is wall
*/

static int wolfmap[MAP_W][MAP_H] = {
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,8,0,8,0,0,0,6},
  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,6,0,0,0,6},
  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,6},
  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
  {2,8,8,8,8,8,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
  {2,2,0,1,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
  {2,2,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
  {2,2,0,8,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
  {2,2,0,1,1,1,1,1,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
  {2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
  {2,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
  {2,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8}
};

int 	get_color(t_env *e)
{
	int color;

	if (wolfmap[e->map_xpos][e->map_ypos] = 1)
		color = WHITE;
	else if (wolfmap[e->map_xpos][e->map_ypos] = 2)
		color = GREEN;
	else if (wolfmap[e->map_xpos][e->map_ypos] = 6)
		color = RED;
	else if (wolfmap[e->map_xpos][e->map_ypos] = 8)
		color = BLUE;
	else if (wolfmap[e->map_xpos][e->map_ypos] = 0)
		color = BROWN;
	return (color);
}

int 	close_window_hook(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
}

int 	calc_move(t_env *e)
{
	if (e->up == 1)
	{
		if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == 0) posX += dirX * moveSpeed;
		if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == 0) posY += dirY * moveSpeed;

	}
	if (e->down == 1)
	{
		if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
		if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
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

int 	calc_movement()
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

void	setup_env(t_env *e)
{
	e->x_pos = 22;
	e->y_pos = 12;
	e->x_dirvec = -1;
	e->y_dirvec = 0;
	e->camera_xpos = 0;
	e->plane_xpos = 0;
	e->plane_ypos = 0.66;
	e->xrot = 0.0;
	e->yrot = 0.0;
	e->rotSpeed = 1.2;
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

void		set_hooks(t_env *e)
{
	mlx_hook(e->win, 2, 0, key_press_hooks, e);
	mlx_hook(e->win, 3, 0, key_release_hook, e);
	mlx_hook(e->win, 17, 0, close_window_hook, e);
}

int	mouse_hooks(t_env *e, int button, int x, int y)
{







}

void	print_controls(void)
{
	ft_putendl("Controls: \n\
				Forward: UP arrow\n\
	Left: LEFT arrow     Right: RIGHT arrow\n\
				Down: DOWN arrow\n");
}

int	main(int ac, char **av)
{
	t_env *e;

	if (!(e = (t_env*)malloc(sizeof(t_env))))
		return (0);
	init_window(e);
	set_hooks(e);
	raycast(e);
	mlx_loop_hook(e->mlx, calc_movement, e);
	mlx_loop(e->mlx);
	double posX = 22, posY = 12;  //x and y start position
  	double dirX = -1, dirY = 0; //initial direction vector
  	double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane
  while(!done())
  {
    for(int x = 0; x < w; x++)
    {
      //calculate ray position and direction
      double cameraX = 2 * x / double(w) - 1; //x-coordinate in camera space
      double rayPosX = posX;
      double rayPosY = posY;
      double rayDirX = dirX + planeX * cameraX;
      double rayDirY = dirY + planeY * cameraX;
      //which box of the map we're in
      int mapX = int(rayPosX);
      int mapY = int(rayPosY);

      //length of ray from current position to next x or y-side
      double sideDistX;
      double sideDistY;

       //length of ray from one x or y-side to next x or y-side
      double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
      double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
      double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?
      //calculate step and initial sideDist
      if (rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (rayPosX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - rayPosX) * deltaDistX;
      }
      if (rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (rayPosY - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - rayPosY) * deltaDistY;
      }
      //perform DDA
      while (hit == 0)
      {
        //jump to next map square, OR in x-direction, OR in y-direction
        if (sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        if (worldMap[mapX][mapY] > 0) hit = 1;
      }
      //Calculate distance projected on camera direction (oblique distance will give fisheye effect!)
      if (side == 0) perpWallDist = (mapX - rayPosX + (1 - stepX) / 2) / rayDirX;
      else           perpWallDist = (mapY - rayPosY + (1 - stepY) / 2) / rayDirY;

      //Calculate height of line to draw on screen
      int lineHeight = (int)(h / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + h / 2;
      if(drawStart < 0)drawStart = 0;
      int drawEnd = lineHeight / 2 + h / 2;
      if(drawEnd >= h)drawEnd = h - 1;

      //choose wall color
      ColorRGB color;
      switch(worldMap[mapX][mapY])
      {
        case 1:  color = RGB_Red;  break; //red
        case 2:  color = RGB_Green;  break; //green
        case 3:  color = RGB_Blue;   break; //blue
        case 4:  color = RGB_White;  break; //white
        default: color = RGB_Yellow; break; //yellow
      }

      //give x and y sides different brightness
      if (side == 1) {color = color / 2;}

      //draw the pixels of the stripe as a vertical line
      verLine(x, drawStart, drawEnd, color);
    }
    redraw();
    cls();
  }







	return (0);
}
