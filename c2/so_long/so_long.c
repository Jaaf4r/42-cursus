#include "so_long.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	mlx_testing(t_data *img)
{
	void	*mlx;
	void	*mlx_win;
	void    *image;

	mlx = mlx_init();
	if (!mlx)
		return ;
	
	mlx_win = mlx_new_window(mlx, 500, 250, "Btata");
	if (!mlx_win)
	{
		// Clean up and return if window creation fails
		mlx_destroy_display(mlx);
		free(mlx);
		return ;
	}

	// Create a new image
	image = mlx_new_image(mlx, 500, 250);
	if (!image)
	{
		mlx_destroy_window(mlx, mlx_win);
		mlx_destroy_display(mlx);
		free(mlx);
		return ;
	}

	// Store the image pointer
	img->img = image;
	
	// Get the image data address
	img->addr = mlx_get_data_addr(img->img,
		&img->bits_per_pixel, &img->line_length, &img->endian);

	// Draw a red pixel at position (5,5)
	my_mlx_pixel_put(img, 5, 5, 0x00FF0000);

	// Put the image to window
	mlx_put_image_to_window(mlx, mlx_win, img->img, 5, 5);

	// If you want to load a PNG file, use mlx_xpm_file_to_image instead
	// void *sprite;
	int width, height;
	/*sprite = */mlx_xpm_file_to_image(mlx, "path_to_xpm_file", &width, &height);

	mlx_loop(mlx);
}

int	main(int ac, char **av)
{
	t_game	tool;
	t_data	img;

	ft_bzero(&tool, sizeof(t_game));
	if (ac != 2 || !valid_map_file(av[1], &tool))
		return (1);
	road_check(&tool);
	mlx_testing(&img);
	ft_putstr_fd("NOICE HEHE\n", 1);
	free_arr2d(tool.map_2d);
	return (0);
}
