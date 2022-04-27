#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

void	give_malloc(void *param)
{
	t_program *m = param;
	m->win = mlx_new_window(m->mlx, m->len * 72 - 72, m->contador * 72, "Game");
	m->mtrx = (int **)malloc(m->len*sizeof(int*));
	while (m->i < m->len)
	{
		m->mtrx[m->i] = (int *)malloc(m->contador*sizeof(int*));
		m->i++;
	}
	m->i = 0;
	m->contador = 0;
}

void	mtrx_size(void *param, char **argv)
{
	t_program *m = param;
	m->fd = open(argv[0], O_RDONLY);
	if (m->fd == -1)
		e_m(6);
	m->i = 0;
	m->line = get_next_line(m->fd);
	m->len = ft_strlen(m->line, 1);
	if (m->len < 3)
		e_m(6);
	while (m->line[m->i] != '\0' && m->line[m->i] != '\n')
	{
		while (m->line[m->i] != '\n')
			m->i++;
		m->contador += 1;
		m->len1 = ft_strlen(m->line, 1);
		free(m->line);
		m->line = get_next_line(m->fd);
		m->i = 0;
		if (m->line == NULL || ft_strlen(m->line, 1) < 3)
			break;
		m->len2 = ft_strlen(m->line, 1);
		if (m->len1 != m->len2)
			e_m(1);
	}
	give_malloc(&*m);
}

void	big_loop(void *param)
{
	t_program *m = param;
	m->obj3 = 0;
	while (m->line[m->i] != '\0' && m->line[m->i] != '\n')
	{
		while (m->line[m->i] != '\n')
		{
			if (m->line[m->i] == '1')
				loop1(&*m);
			else if (m->line[m->i] == '0')
				loop2(&*m);
			else if (m->line[m->i] == 'P')
				loop3(&*m);
			else if (m->line[m->i] == 'C')
				loop4(&*m);
			else if (m->line[m->i] == 'E')
				loop5(&*m);
			else
				e_m(0);
			m->i++;
		}
		m->contador += 1;
		m->line = get_next_line(m->fd);
		m->i = 0;
		if (m->line == NULL || ft_strlen(m->line, 1) < 3)
			break;
	}	
}

int	*read_map(void *param, char **argv)
{
	t_program *m = param;
	mtrx_size(&*m, &argv[0]);
	close(m->fd);
	m->fd = open(argv[0], O_RDONLY);
	free(m->line);
	m->line = get_next_line(m->fd);
	big_loop(&*m);
	free(m->line);
	rectangle(&*m);
	test_wall(&*m, &argv[0]);
	return 0;
}
