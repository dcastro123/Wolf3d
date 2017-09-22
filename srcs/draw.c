/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 03:05:37 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/21 17:45:47 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static	unsigned int	get_color(t_env *e)
{
	unsigned int color;

	if (g_wolfmap[e->map_xpos][e->map_ypos] == 1)
		color = YELLOW;
	else if (g_wolfmap[e->map_xpos][e->map_ypos] == 2)
		color = ORANGE;
	else if (g_wolfmap[e->map_xpos][e->map_ypos] == 6)
		color = RED;
	else if (g_wolfmap[e->map_xpos][e->map_ypos] == 8)
		color = BLUE;
	else
		color = BLACK;
	return (color);
}

void					draw_bg(t_env *e)
{
	int	i;

	i = 0;
	while (i < (e->size * WINDOW_H / 2))
	{
		e->data[i / 4] = SKYBLUE;
		i++;
	}
	while (i < (e->size * WINDOW_H))
	{
		e->data[i / 4] = 0x6e8b3d;
		i++;
	}
}

void					draw_line(t_env *e)
{
	while (++(e->start) < e->end)
	{
		if (e->x < 0 || e->start < 0 || e->x >= WINDOW_W\
				|| e->start >= WINDOW_H)
			break ;
		e->data[(int)((e->x * 4) + (e->start * e->size)) / 4] = get_color(e);
	}
}
