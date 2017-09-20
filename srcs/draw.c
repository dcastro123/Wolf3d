/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 03:05:37 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/20 05:22:09 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes/wolf3d.h"

/*
** Gets color from current mapx and mapy position
**
*/

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
	else if (wolfmap[e->map_xpos][e->map_ypos] = 3)
		color = BROWN;
	return (color);
}

/*
** Draws the Sky color and the Floor color
**
*/

// static void	draw_misc(t_env *e)
// {
// 	int		i;
// 	int		j;
// 	int		y;

// 	i = -1;
// 	while (++i < (e->size * WINDOW_H / 2))
// 	{
// 		e->data[]
// }