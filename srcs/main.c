/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 20:43:17 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/18 18:40:19 by dcastro-         ###   ########.fr       */
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
static int 	wolfmap[20][20] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6},
	{2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 6},
	{2, 4, 4, 3, 3, 3, 3, 5, 5, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 6},
	{2, 4, 4, 3, 3, 3, 3, 5, 5, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 6},
	{2, 3, 3, 3, 3, 3, 3, 5, 5, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 6},
	{2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 6},
	{2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 6},
	{2, 7, 7, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 6},
	{2, 7, 7, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 6},
	{2, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 6},
	{2, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 6},
	{2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 6},
	{2, 4, 4, 3, 3, 3, 3, 5, 5, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 6},
	{2, 4, 4, 3, 3, 3, 3, 5, 5, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 6},
	{2, 3, 3, 3, 3, 3, 3, 5, 5, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 6},
	{2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 6},
	{2, 7, 7, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 6},
	{2, 7, 7, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 6},
	{2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 6},
	{2, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
};

void	setup_env(t_env *e)
{
	e->x_pos = 22;
	e->y_pos = 12;
	e->x_dir = -1;
	e->y_dir = 0;
	e->camera_x = 0;
	e->camera_y = 0.66; 





}

void	init_window(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WINDOW_W, WINDHOW_H, "Wolf3d");
	e->img = mlx_get_data_addr(e->image, &e->bits, &e->size, &e->end);
	setup_env(e);
}
int	key_hooks(int keycode, t_env *e)
{
	if (keycode == K_ESC)
		exit(0);
	else if (keycode == K_UP)
		e->move_x -= .10;
	else if (keycode == K_DWN)
		e->move_x += .10;
	return (0);
}

int	mouse_hooks(t_env *e, int button, int x, int y)
{







}

void	store_map(t_env *e, char *s)
{









}

int	check_map(t_env *e, int fd)
{








}

int	check_file(t_env *e, char *s)
{
	int	fd;

	if ((fd = open(s, O_RDONLY)) < 0)
		ft_error("Unable to open\n");
	if (!s)
		ft_error("No argument passed");
	if (!check_map(e,fd))
		ft_error("Invalid Map");
	return (1);
}

int	main(int ac, char **av)
{
	printf("wolf at [1][1]: %d\n", wolfmap[1][1]);
	ac = 1;
	av = NULL;








	return (0);
}
