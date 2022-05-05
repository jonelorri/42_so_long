/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorria <jelorria@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:24:37 by jelorria          #+#    #+#             */
/*   Updated: 2022/05/05 20:24:38 by jelorria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int	key_event(int key_code, void *param)
{
	t_program	*m;

	m = param;
	if (key_code == 53)
	{	
		free(m->mtrx);
		exit(EXIT_SUCCESS);
	}
	else if (key_code == 1)
		case1(&*m);
	else if (key_code == 2)
		case2(&*m);
	else if (key_code == 13)
		case3(&*m);
	else if (key_code == 0)
		case4(&*m);
	printf("%d\n", m->i);
	return (m->i);
}

int	main(int argc, char **argv)
{
	t_program	m;

	if (argc != 2)
		e_m(6);
	m.i = ft_strlen(argv[1], 1) - 1;
	if ((argv[1][m.i] != 'r') || (argv[1][m.i - 1] != 'e')
		|| (argv[1][m.i - 2] != 'b') || (argv[1][m.i - 3] != '.'))
		e_m(5);
	m.mlx = mlx_init();
	m.imgf = mlx_xpm_file_to_image(m.mlx, "img/floor2.xpm", &m.iw, &m.ih);
	m.imgr = mlx_xpm_file_to_image(m.mlx, "img/rock.xpm", &m.iw, &m.ih);
	m.imgz = mlx_xpm_file_to_image(m.mlx, "img/fox_front_72.xpm", &m.iw, &m.ih);
	m.imgc = mlx_xpm_file_to_image(m.mlx, "img/donut.xpm", &m.iw, &m.ih);
	m.imge = mlx_xpm_file_to_image(m.mlx, "img/home1.xpm", &m.iw, &m.ih);
	m.collect = 0;
	m.tocollect = 0;
	m.con = 0;
	read_map(&m, &argv[1]);
	m.x = m.yz * 72;
	m.y = m.xz * 72;
	m.i = 0;
	mlx_key_hook(m.win, &key_event, &m);
	mlx_loop(m.mlx);
	return (0);
}
