/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 20:43:17 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/18 02:06:34 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Wolf3d.h"

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

int	parse_file(t_env *e, char *s)
{
	int	fd;
	char *line;

	if ((fd = open(s, O_RDONLY)) < 0)
		ft_error("Unable to open\n");
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{

	}
}

int	main(int ac, char **av)
{










	return (0);
}
