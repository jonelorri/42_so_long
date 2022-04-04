#include <mlx.h>
#include <stdio.h>
#include <unistd.h>

typedef struct  s_program
{
    void	*mlx;
    void	*win;
	void	*imgZ;
	void	*imgF;
	int		x;
	int		y;
}               t_program;

int key_event(int key_code, void *param)
{
	t_program *main = param;
	printf("%d\n", key_code);
	if (key_code == 1)
	{
		main->y += 70;
		mlx_put_image_to_window(main->mlx, main->win, main->imgZ, main->x, main->y);
		mlx_put_image_to_window(main->mlx, main->win, main->imgF, main->x, main->y -70);
	}
	if (key_code == 2)
	{
		main->x += 70;
		mlx_put_image_to_window(main->mlx, main->win, main->imgZ, main->x, main->y);
		mlx_put_image_to_window(main->mlx, main->win, main->imgF, main->x - 70, main->y);
	}
	if (key_code == 13) // PARRIBA
	{
		main->y += -70;
		mlx_put_image_to_window(main->mlx, main->win, main->imgZ, main->x, main->y);
		mlx_put_image_to_window(main->mlx, main->win, main->imgF, main->x, main->y + 70);
	}
	//mlx_put_image_to_window(main->mlx, main->win, main->imgF, 0, 0);
	//mlx_put_image_to_window(main->mlx, main->win, main->imgZ, 0, 70);
	return 0;
}

int	main()
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		img_width;
	int		img_height;
	int		x;
	int		y;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1400, 700, "Hello World");
	img = mlx_xpm_file_to_image(mlx, "img/floor.xpm", &img_width, &img_height);

	t_program main;
	main.mlx = mlx;
	main.win = mlx_win;
	main.imgF = img;

	// DIBUJAR FONDO
	x = 0;
	y = 0;
	while (y < 700)
	{
		while (x < 1400)
		{
			mlx_put_image_to_window(mlx, mlx_win, img, x, y);
			x = x + 70;
		}
		x = 0;
		y = y + 70;
	}

	// EL ZORRO
	img = mlx_xpm_file_to_image(mlx, "img/fox_front_70x70.xpm", &img_width, &img_height);	
	
	main.imgZ = img;

	mlx_put_image_to_window(mlx, mlx_win, img, 0,  0);
	main.x = 0;
	main.y = 0;
	mlx_key_hook(mlx_win, &key_event, &main);

	mlx_loop(mlx);
}
