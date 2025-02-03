/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:12:18 by ljeribha          #+#    #+#             */
/*   Updated: 2025/01/13 14:27:12 by ljeribha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	isometric(int *x, int *y, int z)
{
	int	prev_x = *x;
	int	prev_y = *y;

	*x = (prev_x - prev_y) * cos(ANGLE);
	*y = (prev_x + prev_y) * sin(ANGLE) - z;
}

void	draw_line(t_mlx *mlx, int x0, int y0, int x1, int y1, int color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = abs(x1- x0);
	dy = abs(y1 - y0);
	sx = (x0 < x1) ? 1 : -1;
	sy = (y0 < y1) ? 1 : -1;
	err = dx - dy;

	while (1)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break;
		e2 = err * 2;
		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void	render_map(t_mlx *mlx, int **grid, int rows, int cols)
{
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
			if (x < cols - 1)
			{
				x1 = (x + 1) * SCALE;
				y1 = y * SCALE;
				z1 = grid[y][x + 1];
				isometric(&x1, &y1, z1);
				draw_line(mlx, x0 + WIDTH / 2, y0 + HEIGHT / 2, x1 + WIDTH / 2, y1 + HEIGHT / 2, 0xFFFFFF);
			}
			if (y < rows - 1)
			{
				x1 = x * SCALE;
				y1 = (y + 1) * SCALE;
				z1 = grid[y + 1][x];
				isometric(&x1, &y1, z1);
				draw_line(mlx, x0 + WIDTH / 2, y0 + HEIGHT / 2, x1 + WIDTH / 2, y1 + HEIGHT / 2, 0xFFFFFF);
			}
			x++;
		}
		y++;
	}
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

int	close_window(void *param)
{
	(void)param;
	printf("Window closed!\n");
	exit(0);
}

int	main(void)
{
	t_mlx	mlx;
	mlx.mlx_ptr =  mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, "FDF Isometric Projection!");

	mlx_hook(mlx.win_ptr, 17, 0, close_window, NULL);
	mlx_key_hook(mlx.win_ptr, key_press, NULL);


	int	rows = 11;
	int	cols = 19;
	int	**grid = malloc(sizeof(int *) * rows);
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		grid[i] = malloc(sizeof(int) * cols);
		j = 0;
		while (j < cols)
		{
			grid[i][j] = i + j; //example heights
			j++;
		}
		i++;
	}

	render_map(&mlx, grid, rows, cols);
	mlx_loop(mlx.mlx_ptr);

	if (grid)
	{
		i = 0;
		while (i < rows)
		{
			if (grid[i])
				free(grid[i]);
			i++;
		}
		free(grid);
	}
	return (0);
}
