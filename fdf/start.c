/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:28:38 by ljeribha          #+#    #+#             */
/*   Updated: 2025/01/29 14:29:34 by ljeribha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h" // Bresenham algorithm Implementation

void	render_map(t_mlx *mlx, int **grid, int rows, int cols)
{
	if (!mlx || !mlx->mlx_ptr || !mlx->win_ptr || !grid)
		return;
	int	y;
	int	x;
	int	x0;
	int	y0;
	int	z0;
	int	x1;
	int	y1;
	int	z1;

	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			x0 = x * SCALE;
			y0 = y * SCALE;
			z0 = grid[y][x];
			
			isometric(&x0, &y0, z0);
			if (x < cols - 1) //horizontal connection
			{
				x1 = (x + 1) * SCALE;
				y1 = y * SCALE;
				z1 = grid[y][x + 1];
				isometric(&x1, &y1, z1);
				draw_line(mlx, x0 + WIDTH / 2, y0 + HEIGHT / 2, x1 + WIDTH / 2, y1 + HEIGHT / 2, 0xFFFFFF);
			}
			ft_printf("Rendering point x: x=%d, y=%d, z=%d", x0, y0, z0);
			if (y < rows - 1) //vertical connection
			{
				x1 = x * SCALE;
				y1 = (y + 1) * SCALE;
				z1 = grid[y + 1][x];
				isometric(&x1, &y1, z1);
				draw_line(mlx, x0 + WIDTH / 2, y0 + HEIGHT / 2, x1 + WIDTH / 2, y1 + HEIGHT / 2, 0xFFFFFF);
			}
			ft_printf("Rendering point y: x=%d, y=%d, z=%d", x0, y0, z0);
			x++;
		}
		y++;
	}
}
