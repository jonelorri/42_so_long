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
	if (key_code == 1 && m->y != 576) // S
	{
		m->y += 72; 
		mlx_put_image_to_window(m->mlx, m->win, m->imgZ, m->x, m->y);
		mlx_put_image_to_window(m->mlx, m->win, m->imgF, m->x, m->y -72);
		m->i = m->i + 1;
	}
	if (key_code == 2 && m->x != 1296) // D
	{
		m->x += 72;
		mlx_put_image_to_window(m->mlx, m->win, m->imgZ, m->x, m->y);
		mlx_put_image_to_window(m->mlx, m->win, m->imgF, m->x - 72, m->y);
		m->i = m->i + 1;
	}
	if (key_code == 13 && m->y != 72) // W
	{
		m->y += -72;
		mlx_put_image_to_window(m->mlx, m->win, m->imgZ, m->x, m->y);
		mlx_put_image_to_window(m->mlx, m->win, m->imgF, m->x, m->y + 72);
		m->i = m->i + 1;
	}
	if (key_code == 0 && m->x != 72) // A
	{
		m->x += -72;
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

	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, 1440, 720, "Hello World");
	m.imgF = mlx_xpm_file_to_image(m.mlx, "img/floor2.xpm", &m.iw, &m.ih);

	// MAPA
	m.imgF = mlx_xpm_file_to_image(m.mlx, "img/floor2.xpm", &m.iw, &m.ih);
	m.fd = open("./map.ber", O_RDONLY);	

	m.line = get_next_line(m.fd);
	while (m.line != NULL)
	{
		while (*m.line != '\n')
		{
			if (*m.line == '1' || *m.line == '0')
			{
				mlx_put_image_to_window(m.mlx, m.win, m.imgF, m.x, m.y);
				m.x = m.x + 72;
			}
			m.line++;
		}
		m.x = 0;
		m.y = m.y + 72;
		m.line = get_next_line(m.fd);
	}

	// DIBUJAR FONDO
/*	
	m.x = 0;
	m.y = 0;
	while (m.y < 720)
	{
		while (m.x < 1440)
		{
			mlx_put_image_to_window(m.mlx, m.win, m.imgF, m.x, m.y);
			m.x = m.x + 72;
		}
		m.x = 0;
		m.y = m.y + 72;
	}
	
	m.imgR = mlx_xpm_file_to_image(m.mlx, "img/rock.xpm", &m.iw, &m.ih);
	m.x = 0;
	m.y = 0;
	while (m.y < 720)
	{
		while (m.x < 1440 && m.y < 72 || m.y > 648) 
		{
			mlx_put_image_to_window(m.mlx, m.win, m.imgR, m.x, m.y);
			m.x = m.x + 72;
		}
		m.x = 0;
		m.y = m.y + 72;
	}
*/

	// EL ZORRO
	m.imgZ = mlx_xpm_file_to_image(m.mlx, "img/fox_front_72.xpm", &m.iw, &m.ih);	

	mlx_put_image_to_window(m.mlx, m.win, m.imgZ, 72,  72);
	m.x = 72;
	m.y = 72;
	m.i = 0;

	mlx_key_hook(m.win, &key_event, &m);

	mlx_loop(m.mlx);
}
