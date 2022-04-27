#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int	key_event(int key_code, void *param)
{
	t_program *m = param;
	if (key_code == 53) 	
	{	
		free(m->mtrx);
		exit(EXIT_SUCCESS);	
	}
	else if (key_code == 1) // S
		case1(&*m);
	else if (key_code == 2) // D
		case2(&*m);
	else if (key_code == 13) // W
		case3(&*m);
	else if (key_code == 0) // A
		case4(&*m);
	printf("%d\n", m->i);
	return(m->i);
}

int	main(int argc, char **argv)
{
	t_program m;
	if (argc != 2)
		e_m(6);
	m.i = ft_strlen(argv[1], 1) - 1;
	if ((argv[1][m.i] != 'r') || (argv[1][m.i - 1] != 'e')
		|| (argv[1][m.i - 2] != 'b') || (argv[1][m.i - 3] != '.'))
		e_m(5);
	m.mlx = mlx_init();
	m.imgF = mlx_xpm_file_to_image(m.mlx, "img/floor2.xpm", &m.iw, &m.ih);
	m.imgR = mlx_xpm_file_to_image(m.mlx, "img/rock.xpm", &m.iw, &m.ih);
	m.imgZ = mlx_xpm_file_to_image(m.mlx, "img/fox_front_72.xpm", &m.iw, &m.ih);
	m.imgC = mlx_xpm_file_to_image(m.mlx, "img/donut.xpm", &m.iw, &m.ih);
	m.imgE = mlx_xpm_file_to_image(m.mlx, "img/home1.xpm", &m.iw, &m.ih);
	m.collect = 0;
	m.tocollect = 0;
	m.contador = 0;
	read_map(&m, &argv[1]);
	m.x = m.yZ * 72; //posicion visual en pixeles zorro
	m.y = m.xZ * 72;
	m.i = 0;
	mlx_key_hook(m.win, &key_event, &m);
	mlx_loop(m.mlx);
	return 0;
}
