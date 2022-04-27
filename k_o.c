#include <mlx.h>
#include "get_next_line.h"

int	case1(void *param)
{
	t_program *m = param;
	if (m->mtrx[m->xZ + 1][m->yZ] == 'E' && m->collect == m->tocollect)
	{
		free(m->mtrx);
		exit(EXIT_SUCCESS);
	}
	if (m->mtrx[m->xZ + 1][m->yZ] == '1' || m->mtrx[m->xZ + 1][m->yZ] == 'E')
		return (1);
	if (m->mtrx[m->xZ + 1][m->yZ] == 'C')
	{
		m->collect += 1;
		m->mtrx[m->xZ + 1][m->yZ] = '0';
	}
	m->y += 72;
	m->xZ += 1;
	mlx_put_image_to_window(m->mlx, m->win, m->imgZ, m->x, m->y);
	mlx_put_image_to_window(m->mlx, m->win, m->imgF, m->x, m->y -72);
	m->i = m->i + 1;
	return 0;
}

int	case2(void *param)
{
	t_program *m = param;
	if (m->mtrx[m->xZ][m->yZ + 1] == 'E' && m->collect == m->tocollect)
	{
		free(m->mtrx);
		exit(EXIT_SUCCESS);
	}
	if (m->mtrx[m->xZ][m->yZ + 1] == '1' || m->mtrx[m->xZ][m->yZ + 1] == 'E')
		return(1);
	if (m->mtrx[m->xZ][m->yZ + 1] == 'C')
	{
		m->collect += 1;
		m->mtrx[m->xZ][m->yZ + 1] = '0';
	}
	m->yZ += 1;
	m->x += 72;
	mlx_put_image_to_window(m->mlx, m->win, m->imgZ, m->x, m->y);
	mlx_put_image_to_window(m->mlx, m->win, m->imgF, m->x - 72, m->y);
	m->i = m->i + 1;
	return 0;
}

int	case3(void *param)
{
	t_program *m = param;
	if (m->mtrx[m->xZ - 1][m->yZ] == 'E' && m->collect == m->tocollect)
	{
		free(m->mtrx);
		exit(EXIT_SUCCESS);
	}
	if (m->mtrx[m->xZ - 1][m->yZ] == '1' || m->mtrx[m->xZ - 1][m->yZ] == 'E')
		return(1);
	if (m->mtrx[m->xZ - 1][m->yZ] == 'C')
	{
		m->collect += 1;
		m->mtrx[m->xZ - 1][m->yZ] = '0';
	}
	m->xZ -= 1;
	m->y += -72;
	mlx_put_image_to_window(m->mlx, m->win, m->imgZ, m->x, m->y);
	mlx_put_image_to_window(m->mlx, m->win, m->imgF, m->x, m->y + 72);
	m->i = m->i + 1;
	return 0;
}

int	case4(void *param)
{
	t_program *m = param;
	if (m->mtrx[m->xZ][m->yZ - 1] == 'E' && m->collect == m->tocollect)
	{
		free(m->mtrx);
		exit(EXIT_SUCCESS);
	}
	if (m->mtrx[m->xZ][m->yZ - 1] == '1' || m->mtrx[m->xZ][m->yZ - 1] == 'E')
		return (1);
	if (m->mtrx[m->xZ][m->yZ - 1] == 'C')
	{
		m->collect += 1;
		m->mtrx[m->xZ][m->yZ - 1] = '0';
	}
	m->x += -72;
	m->yZ -= 1;
	mlx_put_image_to_window(m->mlx, m->win, m->imgZ, m->x, m->y);
	mlx_put_image_to_window(m->mlx, m->win, m->imgF, m->x + 72, m->y);
	m->i = m->i + 1;
	return 0;
}
