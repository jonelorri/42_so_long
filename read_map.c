#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int	*read_map(void *param)
{
	int	i;
	int	x;
	int	y;
	int	cont;

	cont = 0;
	t_program *m = param;
	m->mlx = mlx_init();
	m->fd = open("./map.ber", O_RDONLY);
	m->imgF = mlx_xpm_file_to_image(m->mlx, "img/floor2.xpm", &m->iw, &m->ih);
	m->imgR = mlx_xpm_file_to_image(m->mlx, "img/rock.xpm", &m->iw, &m->ih);
	m->imgZ = mlx_xpm_file_to_image(m->mlx, "img/fox_front_72.xpm", &m->iw, &m->ih);
	i = 0;
	x = 0;
	y = 0;
	m->contador = 0;
	m->line = get_next_line(m->fd);
	m->len = ft_strlen(m->line, 1);

	// SACAR TAMAÑO MATRIZ
	while (m->line[i] != '\0' && m->line[i] != '\n')
	{
		while (m->line[i] != '\n')
			i++;
		m->contador += 1;
		free(m->line);
		m->line = get_next_line(m->fd);
		i = 0;
		if (m->line == NULL || ft_strlen(m->line, 1) < 3)
			break;
	}
	
	// DAR MALLOC MATRIZ
	m->mtrx = (int **)malloc(m->len*sizeof(int*));
	while (i < m->len)
	{
		m->mtrx[i] = (int *)malloc(m->contador*sizeof(int*));
		i++;
	}
	i = 0;

	m->win = mlx_new_window(m->mlx, m->len * 72 - 72, m->contador * 72, "Game");

	// RELLENAR MARIZ Y DIBUJAR MAP
	close(m->fd);
	m->fd = open("./map.ber", O_RDONLY);
	free(m->line);
	m->line = get_next_line(m->fd);
	while (m->line[i] != '\0' && m->line[i] != '\n')
	{
		while (m->line[i] != '\n')
		{
			if (m->line[i] == '1')
			{
				mlx_put_image_to_window(m->mlx, m->win, m->imgR, x,  y);
				m->mtrx[cont][i] = '1';
			}
			if (m->line[i] == '0')
			{
				mlx_put_image_to_window(m->mlx, m->win, m->imgF, x, y);
				m->mtrx[cont][i] = '0';
			}
			x += 72;
			i++;
		}
		x = 0;
		y += 72;
		cont += 1;
		m->line = get_next_line(m->fd);
		i = 0;
		if (m->line == NULL || ft_strlen(m->line, 1) < 3)
			break;
	}
	printf("--> %c\n", m->mtrx[2][1]);
	return 0;
}
