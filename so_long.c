#include <mlx.h>

int	main()
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 640, 360, "Hello World");
	mlx_loop(mlx);
}
