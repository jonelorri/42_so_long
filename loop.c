/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelorria <jelorria@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:45:03 by jelorria          #+#    #+#             */
/*   Updated: 2022/05/05 19:58:42 by jelorria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "get_next_line.h"

void	loop1(void *param)
{
	t_program	*m;

	m = param;
	mlx_put_image_to_window(m->mlx, m->win, m->imgr, m->i * 72, m->con * 72);
	m->mtrx[m->con][m->i] = '1';
	m->obj1 = 1;
}

void	loop2(void *param)
{
	t_program	*m;

	m = param;
	mlx_put_image_to_window(m->mlx, m->win, m->imgf, m->i * 72, m->con * 72);
	m->mtrx[m->con][m->i] = '0';
	m->obj2 = 1;
}

void	loop3(void *param)
{
	t_program	*m;

	m = param;
	mlx_put_image_to_window(m->mlx, m->win, m->imgf, m->i * 72, m->con * 72);
	mlx_put_image_to_window(m->mlx, m->win, m->imgz, m->i * 72, m->con * 72);
	m->xz = m->con;
	m->yz = m->i;
	m->obj3++;
	if (m->obj3 > 1)
		e_m(3);
}

void	loop4(void *param)
{
	t_program	*m;

	m = param;
	mlx_put_image_to_window(m->mlx, m->win, m->imgf, m->i * 72, m->con * 72);
	mlx_put_image_to_window(m->mlx, m->win, m->imgc, m->i * 72, m->con * 72);
	m->mtrx[m->con][m->i] = 'C';
	m->tocollect += 1;
	m->obj4 = 1;
}

void	loop5(void *param)
{
	t_program	*m;

	m = param;
	mlx_put_image_to_window(m->mlx, m->win, m->imgf, m->i * 72, m->con * 72);
	mlx_put_image_to_window(m->mlx, m->win, m->imge, m->i * 72, m->con * 72);
	m->mtrx[m->con][m->i] = 'E';
	m->obj5 = 1;
}
