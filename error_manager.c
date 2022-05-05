/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorria <jelorria@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:09:11 by jelorria          #+#    #+#             */
/*   Updated: 2022/05/05 19:58:26 by jelorria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

void	e_m(int cont)
{
	if (cont == 0)
		printf("Error\nOnly allowed '0', '1', 'P', 'E' and 'C'\n");
	if (cont == 1)
		printf("Error\nNot a rectangle\n");
	if (cont == 2)
		printf("Error\nIs not surrounded by '1'\n");
	if (cont == 3)
		printf("Error\nOnly one Character is allowed\n");
	if (cont == 4)
		printf("Error\nNo Character\n");
	if (cont == 5)
		printf("Error\nIt is not a '.ber' file\n");
	if (cont == 6)
		printf("Error\nEnter a file\n");
	if (cont == 9)
		printf("Error\nIt is empty\n");
	exit(EXIT_SUCCESS);
}

void	rectangle(void *param)
{
	t_program	*m;

	m = param;
	if (m->obj1 + m->obj2 + m->obj3 + m->obj4 + m->obj5 != 5)
		e_m(0);
}

void	wall_case(void *param, int cont)
{
	t_program	*m;

	m = param;
	if (cont == 0 || cont == m->con - 1)
	{
		if (m->line[m->i] != '1')
		{
			free(m->line);
			e_m(2);
		}
	}
	else if (m->i == 0 || m->i == m->len - 2)
	{
		if (m->line[m->i] != '1')
		{
			free(m->line);
			e_m(2);
		}
	}
	m->i++;
}

void	test_wall(void *param, char **argv)
{
	int			cont;
	t_program	*m;

	m = param;
	m->i = 0;
	cont = 0;
	close(m->fd);
	m->fd = open(argv[0], O_RDONLY);
	m->line = get_next_line(m->fd);
	while (cont <= m->con - 1)
	{
		while (m->line[m->i] != '\0' && m->line[m->i] != '\n')
			wall_case(&*m, cont);
		free(m->line);
		m->line = get_next_line(m->fd);
		m->i = 0;
		cont++;
	}
	free(m->line);
}
