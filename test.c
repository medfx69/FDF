#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		i = 50;
	int		j = 50;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	while (i < 450)
	{
		mlx_pixel_put(mlx,mlx_win, i, j, 0xFFFFFF);
		i++;
	}
	while (j < 450)
	{
		mlx_pixel_put(mlx,mlx_win, i, j, 0xFFFFFF);
		j++;
	}
	while (i > 50)
	{
		mlx_pixel_put(mlx,mlx_win, i, j, 0xFFFFFF);
		i--;
	}
	while (j > 50)
	{
		mlx_pixel_put(mlx,mlx_win, i, j, 0xFFFFFF);
		j--;
	}
	
	mlx_loop(mlx);
}