#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int key_event(int key_code, void *param)
{
	
	t_program *m = param;
	if (key_code == 53)
	{
		mlx_destroy_window(m->mlx, m->win);
		exit (1);
	}
	else if (key_code == 1) // S
	{
		if (m->mtrx[m->x_ + 1][m->y_] == '1')
			return (1);	
		m->y += 72;
		m->x_ += 1;
		mlx_put_image_to_window(m->mlx, m->win, m->imgZ, m->x, m->y);
		mlx_put_image_to_window(m->mlx, m->win, m->imgF, m->x, m->y -72);
		m->i = m->i + 1;
	}
	else if (key_code == 2) // D
	{
		if (m->mtrx[m->x_][m->y_ + 1] == '1')
			return (1);
		m->y_ += 1;
		m->x += 72;
		mlx_put_image_to_window(m->mlx, m->win, m->imgZ, m->x, m->y);
		mlx_put_image_to_window(m->mlx, m->win, m->imgF, m->x - 72, m->y);
		m->i = m->i + 1;
	}
	else if (key_code == 13) // W
	{
		if (m->mtrx[m->x_ - 1][m->y_] == '1')
			return (1);
		m->x_ -= 1;
		m->y += -72;
		mlx_put_image_to_window(m->mlx, m->win, m->imgZ, m->x, m->y);
		mlx_put_image_to_window(m->mlx, m->win, m->imgF, m->x, m->y + 72);
		m->i = m->i + 1;
	}
	else if (key_code == 0) // A
	{
		if (m->mtrx[m->x_][m->y_ - 1] == '1')
			return (1);
		m->x += -72;
		m->y_ -= 1;
		mlx_put_image_to_window(m->mlx, m->win, m->imgZ, m->x, m->y);	
		mlx_put_image_to_window(m->mlx, m->win, m->imgF, m->x + 72, m->y);
		m->i = m->i + 1;
	}
	
	// CONTADOR
	printf("%d\n", m->i);
	
	return (m->i);
}

int	main()
{
	t_program m;

	//MAPA
	read_map(&m);

	// EL ZORRO
	m.imgZ = mlx_xpm_file_to_image(m.mlx, "img/fox_front_72.xpm", &m.iw, &m.ih);	

	mlx_put_image_to_window(m.mlx, m.win, m.imgZ, 72,  72);
	m.x = 72; //posicion visual en pixeles zorro
	m.x_ = 1; //posición en matriz del zorro
	m.y = 72;
	m.y_ = 1;
	m.i = 0;

	mlx_key_hook(m.win, &key_event, &m);

	mlx_loop(m.mlx);
}
