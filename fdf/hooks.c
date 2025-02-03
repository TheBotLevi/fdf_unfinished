/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:30:16 by ljeribha          #+#    #+#             */
/*   Updated: 2025/01/31 16:18:48 by ljeribha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clean_up(t_mlx *mlx, int **grid, int rows)
{
	if (grid)
		free_grid(grid, rows);
	if (mlx->mlx_ptr)
	{
		if (mlx->win_ptr)
		{
			mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
			mlx->win_ptr = NULL;
		}
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		mlx->mlx_ptr = NULL;
	}
}

int	key_press(int keycode, t_mlx *mlx)
{
	printf("Key pressed: %d\n", keycode);
	if (keycode == 65307)
	{
		clean_up(mlx, NULL, 0);
		printf("Exiting program!\n");
		close_window(mlx);
	}
	return (0);
}

int	close_window(t_mlx *mlx)
{
	clean_up(mlx, NULL, 0);
	printf("Window closed!\n");
	exit(0);
	return (0);
}