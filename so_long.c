#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	*get_next_line(int fd);

typedef struct  s_program
{
	void	*mlx;
	void	*win;
	void	*imgZ;
	void	*imgF;
	int	x;
	int	y;
	int	i;
}               t_program;

int key_event(int key_code, void *param)
{
	t_program *main = param;
	if (key_code == 53)
	{
		mlx_destroy_window(main->mlx, main->win);
		exit (1);
	}
	if (key_code == 1 && main->y != 576) // S
	{
		main->y += 72; 
		mlx_put_image_to_window(main->mlx, main->win, main->imgZ, main->x, main->y);
		mlx_put_image_to_window(main->mlx, main->win, main->imgF, main->x, main->y -72);
		main->i = main->i + 1;
	}
	if (key_code == 2 && main->x != 1296) // D
	{
		main->x += 72;
		mlx_put_image_to_window(main->mlx, main->win, main->imgZ, main->x, main->y);
		mlx_put_image_to_window(main->mlx, main->win, main->imgF, main->x - 72, main->y);
		main->i = main->i + 1;
	}
	if (key_code == 13 && main->y != 72) // W
	{
		main->y += -72;
		mlx_put_image_to_window(main->mlx, main->win, main->imgZ, main->x, main->y);
		mlx_put_image_to_window(main->mlx, main->win, main->imgF, main->x, main->y + 72);
		main->i = main->i + 1;
	}
	if (key_code == 0 && main->x != 72) // A
	{
		main->x += -72;
		mlx_put_image_to_window(main->mlx, main->win, main->imgZ, main->x, main->y);			
		mlx_put_image_to_window(main->mlx, main->win, main->imgF, main->x + 72, main->y);
		main->i = main->i + 1;
	}
	
	// CONTADOR
	printf("%d\n", main->i);
	
	return (main->i);
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
	int		fd;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1440, 720, "Hello World");
	img = mlx_xpm_file_to_image(mlx, "img/floor2.xpm", &img_width, &img_height);

	// LEER MAPA
	fd = open("./map.ber", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));	
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));

	t_program main;
	main.mlx = mlx;
	main.win = mlx_win;
	main.imgF = img;

	// DIBUJAR FONDO
	x = 0;
	y = 0;
	while (y < 720)
	{
		while (x < 1440)
		{
			mlx_put_image_to_window(mlx, mlx_win, img, x, y);
			x = x + 72;
		}
		x = 0;
		y = y + 72;
	}
	
	img = mlx_xpm_file_to_image(mlx, "img/rock.xpm", &img_width, &img_height);
	x = 0;
	y = 0;
	while (y < 720)
	{
		while (x < 1440 && y < 72 || y > 648) 
		{
			mlx_put_image_to_window(mlx, mlx_win, img, x, y);
			x = x + 72;
		}
		x = 0;
		y = y + 72;
	}

	// EL ZORRO
	img = mlx_xpm_file_to_image(mlx, "img/fox_front_72.xpm", &img_width, &img_height);	
	
	main.imgZ = img;

	mlx_put_image_to_window(mlx, mlx_win, img, 72,  72);
	main.x = 72;
	main.y = 72;
	main.i = 0;
	mlx_key_hook(mlx_win, &key_event, &main);

	mlx_loop(mlx);
}
