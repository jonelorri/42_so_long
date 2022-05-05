/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorria <jelorria@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:49:07 by jelorria          #+#    #+#             */
/*   Updated: 2022/05/05 19:59:28 by jelorria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

void	adjusting(void *param)
{
	t_program	*m;

	m = param;
	m->con += 1;
	m->line = get_next_line(m->fd);
	m->i = 0;
}

void	give_malloc(void *param)
{
	t_program	*m;

	m = param;
	m->win = mlx_new_window(m->mlx, m->len * 72 - 72, m->con * 72, "Game");
	m->mtrx = (int **) malloc (m->len * sizeof(int *));
	while (m->i < m->len)
	{
		m->mtrx[m->i] = (int *) malloc (m->con * sizeof(int *));
		m->i++;
	}
	m->i = 0;
	m->con = 0;
}

void	mtrx_size(void *param)
{
	t_program	*m;

	m = param;
	if (m->fd == -1)
		e_m(6);
	m->line = get_next_line(m->fd);
	m->len = ft_strlen(m->line, 1);
	if (m->len < 3)
		e_m(6);
	while (m->line[m->i] != '\0' && m->line[m->i] != '\n')
	{
		while (m->line[m->i] != '\n')
			m->i++;
		m->con += 1;
		m->len1 = ft_strlen(m->line, 1);
		free(m->line);
		m->line = get_next_line(m->fd);
		m->i = 0;
		if (m->line == NULL || ft_strlen(m->line, 1) < 3)
			break ;
		m->len2 = ft_strlen(m->line, 1);
		if (m->len1 != m->len2)
			e_m(1);
	}
	give_malloc(&*m);
}

void	big_loop(void *param)
{
	t_program	*m;

	m = param;
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
		adjusting(&*m);
		if (m->line == NULL || ft_strlen(m->line, 1) < 3)
			break ;
	}	
}

int	*read_map(void *param, char **argv)
{
	t_program	*m;

	m = param;
	m->obj5 = 0;
	m->obj4 = 0;
	m->obj3 = 0;
	m->obj2 = 0;
	m->obj1 = 0;
	m->i = 0;
	m->fd = open(argv[0], O_RDONLY);
	mtrx_size(&*m);
	close(m->fd);
	m->fd = open(argv[0], O_RDONLY);
	free(m->line);
	m->line = get_next_line(m->fd);
	m->obj3 = 0;
	big_loop(&*m);
	free(m->line);
	rectangle(&*m);
	test_wall(&*m, &argv[0]);
	return (0);
}
