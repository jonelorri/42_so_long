#include <mlx.h>
#include <stdio.h>

int	main()
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int	img_width;
	int	img_height;
	int	x;
	int	y;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1400, 700, "Hello World");
	img = mlx_xpm_file_to_image(mlx, "img/floor.xpm", &img_width, &img_height);
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
	img = mlx_xpm_file_to_image(mlx, "img/fox_front_70x70.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, 0,  0);
	mlx_loop(mlx);
}
