#include <mlx.h>
#include "get_next_line.h"

void	loop1(void *param)
{
	t_program *m = param;
	mlx_put_image_to_window(m->mlx, m->win, m->imgR, m->i * 72, m->contador * 72);
	m->mtrx[m->contador][m->i] = '1';
	m->obj1 = 1;
}

void	loop2(void *param)
{
	t_program *m = param;
	mlx_put_image_to_window(m->mlx, m->win, m->imgF, m->i * 72, m->contador * 72);
	m->mtrx[m->contador][m->i] = '0';
	m->obj2 = 1;
}

void	loop3(void *param)
{
	t_program *m = param;
	mlx_put_image_to_window(m->mlx, m->win, m->imgF, m->i * 72, m->contador * 72);
	mlx_put_image_to_window(m->mlx, m->win, m->imgZ, m->i * 72, m->contador * 72);
	m->xZ = m->contador;
	m->yZ = m->i;
	m->obj3++;
	if (m->obj3 > 1)
		e_m(3);
}

void	loop4(void *param)
{
	t_program *m = param;
	mlx_put_image_to_window(m->mlx, m->win, m->imgF, m->i * 72, m->contador * 72);
	mlx_put_image_to_window(m->mlx, m->win, m->imgC, m->i * 72, m->contador * 72);
	m->mtrx[m->contador][m->i] = 'C';
	m->tocollect += 1;
	m->obj4 = 1;
}

void	loop5(void *param)
{
	t_program *m = param;
	mlx_put_image_to_window(m->mlx, m->win, m->imgF, m->i * 72, m->contador * 72);
	mlx_put_image_to_window(m->mlx, m->win, m->imgE, m->i * 72, m->contador * 72);
	m->mtrx[m->contador][m->i] = 'E';
	m->obj5 = 1;
}
