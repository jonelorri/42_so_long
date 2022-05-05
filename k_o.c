/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_o.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorria <jelorria@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:34:31 by jelorria          #+#    #+#             */
/*   Updated: 2022/05/05 19:59:11 by jelorria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "get_next_line.h"

int	case1(void *param)
{
	t_program	*m;

	m = param;
	if (m->mtrx[m->xz + 1][m->yz] == 'E' && m->collect == m->tocollect)
	{
		free(m->mtrx);
		exit(EXIT_SUCCESS);
	}
	if (m->mtrx[m->xz + 1][m->yz] == '1' || m->mtrx[m->xz + 1][m->yz] == 'E')
		return (1);
	if (m->mtrx[m->xz + 1][m->yz] == 'C')
	{
		m->collect += 1;
		m->mtrx[m->xz + 1][m->yz] = '0';
	}
	m->y += 72;
	m->xz += 1;
	mlx_put_image_to_window(m->mlx, m->win, m->imgz, m->x, m->y);
	mlx_put_image_to_window(m->mlx, m->win, m->imgf, m->x, m->y -72);
	m->i = m->i + 1;
	return (0);
}

int	case2(void *param)
{
	t_program	*m;

	m = param;
	if (m->mtrx[m->xz][m->yz + 1] == 'E' && m->collect == m->tocollect)
	{
		free(m->mtrx);
		exit(EXIT_SUCCESS);
	}
	if (m->mtrx[m->xz][m->yz + 1] == '1' || m->mtrx[m->xz][m->yz + 1] == 'E')
		return (1);
	if (m->mtrx[m->xz][m->yz + 1] == 'C')
	{
		m->collect += 1;
		m->mtrx[m->xz][m->yz + 1] = '0';
	}
	m->yz += 1;
	m->x += 72;
	mlx_put_image_to_window(m->mlx, m->win, m->imgz, m->x, m->y);
	mlx_put_image_to_window(m->mlx, m->win, m->imgf, m->x - 72, m->y);
	m->i = m->i + 1;
	return (0);
}

int	case3(void *param)
{
	t_program	*m;

	m = param;
	if (m->mtrx[m->xz - 1][m->yz] == 'E' && m->collect == m->tocollect)
	{
		free(m->mtrx);
		exit(EXIT_SUCCESS);
	}
	if (m->mtrx[m->xz - 1][m->yz] == '1' || m->mtrx[m->xz - 1][m->yz] == 'E')
		return (1);
	if (m->mtrx[m->xz - 1][m->yz] == 'C')
	{
		m->collect += 1;
		m->mtrx[m->xz - 1][m->yz] = '0';
	}
	m->xz -= 1;
	m->y += -72;
	mlx_put_image_to_window(m->mlx, m->win, m->imgz, m->x, m->y);
	mlx_put_image_to_window(m->mlx, m->win, m->imgf, m->x, m->y + 72);
	m->i = m->i + 1;
	return (0);
}

int	case4(void *param)
{
	t_program	*m;

	m = param;
	if (m->mtrx[m->xz][m->yz - 1] == 'E' && m->collect == m->tocollect)
	{
		free(m->mtrx);
		exit(EXIT_SUCCESS);
	}
	if (m->mtrx[m->xz][m->yz - 1] == '1' || m->mtrx[m->xz][m->yz - 1] == 'E')
		return (1);
	if (m->mtrx[m->xz][m->yz - 1] == 'C')
	{
		m->collect += 1;
		m->mtrx[m->xz][m->yz - 1] = '0';
	}
	m->x += -72;
	m->yz -= 1;
	mlx_put_image_to_window(m->mlx, m->win, m->imgz, m->x, m->y);
	mlx_put_image_to_window(m->mlx, m->win, m->imgf, m->x + 72, m->y);
	m->i = m->i + 1;
	return (0);
}
