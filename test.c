/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:56:51 by ljeribha          #+#    #+#             */
/*   Updated: 2024/12/30 13:36:30 by ljeribha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	put_pixel_mlx(t_data *data, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && x < 1920 && y < 1080)
	{
		char	*dst;

		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 600, "Hello world!");
	img.img = mlx_new_image(mlx, 1000, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	put_pixel_mlx(&img, 5, 5, 0x00FFFF00);
	put_pixel_mlx(&img, 10, 5, 0x0000FF00);
	put_pixel_mlx(&img, 5, 10, 0x000000FF);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
