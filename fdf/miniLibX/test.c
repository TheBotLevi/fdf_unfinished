/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:56:51 by ljeribha          #+#    #+#             */
/*   Updated: 2025/01/10 11:28:59 by ljeribha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	put_pixel_mlx(t_data *data, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && x < 100 && y < 600)
	{
		char	*dst;

		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

int	close_window(void *param)
{
	(void)param;
	printf("Window closed!\n");
	exit(0);
}

int	key_press(int keycode, void *param)
{
	(void)param;
	printf("Key pressed: %d\n", keycode);
	if (keycode == 65307)
	{
		printf("Exiting program!\n");
		exit(0);
	}
	return (0);
}

int	mouse_click(int button, int x, int y, void *param)
{
	(void)param;
	printf("Mouse button %d clicked at (%d, %d)\n",button, x, y );
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 600, "My World!");
	img.img = mlx_new_image(mlx, 1000, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	put_pixel_mlx(&img, 5, 5, 0x00FF0000);
	put_pixel_mlx(&img, 15, 5, 0x00FF0000);
	put_pixel_mlx(&img, 5, 15, 0x00FF0000);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 210, 210);

	mlx_hook(mlx_win, 17, 0, close_window, NULL);
	mlx_key_hook(mlx_win, key_press, NULL);
	mlx_mouse_hook(mlx_win, mouse_click, NULL);

	mlx_loop(mlx);
}
