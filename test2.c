/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:30:03 by ljeribha          #+#    #+#             */
/*   Updated: 2024/12/30 13:00:55 by ljeribha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	put_pixel_mlx(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	t_data	*img;

	mlx = mlx_init();
	img->img = mlx_new_image(mlx, 1920, 1080);

	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, img->endian);
}
